#include "server.hpp"
#include "client.hpp"
#include "Transaction.hpp"
#include "cryptoHandler.hpp"
#include <cryptopp/hex.h>
#include <iostream>

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
    Transaction transaction("123", "456", 200, "transfer");
    bank.processTransaction(transaction);

    // Print new balances
    std::cout << "Alice's new balance: " << bank.getClient("123").getBalance() << std::endl;
    std::cout << "Lyon's new balance: " << bank.getClient("456").getBalance() << std::endl;

    // Encrypt and decrypt a text message using AES
    CryptoHandler crypto;
    std::string plainText = "Hello World!";
    std::string cipherText = crypto.encrypt(plainText);
    std::string decryptedText = crypto.decrypt(cipherText);

    std::cout << "Plain Text: " << plainText << std::endl;
    std::cout << "Encrypted Text: " << cipherText << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
