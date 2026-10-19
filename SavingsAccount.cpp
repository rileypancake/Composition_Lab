/**
* Name: Riley Pancake
 * Date: 10.19.2026
 * Assignment: Composition Lab
 * Purpose: Implements interest calculation and logs it via deposit.
 */

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string accountNumber,
                               std::string accountHolderName,
                               double balance,
                               double interestRate)
    : BankAccount(accountNumber, accountHolderName, balance),
      interestRate(interestRate >= 0 ? interestRate : 0) {}

void SavingsAccount::calculateInterest() {
    double interest = getBalance() * interestRate;
    deposit(interest); // Deposit logs "Deposit" into transactionHistory
}