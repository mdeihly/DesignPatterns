#include "Database.h"

Database *Database::databaseInstance = nullptr;
std::mutex Database::mtx;

Database::Database()
{
	counter++;

	std::cout << "New instance created.." << std::endl;
}

Database *Database::getInstance()
{
	// double-checked locking
	if (nullptr == databaseInstance)
	{
		mtx.lock();
		if (nullptr == databaseInstance)
		{
			databaseInstance = new Database();
		}
		mtx.unlock();
	}

	return databaseInstance;
}

void Database::logMsg(const std::string& msg)
{
	std::cout << msg << std::endl;
}
