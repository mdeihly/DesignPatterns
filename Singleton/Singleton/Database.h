#pragma once

#include <iostream>
#include <string>
#include <mutex>

class Database
{
public:
	static Database *getInstance();
	static Database* databaseInstance;
	void logMsg(const std::string &msg);

	// Singleton should not be cloneable
	Database(const Database&) = delete;
	// Singleton should not be assignable
	Database& operator=(const Database&) = delete;

private:
	Database();
	int counter = 0;
	static std::mutex mtx;

};

