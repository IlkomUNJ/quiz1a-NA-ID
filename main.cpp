#include <iostream>
#include "bank_customer.h"
#include "buyer.h"

enum PrimaryPrompt{LOGIN, REGISTER, EXIT, ADMIN_LOGIN};
enum RegisterPrompt{CREATE_BUYER, CREATE_SELLER, BACK};
enum AdminPrompt{VIEW_ALL_BUYERS, VIEW_ALL_SELLERS, VIEW_ALL_BUYERS_DETAILED, VIEW_ALL_SELLERS_DETAILED, SEARCH, CREATE_NEW_ACCOUNT, REMOVE_ACCOUNT, BACK_TO_MAIN};
using namespace std;

int main() {
    //create a loop prompt 
    PrimaryPrompt prompt = LOGIN;
    RegisterPrompt regPrompt = CREATE_BUYER;
    const string ADMIN_USERNAME = "root";
    const string ADMIN_PASSWORD = "toor";
    string username, password;

    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Admin Login" << endl;
        int choice;
        cin >> choice;
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
                            case VIEW_ALL_BUYERS:
                                cout << "[TODO] View All Buyers\n";
                                // list all buyers (summary)
                                break;
                            case VIEW_ALL_SELLERS:
                                cout << "[TODO] View All Sellers\n";
                                // list all sellers (summary)
                                break;
                            case VIEW_ALL_BUYERS_DETAILED:
                                cout << "[TODO] View All Buyers (Detailed)\n";
                                // list all buyers with full details
                                break;
                            case VIEW_ALL_SELLERS_DETAILED:
                                cout << "[TODO] View All Sellers (Detailed)\n";
                                // list all sellers with full details
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
                                bool createActive = true;
                                while (createActive) {
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
                                    switch (c) {
                                        case 1: {
                                            cout << "[TODO] Create Buyer Account\n";
                                            // collect: Name, Address, Phone, Email
                                            string name, address, phone, email;
                                            cout << "Name: ";    getline(cin >> ws, name);
                                            cout << "Address: "; getline(cin >> ws, address);
                                            cout << "Phone: ";   getline(cin >> ws, phone);
                                            cout << "Email: ";   getline(cin >> ws, email);
                                            cout << "[TODO] Persist buyer account\n";
                                            break;
                                        }
                                        case 2: {
                                            cout << "[TODO] Create Seller Account\n";
                                            // collect: Buyer link (ID), Store details, contact
                                            string buyerId, storeName, storeAddress, storePhone, storeEmail;
                                            cout << "Link to Buyer ID: "; getline(cin >> ws, buyerId);
                                            cout << "Store Name: ";       getline(cin >> ws, storeName);
                                            cout << "Store Address: ";    getline(cin >> ws, storeAddress);
                                            cout << "Store Phone: ";      getline(cin >> ws, storePhone);
                                            cout << "Store Email: ";      getline(cin >> ws, storeEmail);
                                            cout << "[TODO] Persist seller account and link to buyer\n";
                                            break;
                                        }
                                        case 3: {
                                            cout << "[TODO] Create Bank Account\n";
                                            // collect: Owner (Buyer/Seller) ID, initial deposit, address, phone, email
                                            string ownerType, ownerId, address, phone, email;
                                            double initialDeposit = 0.0;
                                            cout << "Owner Type (Buyer/Seller): "; getline(cin >> ws, ownerType);
                                            cout << "Owner ID: ";                 getline(cin >> ws, ownerId);
                                            cout << "Initial Deposit: ";          cin >> initialDeposit;
                                            cout << "Address: ";                  getline(cin >> ws, address);
                                            cout << "Phone: ";                    getline(cin >> ws, phone);
                                            cout << "Email: ";                    getline(cin >> ws, email);
                                            cout << "[TODO] Persist bank account and link to owner\n";
                                            break;
                                        }
                                        case 4:
                                            createActive = false;
                                            break;
                                        default:
                                            cout << "Invalid option.\n";
                                            break;
                                    }
                                }
                                break;
                            }
                            case REMOVE_ACCOUNT: {
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

                                string id;
                                cout << "Enter ID to remove: ";
                                getline(cin >> ws, id);

                                if (t == 1) {
                                    cout << "[TODO] Remove Buyer with ID: " << id << " (and related data)\n";
                                } else if (t == 2) {
                                    cout << "[TODO] Remove Seller with ID: " << id << " (and related data)\n";
                                } else {
                                    cout << "Invalid option.\n";
                                }
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