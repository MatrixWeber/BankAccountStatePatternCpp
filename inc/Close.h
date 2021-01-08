//
// Created by Alex on 30.04.2020.
//

#ifndef ACCOUNT_TEST1_CLOSE_H
#define ACCOUNT_TEST1_CLOSE_H

#include <functional>
#include "IAccountState.h"
#include "Account.h"

class Close : public IAccountState
{
public:
    ~Close() override = default;

    void deposit(Account *account, std::function<float()> add) override {
        account->setState(Account::StateEnum::ST_CLOSE);
    }

    void withdraw(Account *account, std::function<float()> subtract) override {
        account->setState(Account::StateEnum::ST_CLOSE);
    }

    void freeze(Account *account) override {
        account->setState(Account::StateEnum::ST_CLOSE);
    }

    void close(Account *account) override {
        account->setState(Account::StateEnum::ST_CLOSE);
    }

    void holderVerified(Account *account) override {
        account->setState(Account::StateEnum::ST_CLOSE);
    }
};
#endif //ACCOUNT_TEST1_CLOSE_H
