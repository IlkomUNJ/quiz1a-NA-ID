#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "bank_customer.h"
#include "buyer.h"
#include "seller.h"

enum PrimaryPrompt{LOGIN, REGISTER, EXIT, ADMIN_LOGIN};
enum RegisterPrompt{CREATE_BUYER, CREATE_SELLER, BACK};
enum AdminPrompt{VIEW_ALL_BUYERS, VIEW_ALL_SELLERS, VIEW_ALL_BUYERS_DETAILED, VIEW_ALL_SELLERS_DETAILED, SEARCH, CREATE_NEW_ACCOUNT, REMOVE_ACCOUNT, BACK_TO_MAIN};
enum CreateAccountPrompt{CREATE_BUYER_ACCOUNT, CREATE_SELLER_ACCOUNT, CREATE_BANK_ACCOUNT, BACK_TO_ADMIN};
using namespace std;

int main() {
    //create a loop prompt 
    PrimaryPrompt prompt = LOGIN;
    RegisterPrompt regPrompt = CREATE_BUYER;
    const string ADMIN_USERNAME = "root";
    const string ADMIN_PASSWORD = "toor";
    string username, password;

    // Storage containers for system data
    vector<BankCustomer> bankCustomers;
    vector<Buyer> buyers;
    vector<seller> sellers;
    
    // Simple tracking for deleted accounts (using IDs)
    vector<int> deletedBuyerIds;
    vector<int> deletedSellerIds;
    vector<int> deletedBankIds;
    
    // Sample data for testing
    // Create some initial bank customers with complete information
    BankCustomer customer1(1, "Alice Johnson", 1500.0, "123 Main St, Springfield", "555-0101", "alice@email.com");
    BankCustomer customer2(2, "Bob Smith", 2000.0, "456 Oak Ave, Springfield", "555-0102", "bob@email.com");
    BankCustomer customer3(3, "Carol Davis", 1200.0, "789 Pine Rd, Springfield", "555-0103", "carol@email.com");
    bankCustomers.push_back(customer1);
    bankCustomers.push_back(customer2);
    bankCustomers.push_back(customer3);
    
    // Create some initial buyers with complete information
    Buyer buyer1(1, "Alice Johnson", bankCustomers[0], "123 Main St, Springfield", "555-0101", "alice@email.com");
    Buyer buyer2(2, "Bob Smith", bankCustomers[1], "456 Oak Ave, Springfield", "555-0102", "bob@email.com");
    buyers.push_back(buyer1);
    buyers.push_back(buyer2);
    
    // Create some initial sellers with store information
    seller seller1(buyer1, 101, "Alice's Store", "123 Main St Store, Springfield", "555-0201", "store.alice@email.com");
    seller seller2(Buyer(3, "Carol Davis", bankCustomers[2], "789 Pine Rd, Springfield", "555-0103", "carol@email.com"), 102, "Carol's Market", "789 Pine Market, Springfield", "555-0203", "market.carol@email.com");
    sellers.push_back(seller1);
    sellers.push_back(seller2);

    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Admin Login" << endl;
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        prompt = static_cast<PrimaryPrompt>(choice - 1);
        switch (prompt) {
            case LOGIN:
                cout << "Login selected." << endl;
                /* if Login is selected, based on authority then provide options:
                assume user is logged in as Buyer for now
                1. Chek Account Status (will display if user is Buyer or Seller or both and linked banking account status)
                Will display Buyer, Seller and Banking Account details
                2. Upgrade Account to Seller
                Will prompt user to enter Seller details and create a Seller account linked to Buyer account
                Will reject if a user dont have a banking account linked
                3. Create Banking Account (if not already linked), will be replaced with banking functions
                Must provides: initial deposit amount, Address, Phone number, Email
                Banking functions will provides: Balance checking, Transaction History, Deposit, Withdraw
                4. Browse Store Functionality
                Will display all stores initially
                Need to select a store to browse each store inventory
                Will display all items in the store inventory
                After selecting an item, will display item details and option to add to cart
                After adding to cart, will notify user item is added to cart
                5. Order Functionality
                Will display all items in cart
                Will provide option to remove item from cart
                Will provide option to checkout
                After checkout invoide will be generated (will go to payment functionality)
                6. Payment Functionality
                Will display all listed invoices
                Pick an invoice to pay
                Will display invoice details and total amount
                Will provide option to pay invoice
                Payment is done through confirmation dialogue
                In confirmation dialogue, will display account balance as precursor
                User will need to manually enter invoice id to pay
                After paying balance will be redacted from buyer and added to the responding seller account
                After payment, order status will be changed to paid
                7. Logout (return to main menu)
                Display confirmation dialogue
                If confirmed, return to main menu
                If not, return to Buyer menu
                8. Delete Account (remove both Buyer and Seller account and relevant banking account)
                Display confirmation dialogue
                If confirmed, delete account and return to main menu
                If not, return to Buyer menu

                assume user is logged in as Seller for now
                9. Check Inventory
                10. Add Item to Inventory
                11. Remove Item from Inventory
                12. View Orders (will display all orders placed to this seller
                Only orders with paid status will be listed
                Order details will listing items, quantity, total amount, buyer details, order status (paid, cancelled, completed)
                extra functions
                9. Exit to main Menu
                10. Exit Program
                **/
                break;
            case REGISTER:
                regPrompt = CREATE_BUYER; // reset regPrompt to CREATE_BUYER when entering register menu
                while (regPrompt != BACK){
                    cout << "Register selected. " << endl;
                    cout << "Select an option: " << endl;
                    cout << "1. Create Buyer Account" << endl;
                    cout << "2. Create Seller Account" << endl;
                    cout << "3. Back" << endl;
                    int regChoice;
                    cin >> regChoice;
                    regPrompt = static_cast<RegisterPrompt>(regChoice - 1);
                    switch (regPrompt) {
                        case CREATE_BUYER:
                            cout << "Create Buyer Account selected." << endl;
                            break;
                        case CREATE_SELLER:
                            cout << "Create Seller Account selected." << endl;
                            break;
                        case BACK:
                            cout << "Back selected." << endl;
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }
                /* if register is selected then went throuhh registration process:
                1. Create a new Buyer Account
                Must provides: Name, Home Address, Phone number, Email
                2. Option to create a Seller Account (will be linked to Buyer account)
                Must Provides 1: Home Address, Phone number, Email
                Must provides 2: Store Name, Store Address, Store Phone number, Store Email
                Must provides 3: initial deposit amount
                After finished immediately logged in as Buyer/Seller
                */
                break;
            case EXIT:
                cout << "Exiting." << endl;
                break;
            case ADMIN_LOGIN:
                /* Prompt for username & password then check the entries with our hard coded features */
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
                    cout << "Admin login successful." << endl;
                    // Admin sub-menu
                    AdminPrompt adminPrompt = VIEW_ALL_BUYERS;
                    while (adminPrompt != BACK_TO_MAIN) {
                        cout << "\nAdmin Menu:\n";
                        cout << "1. View All Buyers\n";
                        cout << "2. View All Sellers\n";
                        cout << "3. View All Buyers (Detailed)\n";
                        cout << "4. View All Sellers (Detailed)\n";
                        cout << "5. Search (Name / Account ID / Address / Phone Number)\n";
                        cout << "6. Create New Account\n";
                        cout << "7. Remove Buyer/Seller by ID\n";
                        cout << "8. Back to Main Menu\n";
                        cout << "Select an option: ";

                        int adminChoice;
                        if (!(cin >> adminChoice)) {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            cout << "Invalid input.\n";
                            continue;
                        }
                        adminPrompt = static_cast<AdminPrompt>(adminChoice - 1);

                        switch (adminPrompt) {
                            case VIEW_ALL_BUYERS: {
                                cout << "\n=== All Buyers (Summary) ===\n";
                                bool foundActiveBuyers = false;
                                cout << "ID\tName\t\tBalance\n";
                                cout << "--------------------------------\n";
                                for (const auto& buyer : buyers) {
                                    // Check if buyer is not deleted
                                    bool isDeleted = false;
                                    for (int deletedId : deletedBuyerIds) {
                                        if (buyer.getId() == deletedId) {
                                            isDeleted = true;
                                            break;
                                        }
                                    }
                                    if (!isDeleted) {
                                        cout << buyer.getId() << "\t" 
                                             << buyer.getName() << "\t\t$" 
                                             << buyer.getAccount().getBalance() << "\n";
                                        foundActiveBuyers = true;
                                    }
                                }
                                if (!foundActiveBuyers) {
                                    cout << "No active buyers found.\n";
                                }
                                break;
                            }
                            case VIEW_ALL_SELLERS: {
                                cout << "\n=== All Sellers (Summary) ===\n";
                                bool foundActiveSellers = false;
                                cout << "ID\tName\t\tStore Name\tBalance\n";
                                cout << "--------------------------------------------\n";
                                for (const auto& seller : sellers) {
                                    // Check if seller is not deleted
                                    bool isDeleted = false;
                                    for (int deletedId : deletedSellerIds) {
                                        if (seller.getId() == deletedId) {
                                            isDeleted = true;
                                            break;
                                        }
                                    }
                                    if (!isDeleted) {
                                        cout << seller.getId() << "\t" 
                                             << seller.getName() << "\t\t"
                                             << "Store #" << seller.getId() << "\t$"
                                             << seller.getAccount().getBalance() << "\n";
                                        foundActiveSellers = true;
                                    }
                                }
                                if (!foundActiveSellers) {
                                    cout << "No active sellers found.\n";
                                }
                                break;
                            }
                            case VIEW_ALL_BUYERS_DETAILED:
                                cout << "\n=== All Buyers (Detailed) ===\n";
                                if (buyers.empty()) {
                                    cout << "No buyers found.\n";
                                } else {
                                    for (const auto& buyer : buyers) {
                                        cout << "\n--- Buyer Details ---\n";
                                        cout << "ID: " << buyer.getId() << "\n";
                                        cout << "Name: " << buyer.getName() << "\n";
                                        cout << "Address: " << buyer.getAddress() << "\n";
                                        cout << "Phone: " << buyer.getPhoneNumber() << "\n";
                                        cout << "Email: " << buyer.getEmail() << "\n";
                                        cout << "Bank Account ID: " << buyer.getAccount().getId() << "\n";
                                        cout << "Account Balance: $" << buyer.getAccount().getBalance() << "\n";
                                        cout << "Account Holder: " << buyer.getAccount().getName() << "\n";
                                        cout << "Bank Address: " << buyer.getAccount().getAddress() << "\n";
                                        cout << "Bank Phone: " << buyer.getAccount().getPhoneNumber() << "\n";
                                        cout << "Bank Email: " << buyer.getAccount().getEmail() << "\n";
                                        cout << "---------------------\n";
                                    }
                                }
                                break;
                            case VIEW_ALL_SELLERS_DETAILED:
                                cout << "\n=== All Sellers (Detailed) ===\n";
                                if (sellers.empty()) {
                                    cout << "No sellers found.\n";
                                } else {
                                    for (const auto& seller : sellers) {
                                        cout << "\n--- Seller Details ---\n";
                                        cout << "Buyer ID: " << seller.getId() << "\n";
                                        cout << "Name: " << seller.getName() << "\n";
                                        cout << "Personal Address: " << seller.getAddress() << "\n";
                                        cout << "Personal Phone: " << seller.getPhoneNumber() << "\n";
                                        cout << "Personal Email: " << seller.getEmail() << "\n";
                                        cout << "Store Name: Store #" << seller.getId() << "\n";
                                        cout << "Store Address: " << seller.getStoreAddress() << "\n";
                                        cout << "Store Phone: " << seller.getStorePhoneNumber() << "\n";
                                        cout << "Store Email: " << seller.getStoreEmail() << "\n";
                                        cout << "Bank Account ID: " << seller.getAccount().getId() << "\n";
                                        cout << "Account Balance: $" << seller.getAccount().getBalance() << "\n";
                                        cout << "Account Holder: " << seller.getAccount().getName() << "\n";
                                        cout << "Bank Address: " << seller.getAccount().getAddress() << "\n";
                                        cout << "Bank Phone: " << seller.getAccount().getPhoneNumber() << "\n";
                                        cout << "Bank Email: " << seller.getAccount().getEmail() << "\n";
                                        cout << "----------------------\n";
                                    }
                                }
                                break;
                            case SEARCH: {
                                cout << "Search by:\n";
                                cout << "1. Name\n";
                                cout << "2. Account ID\n";
                                cout << "3. Address\n";
                                cout << "4. Phone Number\n";
                                cout << "5. Back\n";
                                cout << "Select an option: ";

                                int searchChoice;
                                if (!(cin >> searchChoice)) {
                                    cin.clear();
                                    cin.ignore(1024, '\n');
                                    cout << "Invalid input.\n";
                                    break;
                                }
                                if (searchChoice == 5) break;

                                cout << "Search in:\n";
                                cout << "1. Buyers\n";
                                cout << "2. Sellers\n";
                                cout << "3. Both\n";
                                cout << "Select an option: ";
                                int scopeChoice;
                                if (!(cin >> scopeChoice)) {
                                    cin.clear();
                                    cin.ignore(1024, '\n');
                                    cout << "Invalid input.\n";
                                    break;
                                }

                                string query;
                                cout << "Enter search query: ";
                                getline(cin >> ws, query);

                                cout << "[TODO] Search ";
                                if (scopeChoice == 1) cout << "Buyers ";
                                else if (scopeChoice == 2) cout << "Sellers ";
                                else cout << "Both ";
                                cout << "by ";
                                switch (searchChoice) {
                                    case 1: cout << "Name"; break;
                                    case 2: cout << "Account ID"; break;
                                    case 3: cout << "Address"; break;
                                    case 4: cout << "Phone Number"; break;
                                    default: cout << "Unknown"; break;
                                }
                                cout << " => \"" << query << "\"\n";
                                // implement filtering here
                                break;
                            }
                            case CREATE_NEW_ACCOUNT: {
                                CreateAccountPrompt createPrompt = CREATE_BUYER_ACCOUNT;
                                while (createPrompt != BACK_TO_ADMIN) {
                                    cout << "Create New Account:\n";
                                    cout << "1. Create Buyer Account\n";
                                    cout << "2. Create Seller Account\n";
                                    cout << "3. Create Bank Account\n";
                                    cout << "4. Back\n";
                                    cout << "Select an option: ";
                                    int c;
                                    if (!(cin >> c)) {
                                        cin.clear();
                                        cin.ignore(1024, '\n');
                                        cout << "Invalid input.\n";
                                        continue;
                                    }
                                    createPrompt = static_cast<CreateAccountPrompt>(c - 1);
                                    
                                    switch (createPrompt) {
                                        case CREATE_BUYER_ACCOUNT: {
                                            cout << "\n=== Create Buyer Account ===\n";
                                            // collect: Name, Address, Phone, Email
                                            string name, address, phone, email;
                                            double initialDeposit;
                                            
                                            cout << "Name: ";    getline(cin >> ws, name);
                                            cout << "Address: "; getline(cin >> ws, address);
                                            cout << "Phone: ";   getline(cin >> ws, phone);
                                            cout << "Email: ";   getline(cin >> ws, email);
                                            cout << "Initial Bank Deposit: $"; cin >> initialDeposit;
                                            
                                            // Generate new IDs
                                            int newBuyerId = buyers.size() + 1;
                                            int newBankId = bankCustomers.size() + 1;
                                            
                                            // Create bank account first
                                            BankCustomer newBankCustomer(newBankId, name, initialDeposit, address, phone, email);
                                            bankCustomers.push_back(newBankCustomer);
                                            
                                            // Create buyer account linked to bank account
                                            Buyer newBuyer(newBuyerId, name, bankCustomers.back(), address, phone, email);
                                            buyers.push_back(newBuyer);
                                            
                                            cout << "\n✅ Buyer account created successfully!\n";
                                            cout << "Buyer ID: " << newBuyerId << "\n";
                                            cout << "Bank Account ID: " << newBankId << "\n";
                                            cout << "Initial Balance: $" << initialDeposit << "\n";
                                            break;
                                        }
                                        case CREATE_SELLER_ACCOUNT: {
                                            cout << "\n=== Create Seller Account ===\n";
                                            // collect: Buyer link (ID), Store details, contact
                                            string buyerIdStr, storeName, storeAddress, storePhone, storeEmail;
                                            cout << "Link to Buyer ID: "; getline(cin >> ws, buyerIdStr);
                                            
                                            // Find the buyer account
                                            int buyerId = stoi(buyerIdStr);
                                            Buyer* linkedBuyer = nullptr;
                                            for (auto& buyer : buyers) {
                                                if (buyer.getId() == buyerId) {
                                                    linkedBuyer = &buyer;
                                                    break;
                                                }
                                            }
                                            
                                            if (linkedBuyer == nullptr) {
                                                cout << "❌ Error: Buyer with ID " << buyerId << " not found!\n";
                                                break;
                                            }
                                            
                                            // Check if buyer already has a seller account
                                            bool alreadySeller = false;
                                            for (const auto& seller : sellers) {
                                                if (seller.getId() == buyerId) {
                                                    alreadySeller = true;
                                                    break;
                                                }
                                            }
                                            
                                            if (alreadySeller) {
                                                cout << "❌ Error: Buyer " << linkedBuyer->getName() << " already has a seller account!\n";
                                                break;
                                            }
                                            
                                            cout << "Store Name: ";       getline(cin >> ws, storeName);
                                            cout << "Store Address: ";    getline(cin >> ws, storeAddress);
                                            cout << "Store Phone: ";      getline(cin >> ws, storePhone);
                                            cout << "Store Email: ";      getline(cin >> ws, storeEmail);
                                            
                                            // Generate new seller ID
                                            int newSellerId = 100 + sellers.size() + 1;
                                            
                                            // Create seller account
                                            seller newSeller(*linkedBuyer, newSellerId, storeName, storeAddress, storePhone, storeEmail);
                                            sellers.push_back(newSeller);
                                            
                                            cout << "\n✅ Seller account created successfully!\n";
                                            cout << "Seller ID: " << newSellerId << "\n";
                                            cout << "Linked to Buyer: " << linkedBuyer->getName() << " (ID: " << buyerId << ")\n";
                                            cout << "Store Name: " << storeName << "\n";
                                            break;
                                        }
                                        case CREATE_BANK_ACCOUNT: {
                                            cout << "\n=== Create Bank Account ===\n";
                                            // collect: Owner (Buyer/Seller) ID, initial deposit, address, phone, email
                                            string ownerType, ownerIdStr, address, phone, email, name;
                                            double initialDeposit = 0.0;
                                            
                                            cout << "Owner Type (Buyer/Seller): "; getline(cin >> ws, ownerType);
                                            cout << "Owner ID: ";                 getline(cin >> ws, ownerIdStr);
                                            
                                            int ownerId = stoi(ownerIdStr);
                                            bool ownerFound = false;
                                            
                                            // Check if owner exists and get their name
                                            if (ownerType == "Buyer" || ownerType == "buyer") {
                                                for (const auto& buyer : buyers) {
                                                    if (buyer.getId() == ownerId) {
                                                        name = buyer.getName();
                                                        ownerFound = true;
                                                        break;
                                                    }
                                                }
                                            } else if (ownerType == "Seller" || ownerType == "seller") {
                                                for (const auto& seller : sellers) {
                                                    if (seller.getId() == ownerId) {
                                                        name = seller.getName();
                                                        ownerFound = true;
                                                        break;
                                                    }
                                                }
                                            } else {
                                                cout << "❌ Error: Invalid owner type! Use 'Buyer' or 'Seller'\n";
                                                break;
                                            }
                                            
                                            if (!ownerFound) {
                                                cout << "❌ Error: " << ownerType << " with ID " << ownerId << " not found!\n";
                                                break;
                                            }
                                            
                                            cout << "Initial Deposit: $";          cin >> initialDeposit;
                                            cout << "Address: ";                  getline(cin >> ws, address);
                                            cout << "Phone: ";                    getline(cin >> ws, phone);
                                            cout << "Email: ";                    getline(cin >> ws, email);
                                            
                                            // Generate new bank account ID
                                            int newBankId = bankCustomers.size() + 1;
                                            
                                            // Create bank account
                                            BankCustomer newBankAccount(newBankId, name, initialDeposit, address, phone, email);
                                            bankCustomers.push_back(newBankAccount);
                                            
                                            cout << "\n✅ Bank account created successfully!\n";
                                            cout << "Bank Account ID: " << newBankId << "\n";
                                            cout << "Account Holder: " << name << " (" << ownerType << " ID: " << ownerId << ")\n";
                                            cout << "Initial Balance: $" << initialDeposit << "\n";
                                            break;
                                        }
                                        case BACK_TO_ADMIN:
                                            cout << "Returning to admin menu.\n";
                                            break;
                                        default:
                                            cout << "Invalid option.\n";
                                            break;
                                    }
                                }
                                break;
                            }
                            case REMOVE_ACCOUNT: {
                                cout << "\n=== Remove Account ===\n";
                                cout << "Remove which type:\n";
                                cout << "1. Buyer\n";
                                cout << "2. Seller\n";
                                cout << "3. Back\n";
                                cout << "Select an option: ";
                                int t;
                                if (!(cin >> t)) {
                                    cin.clear();
                                    cin.ignore(1024, '\n');
                                    cout << "Invalid input.\n";
                                    break;
                                }
                                if (t == 3) break;

                                string idStr;
                                cout << "Enter ID to remove: ";
                                getline(cin >> ws, idStr);
                                
                                try {
                                    int id = stoi(idStr);
                                    
                                    if (t == 1) {
                                        // Remove Buyer
                                        cout << "\n=== Remove Buyer Account ===\n";
                                        
                                        // Check if buyer already deleted
                                        for (int deletedId : deletedBuyerIds) {
                                            if (deletedId == id) {
                                                cout << "❌ Error: Buyer with ID " << id << " is already deleted!\n";
                                                goto remove_account_end;
                                            }
                                        }
                                        
                                        // Find the buyer
                                        bool buyerFound = false;
                                        string buyerName;
                                        int bankAccountId = -1;
                                        
                                        for (const auto& buyer : buyers) {
                                            if (buyer.getId() == id) {
                                                buyerFound = true;
                                                buyerName = buyer.getName();
                                                bankAccountId = buyer.getAccount().getId();
                                                break;
                                            }
                                        }
                                        
                                        if (!buyerFound) {
                                            cout << "❌ Error: Buyer with ID " << id << " not found!\n";
                                            break;
                                        }
                                        
                                        // Check if buyer has a seller account
                                        bool hasSeller = false;
                                        for (const auto& seller : sellers) {
                                            if (seller.getId() == id) {
                                                // Check if seller is not already deleted
                                                bool sellerDeleted = false;
                                                for (int deletedId : deletedSellerIds) {
                                                    if (deletedId == id) {
                                                        sellerDeleted = true;
                                                        break;
                                                    }
                                                }
                                                if (!sellerDeleted) {
                                                    hasSeller = true;
                                                }
                                                break;
                                            }
                                        }
                                        
                                        if (hasSeller) {
                                            cout << "⚠️  Warning: This buyer also has an active seller account.\n";
                                            cout << "Removing buyer will also remove the seller account.\n";
                                            cout << "Do you want to continue? (y/n): ";
                                            char confirm;
                                            cin >> confirm;
                                            cin.ignore();
                                            
                                            if (confirm != 'y' && confirm != 'Y') {
                                                cout << "Operation cancelled.\n";
                                                break;
                                            }
                                            
                                            // Mark seller as deleted
                                            deletedSellerIds.push_back(id);
                                            cout << "✅ Associated seller account removed.\n";
                                        }
                                        
                                        // Mark buyer and bank account as deleted
                                        deletedBuyerIds.push_back(id);
                                        deletedBankIds.push_back(bankAccountId);
                                        
                                        cout << "✅ Buyer account removed successfully!\n";
                                        cout << "Removed: " << buyerName << " (ID: " << id << ")\n";
                                        cout << "Associated bank account (ID: " << bankAccountId << ") also removed.\n";
                                        
                                    } else if (t == 2) {
                                        // Remove Seller
                                        cout << "\n=== Remove Seller Account ===\n";
                                        
                                        // Check if seller already deleted
                                        for (int deletedId : deletedSellerIds) {
                                            if (deletedId == id) {
                                                cout << "❌ Error: Seller with ID " << id << " is already deleted!\n";
                                                goto remove_account_end;
                                            }
                                        }
                                        
                                        // Find the seller
                                        bool sellerFound = false;
                                        string sellerName;
                                        
                                        for (const auto& seller : sellers) {
                                            if (seller.getId() == id) {
                                                sellerFound = true;
                                                sellerName = seller.getName();
                                                break;
                                            }
                                        }
                                        
                                        if (!sellerFound) {
                                            cout << "❌ Error: Seller with ID " << id << " not found!\n";
                                            break;
                                        }
                                        
                                        cout << "⚠️  Warning: This will remove the seller account but keep the buyer account.\n";
                                        cout << "Do you want to continue? (y/n): ";
                                        char confirm;
                                        cin >> confirm;
                                        cin.ignore();
                                        
                                        if (confirm != 'y' && confirm != 'Y') {
                                            cout << "Operation cancelled.\n";
                                            break;
                                        }
                                        
                                        // Mark seller as deleted
                                        deletedSellerIds.push_back(id);
                                        
                                        cout << "✅ Seller account removed successfully!\n";
                                        cout << "Removed: " << sellerName << " (Seller ID: " << id << ")\n";
                                        cout << "Note: The associated buyer account remains active.\n";
                                        
                                    } else {
                                        cout << "❌ Invalid option.\n";
                                    }
                                    
                                } catch (const invalid_argument& e) {
                                    cout << "❌ Error: Invalid ID format. Please enter a valid number.\n";
                                } catch (const out_of_range& e) {
                                    cout << "❌ Error: ID number is too large.\n";
                                }
                                
                                remove_account_end:
                                break;
                            }
                            case BACK_TO_MAIN:
                                cout << "Returning to main menu.\n";
                                break;
                            default:
                                cout << "Invalid option.\n";
                                break;
                        }
                    }

                } else {
                    cout << "Admin login failed." << endl;
                    break;
                }
                /** After login create a sub prompt that provides the following features
                1. Account Management
                    - View All Buyers, Sellers
                    - View All details of Buyers, Sellers
                    - Seek certain buyer of seller based on Name / account Id / address / phone number
                    - Create new buyer/seller/Bank account
                    - Remove buyer/seller based on ID (all related info will be deleted)
                2. System Report
                    - Total number of Buyers, Sellers
                    - Total number of Banking Accounts
                */
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }

    //BankCustomer customer1(1, "Alice", 1000.0);
    //Buyer buyer1(1, customer1.getName(), customer1);
    return 1;
}