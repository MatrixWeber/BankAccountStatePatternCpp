//
// Created by Alex on 26.04.2020.
//
#ifndef ACCOUNT_TEST1_EUTER_H
#define ACCOUNT_TEST1_EUTER_H

#include "Frozen.h"
#include "Active.h"
#include "NotVerified.h"
#include "Close.h"

class IAccountState;
class ICallbackable;

class Factory {
public:

    static IAccountState * createFrozen(ICallbackable& gui)
    {
        return new Frozen(gui);
    }

    static IAccountState * createActive(ICallbackable& gui)
    {
        return new Active(gui);
    }

    static IAccountState * createNotVerified()
    {
        return new NotVerified();
    }

    static IAccountState * createClose()
    {
        return new Close();
    }
};

#endif //ACCOUNT_TEST1_EUTER_H