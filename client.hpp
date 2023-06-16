#ifndef CLIENT_H
#define CLIENT_H

#include "Transaction.hpp"
#include <string>
#include <vector>

// Client class definition

class Client
{
private:
    std::string name;                      // the client's name
    std::string accountNumber;             // the client's account number
    std::vector<Transaction> transactions; // the client's performed transactions
    double balance;                        // the client's balance

public:
    Client(const std::string &name, const std::string &accountNumber, double initialBalance);

    // Method to perform a transaction
    void performTransaction(const Transaction &transaction);

    // method to increaseBalance
    void increaseBalance(double amount);

    // method to decreaseBalance
    void decreaseBalance(double amount);

    // Getter functions
    const std::string &getName() const;
    const std::string &getAccountNumber() const;
    const std::vector<Transaction> &getTransactions() const;
    double getBalance() const;
};

#endif