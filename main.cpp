#include "server.hpp"
#include "client.hpp"
#include "Transaction.hpp"
#include "cryptoHandler.hpp"
#include <cryptopp/hex.h>
#include <iostream>
#include <sstream> // for stringstream

int main() {
    // Create some clients
    Client alice("Alice", "123", 1000);
    Client lyon("Lyon", "456", 500);

    // Create a bank (Server) and add clients
    Bank bank;
    bank.addClient(alice);
    bank.addClient(lyon);

    // Print initial balances
    std::cout << "Alice's initial balance: " << bank.getClient("123").getBalance() << std::endl;
    std::cout << "Lyon's initial balance: " << bank.getClient("456").getBalance() << std::endl;

    // Alice sends 200 to Lyon
    double amount = 200;
    
    //Encrypt the transaction amount using AES
    CryptoHandler crypto;
    std::stringstream ss;
    ss<<amount;
    std::string amountStr = ss.str();
    std::string encryptedAmount = crypto.encrypt(amountStr);

    // process the transaction using the encrypted data
    Transaction transaction("123", "456",encryptedAmount,"transfer");
    bank.processTransaction(transaction);

    // Decrypt the transaction amount cak into a double
    std::string decryptedAmountStr = crypto.decrypt(transaction.getAmount());
    std::stringstream s(decryptedAmountStr);
    double decryptedAMount = 0;
    s>>decryptedAMount;

    // Print new balances
    std::cout << "Alice's new balance: " << bank.getClient("123").getBalance() << std::endl;
    std::cout << "Lyon's new balance: " << bank.getClient("456").getBalance() << std::endl;

    std::cout<<"Origional transaction amount: "<<amount<<std::endl;
    std::cout<<"Encrypted transaction amount: "<<encryptedAmount<<std::endl;
    std::cout<<"Decrypted transaction amount: "<<decryptedAMount<<std::endl;

    return 0;
}
