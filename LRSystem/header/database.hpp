#pragma once
#include <winsqlite/winsqlite3.h>
#include <stdexcept>
#include <string>

class DataBase
{
public:

	void CreateDataBase(std::string name);
	void OpenDataBase(std::string name);

	void CreateTable(std::string tableName, std::string values);
	void InsertToDataBase(std::string tableName, std::string values);
	void SelectFromDataBase();
private:
	sqlite3* db;
	char* errMsg;
	int rc;

	std::string dataBaseName;
};

