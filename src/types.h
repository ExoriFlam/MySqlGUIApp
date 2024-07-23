#ifndef TYPES_H
#define TYPES_H
#include <map>
#include <vector>
#include <string>

using Atributes = std::vector<std::string>;
using TableName = std::string;

using Tables = std::map<TableName, Atributes>;
using DbName = std::string;
using DbSchema = std::map<DbName, Tables>;

#endif