#include "DbHelper.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

DbHelper::DbHelper(std::string server, std::string user, std::string password, std::string database)
    : server{server}, user{user}, password{password}, database{database} {}

bool DbHelper::connect(){
    try
    {
        sql::Driver* driver = get_driver_instance();

        conn.reset(driver->connect(server, user, password));

        if (!conn->isValid())
        {
            #ifdef DEBUG
            std::cerr << "Connection failed" << std::endl;
            #endif

            return false;
        }

    }
    catch (sql::SQLException &e)
    {
        #ifdef DEBUG
        std::cerr << "SQLException: " << e.what() << std::endl;
        #endif
        return false;
    }
    return true;
}

bool DbHelper::create_db(std::string db_name){

    try
    {
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::string query = "CREATE DATABASE IF NOT EXISTS " + db_name;
        stmt->execute(query);
    }
    catch (sql::SQLException &e)
    {
    	#ifdef DEBUG
        std::cerr << "SQLException: " << e.what() << std::endl;
        #endif
        return false;
    }

    return true;
}

std::vector<std::string> DbHelper::get_db_names(){

    std::vector<std::string> db_names;
    std::vector<std::string> system_tables{
        "sys", "performance_schema",
        "mysql","information_schema"
    };
    auto is_system_db = [&system_tables](const std::string& db_name){
        return std::find(system_tables.begin(), system_tables.end(), db_name) != system_tables.end();
    };

   

    try
    {
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SHOW DATABASES"));
        while (res->next())
        {
            if(!is_system_db(res->getString(1)))
            {
                db_names.push_back(res->getString(1));
            }
            
        }
    }
    catch (sql::SQLException &e)
    {
    	#ifdef DEBUG
        std::cerr << "SQLException: " << e.what() << std::endl;
        #endif
    }

    return db_names;
}


std::vector<std::string> DbHelper::get_table_names(const std::string db_name)
{
    std::vector<std::string> tables;

    try
    {
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::string tables_query = "SHOW TABLES FROM " + db_name;
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(tables_query));

        while(res->next())
        {
            tables.push_back(res->getString(1));
        }
    }
    catch(sql::SQLException &e)
    {
        #ifdef DEBUG
        std::cerr << "SQLException: " << e.what() << std::endl;
        #endif
    }

    return tables;
}


DbSchema DbHelper::get_schema()
{

    DbSchema schema;

    try {
        std::vector<std::string> db_names = get_db_names();
        for (const auto& db_name : db_names) {
            conn->setSchema(db_name);
            std::unique_ptr<sql::Statement> stmt(conn->createStatement());

           
            std::unique_ptr<sql::ResultSet> tables_res(stmt->executeQuery("SHOW TABLES"));
            Tables tables;

            while (tables_res->next()) {
                std::string table_name = tables_res->getString(1);
                std::unique_ptr<sql::Statement> table_stmt(conn->createStatement());

                
                std::string columns_query = "SHOW COLUMNS FROM " + table_name;
                std::unique_ptr<sql::ResultSet> columns_res(table_stmt->executeQuery(columns_query));
                Atributes attributes;

                while (columns_res->next()) {
                    attributes.push_back(columns_res->getString("Field"));
                }

                tables[table_name] = attributes;
            }

            schema[db_name] = tables;
        }
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
    return schema;
}



bool DbHelper::drop_db(std::string db_name)
{
    try
    {
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::string query = "DROP DATABASE " + db_name;
        stmt->execute(query);
    }
    catch(sql::SQLException &e)
    {
        #ifdef DEBUG
        std::cerr << "SQLException: " << e.what() << std::endl;
        #endif
        return false;
    }

    return true;
}

bool DbHelper::execute_modification_query(const std::string& query)
{
    if(!conn)
    {
        std::cerr << "Connection is not established.\n";
        return false;
    }

    try
    {
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        stmt->execute(query);
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << "\n";
        return false;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
        return false;
    }

    return true;
}
