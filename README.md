# Secure Financial Transaction Simulator

## Overview
This repository contains a simulation of secure financial transactions. The simulator includes classes representing Clients and a Bank (or Server), where clients perform transactions that are processed by the Bank. To ensure the security of the data, the project also uses the AES encryption method from the CryptoPP library.

## Description
The main components of the project are:
1. `Client`: This class represents a bank client with properties such as name, account number, transaction list, and balance. It includes methods for performing transactions, increasing/decreasing balance, and various getters.

2. `Bank (Server)`: This class simulates a bank or server which holds a map of clients. The class can add a client, get a client by account number, and process transactions.

3. `Transaction`: This class represents a single transaction with properties such as sender account number, recipient account number, and amount.

4. `CryptoHandler`: This class uses the Crypto++ library to encrypt and decrypt data with AES encryption.

## Compilation and Usage
To compile the project manually:
```bash
g++ -c Transaction.cpp -o Transaction.o
g++ -c client.cpp -o client.o
g++ -c server.cpp -o server.o
g++ -c cryptoHandler.cpp -o cryptoHandler.o -lcryptopp
g++ -o main main.cpp Transaction.o client.o server.o cryptoHandler.o -lcryptopp

## To run the project
./main

## Dependencies

This project requires the Crypto++ library. Install it on Ubuntu with:
```bash
sudo apt-get install libcrypto++-dev libcrypto++-doc libcrypto++-utils
Fedora
sudo dnf install cryptopp cryptopp-devel

# Future Improvements
1. Database Integration: Persisting data between runs would significantly improve the application's usability and aligns well with the project's aim to simulate real-world banking systems.

2. Authentication and Authorization: Implementing these features would greatly improve the security of the system, which is a crucial aspect of any banking or financial transaction system.

3. Concurrency and Multithreading: Adding support for these would improve the efficiency and performance of the system, especially as the number of clients and transactions grows.

4. Error and Exception Handling: Robust error and exception handling can make the application more stable and easier to debug, which would be particularly important in a real-world application handling   financial transactions.

5. Unit Testing 
6. Develope a mobile app

# Author
Sulav Gautam
linkedIn: https://www.linkedin.com/in/sulav-gautam-652ab6198
