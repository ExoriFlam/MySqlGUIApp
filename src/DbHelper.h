#ifndef DBHELPER_H
#define DBHELPER_H

#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <memory>
#include <string>
#include <vector>
#include "types.h"
#include "EventSystem.h"
#include <functional>

class DbHelper{
public:
	

    DbHelper(std::string server, std::string user, std::string password, std::string database);

    bool connect();
    bool create_db(std::string db_name);
    bool drop_db(std::string db_name);
    
    bool execute_modification_query(const std::string& query);

    DbSchema get_schema();
    
    std::vector<std::string> get_db_names();
   	std::vector<std::string> get_table_names(const std::string db_name);

private:

	

    std::unique_ptr<sql::Connection> conn;
    std::string server;
    std::string user;
    std::string password;
    std::string database;

    
};

#endif