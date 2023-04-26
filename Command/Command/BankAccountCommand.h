#pragma once
#include "ICommand.h"
#include "BankAccount.h"
class BankAccountCommand :
    public ICommand
{
public:
    enum Action { DEPOSIT = 0, WITHDRAW } action;
    BankAccountCommand(BankAccount& account, const Action action, int amount);
    virtual void call() override;

private:
    BankAccount& account;
    int amount;
};

