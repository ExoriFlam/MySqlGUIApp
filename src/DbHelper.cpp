#include "DbHelper.h"
#include <vector>
#include <iostream>
#include <string>
DbHelper::DbHelper(std::string server, std::string user, std::string password, std::string database):
	server{server}, user{user}, password{password}, database{database} 
{
	conn = mysql_init(NULL);
}

bool DbHelper::connect()
{
	mysql_real_connect(
		conn, server.c_str(), user.c_str(),
		password.c_str(), database.c_str(),
		0, NULL, 0);

	if(conn == NULL)
	{
		std::cerr << "mysql_real_connect() failed" << std::endl;
		return false;
	}

	return true;

}

bool DbHelper::create_db(std::string db_name)
{

	std::string query = "CREATE DATABASE IF NOT EXISTS " + db_name + ";";
	std::cout << query << std::endl;
    if (mysql_query(conn, query.c_str()))
    {
    	
        std::cerr << "CREATE DATABASE failed. Error: " << mysql_error(conn) << std::endl;
        return false;
    }
    
    return true;
}

std::vector<std::string> DbHelper::get_db_names()
{
	
	std::vector<std::string> db_names;
	if (mysql_query(conn, "SHOW DATABASES")) {
       // throw std::runtime_error("Failed to execute SHOW DATABASES query");
    }
    
    MYSQL_RES *res = mysql_store_result(conn);
    if (res == NULL) {
        //throw std::runtime_error("Failed to store result set");
    }
    
    
    MYSQL_ROW row;

   	if(res != NULL)
   	{
   		while ((row = mysql_fetch_row(res)))
    	{
	    	if(row[0])
	    	{
	    		db_names.push_back(row[0]);
	    	}
        
    	}
   	}
    
    // std::cout << "5";
    mysql_free_result(res);
   
    return db_names;

}