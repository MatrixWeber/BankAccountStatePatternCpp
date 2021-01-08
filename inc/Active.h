#ifndef ACCOUNT_TEST1_ACTIVE_H
#define ACCOUNT_TEST1_ACTIVE_H
#include "IAccountState.h"

class Account;

class Active : public IAccountState
{
public:
	explicit Active(ICallbackable& callback) : gui(callback)
	{
	}
	~Active() override = default;

    void deposit(Account *account, std::function<float()> add) override
	{
        add();
        account->setState(Account::StateEnum::ST_ACTIVE);
	}

	void withdraw(Account *account, std::function<float()> subtract) override
	{
        subtract();
        account->setState(Account::StateEnum::ST_ACTIVE);
	}

	void freeze(Account *account) override
	{
        account->setState(Account::StateEnum::ST_FROZEN);
	}

    void close(Account *account) override {
        account->setState(Account::StateEnum::ST_CLOSE);
    }

    void holderVerified(Account *account) override {
        account->setState(Account::StateEnum::ST_ACTIVE);
    }

private:
	ICallbackable& gui;
};

#endif //ACCOUNT_TEST1_ACTIVE_H