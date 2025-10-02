#ifndef BUYER_H
#define BUYER_H

#include <cstddef>
#include <string>
#include "bank_customer.h"

using namespace std;

class Buyer {
private:
    int id;
    string name;
    BankCustomer &account; // Association with BankCustomer
    string address;
    string phoneNumber;
    string email;

public:
    // Original constructor for backward compatibility
    Buyer(int id, const string& name, BankCustomer &account0)
        : id(id), name(name), account(account0), address(""), phoneNumber(""), email("") {}
    
    // Enhanced constructor with all fields
    Buyer(int id, const string& name, BankCustomer &account0, const string& address, const string& phoneNumber, const string& email)
        : id(id), name(name), account(account0), address(address), phoneNumber(phoneNumber), email(email) {}

    // Existing getters
    int getId() const { return id; }
    string getName() const { return name; }
    BankCustomer& getAccount() { return account; }
    const BankCustomer& getAccount() const { return account; }
    
    // New getters for additional fields
    string getAddress() const { return address; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }

    // Existing setters
    void setId(int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
    
    // New setters for additional fields
    void setAddress(const string& newAddress) { address = newAddress; }
    void setPhoneNumber(const string& newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setEmail(const string& newEmail) { email = newEmail; }
};

#endif // BUYER_H