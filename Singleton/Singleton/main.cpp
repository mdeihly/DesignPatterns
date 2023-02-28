#include "Database.h"
#include <thread>

#include <iostream>

void firstThread()
{
	Database *db = Database::getInstance();
	db->logMsg("Message from User 1");
}

void secondThread()
{
	Database* db = Database::getInstance();
	db->logMsg("Message from User 2");
}

int main()
{
	std::thread t1(firstThread);
	std::thread t2(secondThread);
	t1.join();
	t2.join();

	return 0;
}