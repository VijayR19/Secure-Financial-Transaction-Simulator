#include "server.hpp"
#include "Transaction.hpp"
#include <stdexcept>
#include <sstream>

// Adds a clients to bank
Bank::Bank(){
    // empty constructor
}
void Bank::addClient(const Client& client){
    clients.insert({client.getAccountNumber(),client});
}

// Gets a client from the bank
Client& Bank::getClient(const std::string& accountNumber){
    auto it = clients.find(accountNumber);
    if(it == clients.end()){
        throw std::invalid_argument("Client with account number" + accountNumber + " not found.");
    }
    return it->second;
}


// Processes a transaction
void Bank::processTransaction(const Transaction& transaction){
    //Retrive both clients involved in the transaction
    Client& sender = getClient(transaction.getSenderAccountNumber());
    Client& recipient = getClient(transaction.getRecipientAccountNumber());

    // convert transaction amount from string to double
    std::stringstream s(transaction.getAmount());
    double transactionAmount = 0;
    s>>transactionAmount;

    // check if sender has enough balance
    if(sender.getBalance() < transactionAmount){
        throw std::invalid_argument("Sender does not have enough balance for this transaction.");
    }

    // Transfer funds
    sender.decreaseBalance(transactionAmount);
    recipient.increaseBalance(transactionAmount);
}
