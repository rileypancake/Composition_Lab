/**
* Name: Riley Pancake
 * Date: 10.19.2026
 * Assignment: Composition Lab
 * Purpose: Declares BankAccount base class managing dynamic name memory,
 *          balances, and a composed vector of Transaction objects.
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

class BankAccount {
private:
    std::string accountNumber;
    std::string* accountHolderName;
    double balance;
    std::vector<Transaction> transactionHistory; // Composition: has-a collection of Transactions

    std::string getCurrentTimestamp() const;

public:
    BankAccount();
    BankAccount(std::string accountNumber,
                std::string accountHolderName,
                double balance);

    // Rule of Three
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);
    virtual ~BankAccount();

    // Getters
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    // Core Operations
    void deposit(double amount);
    virtual bool withdraw(double amount);
    void printHistory() const;

    // Operators
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // Static Utilities
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
};

#endif // BANKACCOUNT_H