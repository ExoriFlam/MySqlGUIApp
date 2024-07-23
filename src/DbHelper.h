#ifndef DBHELPER
#define DBHELPER_H
#include <mysql/mysql.h>
#include <string>
#include <memory>
#include <vector>

class DbHelper{

public:
	DbHelper(std::string server, std::string user, std::string password, std::string database);

	bool connect();
	
	bool create_db(std::string db_name);

	std::vector<std::string> get_db_names();
	
private:

	MYSQL* conn;


	std::string server;
	std::string user;
	std::string password;
	std::string database;
};


#endif