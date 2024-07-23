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

class DbHelper {
public:
    DbHelper(std::string server, std::string user, std::string password, std::string database);

    bool connect();
    bool create_db(std::string db_name);

    
    DbSchema get_schema();

private:

	std::vector<std::string> get_db_names();

    std::unique_ptr<sql::Connection> conn;
    std::string server;
    std::string user;
    std::string password;
    std::string database;
};

#endif