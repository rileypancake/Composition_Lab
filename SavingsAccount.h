/**
* Name: Riley Pancake
 * Date: 10.19.2026
 * Assignment: Composition Lab
 * Purpose: Declares SavingsAccount derived from BankAccount.
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(std::string accountNumber,
                   std::string accountHolderName,
                   double balance,
                   double interestRate);

    void calculateInterest();
};

#endif // SAVINGSACCOUNT_H