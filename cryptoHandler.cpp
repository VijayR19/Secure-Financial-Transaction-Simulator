#include "cryptoHandler.hpp"
#include <cryptopp/osrng.h>

// constructor that generates a random key and initialization vector.
CryptoHandler::CryptoHandler(){
    CryptoPP::AutoSeededRandomPool prng;
    prng.GenerateBlock(key, sizeof(key));
    prng.GenerateBlock(iv, sizeof(iv));
}

// Encrypts the specified plaintext string and returns the resulting ciphertext string.
std::string CryptoHandler::encrypt(std::string plaintext) {
    std::string ciphertext;
    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption( aesEncryption, iv );
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink( ciphertext ) );
    stfEncryptor.Put( reinterpret_cast<const unsigned char*>( plaintext.c_str() ), plaintext.length() + 1 );
    stfEncryptor.MessageEnd();
    return ciphertext;
}

// Decrypts the specified ciphertext string and returns the resulting plaintext string.
std::string CryptoHandler::decrypt(std::string ciphertext) {
    std::string decryptedtext;
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption( aesDecryption, iv );
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink( decryptedtext ) );
    stfDecryptor.Put( reinterpret_cast<const unsigned char*>( ciphertext.c_str() ), ciphertext.size() );
    stfDecryptor.MessageEnd();
    return decryptedtext;
}
