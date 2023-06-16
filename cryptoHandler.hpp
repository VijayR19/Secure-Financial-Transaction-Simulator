#ifndef CRYPTOHANDLER_H
#define CRYPTOHANDLER_H

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/hex.h>

// The Cryptohandler class provides a simple interface for encryptig and decrypting strings using AES encryption.
class CryptoHandler{
    private:
        // The key and initialization vector used by the AES algorithm.
        CryptoPP::byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH], iv[ CryptoPP::AES::BLOCKSIZE];
    
    public:
        // constructor that initializes a new instances of the CryptoHandler class.
        CryptoHandler();

        // Encrypts the specified plaintext string and returns the resulting ciphertext string.
        std::string encrypt(std::string plaintext);

        // Decrypts the specified ciphertext string and returns the resulting plaintext string.
        std::string decrypt(std::string ciphertext);
};

#endif