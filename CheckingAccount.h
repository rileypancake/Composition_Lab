/**
* Name: Riley Pancake
 * Date: 10.19.2026
 * Assignment: Composition Lab
 * Purpose: Declares CheckingAccount derived from BankAccount.
 */

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    double transactionFee;

public:
    CheckingAccount(std::string accountNumber,
                    std::string accountHolderName,
                    double balance,
                    double transactionFee);

    bool withdraw(double amount) override;
};

#endif // CHECKINGACCOUNT_H