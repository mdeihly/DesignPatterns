#include "BankAccountCommand.h"
#include <vector>
#include <iostream>
int main()
{
	BankAccount ba;
	std::vector<BankAccountCommand> commands
	{
		BankAccountCommand {ba, BankAccountCommand::DEPOSIT, 100},
		BankAccountCommand {ba, BankAccountCommand::WITHDRAW, 200}
	};

	std::cout << ba << std::endl;
	for (auto& cmd : commands)
	{
		cmd.call();
	}
	std::cout << ba << std::endl;

	return 0;
}