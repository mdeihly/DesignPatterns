#include "BankAccountCommand.h"

BankAccountCommand::BankAccountCommand(BankAccount& account, const Action action, int amount):
	account(account), action(action), amount(amount)
{
}

void BankAccountCommand::call()
{
	switch (action)
	{
	case BankAccountCommand::DEPOSIT:
		account.deposit(amount);
		break;
	case BankAccountCommand::WITHDRAW:
		account.withdraw(amount);
		break;
	default:
		break;
	}
}
