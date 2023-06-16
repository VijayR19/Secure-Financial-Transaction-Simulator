#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

// Transaction class definition
class Transaction
{
private:
    std::string senderAccountNumber; // sender's account Number
    std:: string recipientAccountNumber; // recipient's account Number
    double amount;             // the Transaction amount
    std::string type;          // the Transaction type(for example: "deposit","withdraw" and so on)
public:
    Transaction(const std::string& senderAccountNumber, const std::string& recipientAccountNumber,double amount, const std::string &type);

    // getter functions
    const std::string& getSenderAccountNumber() const;
    const std::string& getRecipientAccountNumber() const;
    double getAmount() const;
    const std::string &getType() const;
};

#endif