#pragma once

#include "IAccountState.h"

class Account;

class Frozen : public IAccountState
{
public:
	explicit Frozen(ICallbackable& callback) : gui(callback)
	{
	}
	~Frozen() override = default;

    void deposit(Account *account, std::function<float()> add) override
	{
        add();
		gui.callback();
        account->setState(Account::StateEnum::ST_ACTIVE);
	}

	void withdraw(Account *account, std::function<float()> subtract) override
	{
        subtract();
		gui.callback();
        account->setState(Account::StateEnum::ST_ACTIVE);
	}

	void freeze(Account *account) override
	{
        account->setState(Account::StateEnum::ST_FROZEN);
	}
    void Frozen::close(Account *account) override {
        account->setState(Account::StateEnum::ST_CLOSE);
    }

    void Frozen::holderVerified(Account *account) override {
        account->setState(Account::StateEnum::ST_FROZEN);
    }

private:
	ICallbackable& gui;
};