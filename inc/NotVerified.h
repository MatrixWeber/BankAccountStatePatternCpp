//
// Created by Alex on 30.04.2020.
//

#ifndef ACCOUNT_TEST1_NOTVERIFIED_H
#define ACCOUNT_TEST1_NOTVERIFIED_H

#include "IAccountState.h"
#include "Account.h"

class Account;

class NotVerified : public IAccountState
{
public:
    ~NotVerified() override = default;

    void deposit(Account *account, std::function<float()> add) override {
        add();
        account->setState(Account::StateEnum::ST_VERIFIED);
    }

    void withdraw(Account *account, std::function<float()> subtract) override  {
        account->setState(Account::StateEnum::ST_VERIFIED);
    }

    void freeze(Account *account) override  {
        account->setState(Account::StateEnum::ST_VERIFIED);
    }

    void close(Account *account) override  {
        account->setState(Account::StateEnum::ST_CLOSE);
    }

    void holderVerified(Account *account) override  {
        account->setState(Account::StateEnum::ST_ACTIVE);
    }
};

#endif //ACCOUNT_TEST1_NOTVERIFIED_H
