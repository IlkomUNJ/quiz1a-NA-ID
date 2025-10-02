#pragma once
#include "buyer.h"
#include "item.h"
#include <string>
#include <vector>

class seller : public Buyer {

private:
    // Add seller-specific private members here
    int sellerId;
    std::string sellerName;
    string storeAddress;
    string storePhoneNumber;
    string storeEmail;
    
    bool idDisplayed(int itemId) const {
        // Example implementation, can be customized
        return itemId > 0; // Assuming valid IDs are positive integers
    }

    vector<Item> items; // Assuming seller has a collection of items

public:
    seller() = default;

    // Original constructor for backward compatibility
    seller(Buyer buyer, int sellerId, const std::string& sellerName)
        : Buyer(buyer.getId(), buyer.getName(), buyer.getAccount()), sellerId(sellerId), sellerName(sellerName), 
          storeAddress(""), storePhoneNumber(""), storeEmail("") {
            Buyer::setId(buyer.getId());
        }
    
    // Enhanced constructor with store contact information
    seller(Buyer buyer, int sellerId, const std::string& sellerName, const string& storeAddress, const string& storePhoneNumber, const string& storeEmail)
        : Buyer(buyer.getId(), buyer.getName(), buyer.getAccount()), sellerId(sellerId), sellerName(sellerName),
          storeAddress(storeAddress), storePhoneNumber(storePhoneNumber), storeEmail(storeEmail) {
            Buyer::setId(buyer.getId());
        }

    virtual ~seller() = default;
    
    // Getters for store contact information
    string getStoreAddress() const { return storeAddress; }
    string getStorePhoneNumber() const { return storePhoneNumber; }
    string getStoreEmail() const { return storeEmail; }
    
    // Setters for store contact information
    void setStoreAddress(const string& newStoreAddress) { storeAddress = newStoreAddress; }
    void setStorePhoneNumber(const string& newStorePhoneNumber) { storePhoneNumber = newStorePhoneNumber; }
    void setStoreEmail(const string& newStoreEmail) { storeEmail = newStoreEmail; }

    void addNewItem(int newId, const std::string& newName, int newQuantity, double newPrice) {
        Item newItem(newId, newName, newQuantity, newPrice);
        items.push_back(newItem);
    }

    void updateItem(int itemId, const std::string& newName, int newQuantity, double newPrice) {
        for (auto& item : items) {
            if (item.getId() == itemId) {
                item.alterItemById(itemId, newName, newQuantity, newPrice); // Assuming alterItemById is a method
            }
        }
    }

    void makeItemVisibleToCustomer(int itemId) {
        for (auto& item : items) {
            if (item.getId() == itemId) {
                item.setDisplay(true); // Assuming setDisplay is a method in Item class
                break;
            }
        }
    }

    // Add seller-specific members here
};