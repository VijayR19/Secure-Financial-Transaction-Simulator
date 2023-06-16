#include "Transaction.hpp"
#include <string>

// constructor
Transaction::Transaction(const std::string& senderAccountNumber, const std::string& recipientAccountNumber,double amount, const std::string& type)
            :senderAccountNumber(senderAccountNumber),recipientAccountNumber(recipientAccountNumber),amount(amount),type(type) {}
            
//Getter for sender account Number
const std::string& Transaction::getSenderAccountNumber() const{
    return senderAccountNumber;
}

// Getter for recipient account number
const std::string& Transaction::getRecipientAccountNumber() const{
    return recipientAccountNumber;
}

//Getter for amount
double Transaction::getAmount() const{
    return amount;
}

//Getter for type
const std::string& Transaction::getType() const{
    return type;
}