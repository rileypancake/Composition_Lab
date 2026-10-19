/**
 * Name: Riley Pancake
 * Date: 10.19.2026
 * Assignment: Composition Lab
 * Purpose: Implements BankAccount methods, logging every deposit and withdrawal.
 */

#include "BankAccount.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string BankAccount::getCurrentTimestamp() const {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = new std::string("");
    balance = 0.0;
}

BankAccount::BankAccount(std::string accountNumber,
                         std::string accountHolderName,
                         double balance) {
    this->accountNumber = accountNumber;
    this->accountHolderName = new std::string(accountHolderName);
    this->balance = balance;

    if (balance > 0.0) {
        transactionHistory.emplace_back("Initial Deposit", balance, getCurrentTimestamp());
    }
}

BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolderName = new std::string(*other.accountHolderName);
    balance = other.balance;
    transactionHistory = other.transactionHistory;
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        delete accountHolderName;
        accountHolderName = new std::string(*other.accountHolderName);
        balance = other.balance;
        transactionHistory = other.transactionHistory;
    }
    return *this;
}

BankAccount::~BankAccount() {
    delete accountHolderName;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getAccountHolderName() const {
    return *accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactionHistory.emplace_back("Deposit", amount, getCurrentTimestamp());
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }
    balance -= amount;
    transactionHistory.emplace_back("Withdrawal", amount, getCurrentTimestamp());
    return true;
}

void BankAccount::printHistory() const {
    std::cout << "\n--- Transaction History for " << *accountHolderName
              << " (" << accountNumber << ") ---\n";
    if (transactionHistory.empty()) {
        std::cout << "No transactions on file.\n";
    } else {
        for (const auto& tx : transactionHistory) {
            std::cout << "[" << tx.timestamp << "] "
                      << std::left << std::setw(17) << tx.type
                      << ": $" << std::fixed << std::setprecision(2) << tx.amount << "\n";
        }
    }
    std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
}

BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        deposit(amount);
    }
    return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && amount <= balance) {
        withdraw(amount);
    }
    return *this;
}

bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}

void BankAccount::printAccount(const BankAccount& account) {
    std::cout << "\nAccount Number: " << account.getAccountNumber() << "\n"
              << "Account Holder: " << account.getAccountHolderName() << "\n"
              << "Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << "\n";
}

BankAccount BankAccount::createAccountFromInput() {
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    std::cout << "Enter account holder name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, accountHolderName);

    while (accountHolderName.empty()) {
        std::cout << "Account holder name cannot be empty.\nEnter account holder name: ";
        std::getline(std::cin, accountHolderName);
    }

    std::cout << "Enter starting balance: ";
    while (!(std::cin >> balance) || balance < 0) {
        std::cout << "Invalid balance. Please enter a non-negative number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return BankAccount(accountNumber, accountHolderName, balance);
}