#ifndef TYPES_H
#define TYPES_H
#include <unordered_map>
#include <vector>
#include <string>

using Atributes = std::vector<std::string>;
using TableName = std::string;

using Tables = std::unordered_map<TableName, Atributes>;
using DbName = std::string;
using DbSchema = std::unordered_map<DbName, Tables>;// vector

#endif