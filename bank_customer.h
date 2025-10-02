#ifndef BANK_CUSTOMER_H
#define BANK_CUSTOMER_H

#include <string>

using namespace std;

class BankCustomer {
private:
    int id;
    string name;
    double balance;
    string address;
    string phoneNumber;
    string email;

public:
    // Original constructor for backward compatibility
    BankCustomer(int id, const string& name, double balance) : id(id), name(name), balance(balance), address(""), phoneNumber(""), email("") {
        this->id = id;
        this->name = name;
        this->balance = balance;
    }
    
    // Enhanced constructor with all fields
    BankCustomer(int id, const string& name, double balance, const string& address, const string& phoneNumber, const string& email) 
        : id(id), name(name), balance(balance), address(address), phoneNumber(phoneNumber), email(email) {
        this->id = id;
        this->name = name;
        this->balance = balance;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->email = email;
    }

    // Existing getters
    int getId() const;
    string getName() const;
    double getBalance() const;
    
    // New getters for additional fields
    string getAddress() const { return address; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }

    void printInfo() const;
    
    // Existing setters
    void setName(const string& name);
    void setBalance(double balance);
    
    // New setters for additional fields
    void setAddress(const string& newAddress) { address = newAddress; }
    void setPhoneNumber(const string& newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setEmail(const string& newEmail) { email = newEmail; }
    
    void addBalance(double amout);
    bool withdrawBalance(double amout);
};

#endif // BANK_CUSTOMER_H