#ifndef SERVER_H
#define SERVER_H

#include "client.hpp"
#include <map>
# include <sstream> // for stringstream

// Bank/server class definition
class Bank
{
private:
    std::map<std::string, Client> clients; // map of clients, with account number as key

public:
    Bank();
    // method to add client
    void addClient(const Client &client);

    // Method to get a client by account number
    Client& getClient(const std::string &accountNumber);

    // Method to process a transaction
    void processTransaction(const Transaction &transaction);
    
};

#endif