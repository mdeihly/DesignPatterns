#include "BankAccount.h"
#include <iostream>

void BankAccount::deposit(int amount)
{
	this->balance += amount;
	std::cout << "deposited " << amount << 
		", balance is now " << balance << std::endl;
}

void BankAccount::withdraw(int amount)
{
	if (balance - amount >= overdraftLimit)
	{
		balance -= amount;
		std::cout << "withdrew " << amount <<
			", balance is now " << balance << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const BankAccount& account)
{
	os << "balance: " << account.balance;
	return os;
}
