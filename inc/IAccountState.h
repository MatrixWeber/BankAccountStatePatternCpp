//
// Created by Alex on 29.04.2020.
//

#pragma once

class Account;

class IAccountState
{
public:
    virtual	~IAccountState() = default;
    virtual void deposit(Account *account, std::function<float()> add) = 0;
    virtual void withdraw(Account *account, std::function<float()> subtract) = 0;
    virtual void freeze(Account *account) = 0;
    virtual void close(Account *account) = 0;
    virtual void holderVerified(Account *account) = 0;
};
