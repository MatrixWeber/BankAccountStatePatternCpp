//
// Created by Alex on 30.04.2020.
//

#include <functional>
#include "Account.h"
#include "Factory.h"

void Account::setState(StateEnum state)
{
    delete m_pState;

    if(state == StateEnum::ST_ACTIVE)
    {
        m_pState = Factory::createActive(callback);
    }
    else if(state == StateEnum::ST_FROZEN)
    {
        m_pState = Factory::createFrozen(callback);
    }
    else if(state == StateEnum::ST_VERIFIED)
    {
        m_pState = Factory::createNotVerified();
    }
    else if(state == StateEnum::ST_CLOSE)
    {
        m_pState = Factory::createClose();
    }
}

void Account::close()
{
    m_pState->close(this);
}

void Account::holderVerified()
{
    m_pState->holderVerified(this);
}

void Account::freeze()
{
    m_pState->freeze(this);
}

void Account::withdraw(float amount)
{
    m_pState->withdraw(this,  [&](){return balance -= amount;});
}

void Account::deposit(float amount)
{
    m_pState->deposit(this, [&](){return balance += amount;});
}