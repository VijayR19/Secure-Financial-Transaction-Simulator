#include "client.hpp"
#include <stdexcept>

// constructor
Client::Client(const std::string &name, const std::string &accountNumber,double initialBalance)
    : name(name), accountNumber(accountNumber),balance(initialBalance) {}

// perform transaction
void Client::performTransaction(const Transaction &transaction)
{
    // Here we would usually validate the transaction details and the client's ability to perform the transaction.
    // For simplicity, we'll assume that all transactions are valid and can be performed by the client.
    transactions.push_back(transaction);
}

// Increase Balance
void Client::increaseBalance(double amount){
    balance += amount;
}

// decrease Balance
void Client::decreaseBalance(double amount){
    if(amount > balance){
        throw std::invalid_argument("Amount to decrease is greater than current balance.");
    }
    balance -= amount;
}

// Getter for client name
const std::string &Client::getName() const
{
    return name;
}

// Getter for account number
const std::string &Client::getAccountNumber() const
{
    return accountNumber;
}

// Getter for transactions
const std::vector<Transaction> &Client::getTransactions() const
{
    return transactions;
}

// Getter for balance
double Client::getBalance() const{
    return balance;
}

