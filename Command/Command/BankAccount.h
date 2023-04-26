#pragma once
#include <ostream>
class BankAccount
{
public:
	void deposit(int amount);
	void withdraw(int amount);
	friend std::ostream& operator<<(std::ostream& os, const BankAccount& account);
private:
	int balance{ 0 };
	int overdraftLimit{ -500 };
};



