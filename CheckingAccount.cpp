/**
* Name: Riley Pancake
 * Date: 10.19.2026
 * Assignment: Composition Lab
 * Purpose: Implements polymorphic withdrawal including the fee deduction.
 */

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string accountNumber,
                                 std::string accountHolderName,
                                 double balance,
                                 double transactionFee)
    : BankAccount(accountNumber, accountHolderName, balance),
      transactionFee(transactionFee >= 0 ? transactionFee : 0) {}

bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0) {
        return false;
    }
    // Base withdraw automatically updates balance and logs the full deduction
    return BankAccount::withdraw(amount + transactionFee);
}