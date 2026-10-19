/**
* Name: Riley Pancake
 * Date: 10.19.2026
 * Assignment: Composition Lab
 * Purpose: Defines the Transaction struct for recording account operations.
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <utility>

struct Transaction {
    std::string type;
    double amount;
    std::string timestamp;

    Transaction(std::string t, double a, std::string ts)
        : type(std::move(t)), amount(a), timestamp(std::move(ts)) {}
};

#endif // TRANSACTION_H