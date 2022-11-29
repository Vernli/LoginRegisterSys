#include "../header/database.hpp"

void DataBase::CreateDataBase(std::string name) {
	sqlite3_open(name.c_str(), &db);
}

void DataBase::OpenDataBase(std::string name) {
	dataBaseName = name;
	sqlite3_open(dataBaseName.c_str(), &db);
}

void DataBase::CreateTable(std::string tableName, std::string values) {	// Values in SQL (first TYPE, second TYPE, ...) 
	rc = sqlite3_exec(db, ("CREATE TABLE IF NOT EXISTS " + tableName + values).c_str(), NULL, NULL, &errMsg);
	if (rc != SQLITE_OK) {
		throw std::logic_error("TABLE EXISTS OR QUERY IS INVALID!");
	}
}

void DataBase::InsertToDataBase(std::string tableName, std::string values) {		// FROM SET TO VERIFY VECTOR?
	rc = sqlite3_exec(db, ("INSERT INTO " + tableName + " VALUES (" + values + ")").c_str(), NULL, NULL, &errMsg);
	if (rc != SQLITE_OK) {
		throw std::logic_error("ERROR WHEN INSERTING OR QUERY IS INVALID");
	}

}