#pragma once
#include "ICallbackable.h"

class IAccountState;

class Account
{
public:
        enum class StateEnum
        {
            ST_ACTIVE,
            ST_FROZEN,
            ST_CLOSE,
            ST_VERIFIED,
        };
		Account(ICallbackable& callback, IAccountState *state) : callback(callback), m_pState(state)
		{
		}

        Account::~Account() {
            delete m_pState;
        }
		void deposit(float amount);

		void withdraw(float amount);
		void freeze();

		float get() const
		{
			return balance;
		}
        void holderVerified();

        void close();
        void setState(StateEnum state);

private:
	float balance{};
    ICallbackable &callback;
    IAccountState* m_pState{};
};

