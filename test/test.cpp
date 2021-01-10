#include "gtest/gtest.h"
#include "Account.h"
#include "Bank.h"
#include "Factory.h"

TEST(TestAccount, TestDepositMoneyOnActiveAccount) {
    Bank bank;
    auto active = Factory::createActive(bank);
    Account account(bank, active);
    const float amount = 25;
    account.deposit(amount);
    EXPECT_EQ(account.get(), amount);
    account.deposit(amount);
    EXPECT_FALSE(bank.wasCallbackInvoked());
    EXPECT_EQ(account.get(), amount * 2);
    account.setState(Account::StateEnum::ST_CLOSE);
    account.deposit(amount);
    EXPECT_EQ(account.get(), amount * 2);
    EXPECT_FALSE(bank.wasCallbackInvoked());
}

TEST(TestAccount, TestWithdrawMoneyNotVerified) {
    Bank bank;
    auto active = Factory::createNotVerified();
    Account account(bank, active);
    const float amount = 25;
    account.deposit(amount);
    account.withdraw(amount);
    EXPECT_EQ(account.get(), amount);
    EXPECT_FALSE(bank.wasCallbackInvoked());
}



TEST(TestAccount, TestWithdrawMoney) {
    Bank bank;
    auto active = Factory::createActive(bank);
    Account account(bank, active);
    const float amount = 25;
    account.deposit(amount);
    account.withdraw(amount);
    EXPECT_EQ(account.get(), 0);
    account.deposit(amount);
    account.setState(Account::StateEnum::ST_CLOSE);
    account.withdraw(amount);
    EXPECT_EQ(account.get(), amount);
    EXPECT_FALSE(bank.wasCallbackInvoked());
}

TEST(TestAccount, TestGivenFrosenAccountUnfreezeAccountOnDeposit) {
    Bank bank;
    auto frozen = Factory::createFrozen(bank);
    Account account(bank, frozen);
    const float amount = 25;
    account.deposit(amount);
    EXPECT_TRUE(bank.wasCallbackInvoked());
    EXPECT_EQ(account.get(), amount);
    account.deposit(amount);
    EXPECT_FALSE(bank.wasCallbackInvoked());

}

TEST(TestAccount, TestGivenFrosenAccountStaysFrozenOnWithdraw) {
    Bank bank;
    auto frozen = Factory::createFrozen(bank);
    Account account(bank, frozen);
    const float amount = 25;
    account.withdraw(amount);
    EXPECT_TRUE(bank.wasCallbackInvoked());
    EXPECT_EQ(account.get(), 0);
    // verify that the account not changed to active state
    // because a callback function will be invoked only on frozen account
    account.withdraw(amount);
    EXPECT_TRUE(bank.wasCallbackInvoked());
}