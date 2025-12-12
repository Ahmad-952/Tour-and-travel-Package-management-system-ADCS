#include <iostream>
#include <fstream>
using namespace std;

// Global arrays to store data
int custId[100], packageId[100], bookingId[100];
char custName[100][50], custPhone[100][15], custEmail[100][50];
char destination[100][50], packageDesc[100][100];
int duration[100];
float price[100];
int bookCustId[100], bookPackId[100], numPersons[100];
char bookingDate[100][15], travelDate[100][15];
float totalAmount[100];

int custCount = 0, packageCount = 0, bookingCount = 0;

// Function to load customers from file
void loadCustomers() {
    ifstream file("customers.txt");
    if (file) {
        custCount = 0;
        while (file >> custId[custCount]) {
            file.ignore();
            file.getline(custName[custCount], 50);
            file.getline(custPhone[custCount], 15);
            file.getline(custEmail[custCount], 50);
            custCount++;
        }
        file.close();
    }
}

// Function to save customers to file
void saveCustomers() {
    ofstream file("customers.txt");
    for (int i = 0; i < custCount; i++) {
        file << custId[i] << "\n";
        file << custName[i] << "\n";
        file << custPhone[i] << "\n";
        file << custEmail[i] << "\n";
    }
    file.close();
}

// Function to add a new customer
void addCustomer() {
    cout << "\n--- Add New Customer ---\n";
    cout << "Enter Customer ID: ";
    cin >> custId[custCount];
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(custName[custCount], 50);

    cout << "Enter Phone: ";
    cin.getline(custPhone[custCount], 15);

    cout << "Enter Email: ";
    cin.getline(custEmail[custCount], 50);

    custCount++;
    saveCustomers();

    cout << "\nCustomer added successfully!\n";
}

// Function to view all customers
void viewAllCustomers() {
    if (custCount == 0) {
        cout << "\nNo customer records found!\n";
        return;
    }

    cout << "\n========== CUSTOMER LIST ==========\n";
    cout << "ID\tName\t\t\tPhone\t\tEmail\n";
    cout << "-----------------------------------------------------------\n";

    for (int i = 0; i < custCount; i++) {
        cout << custId[i] << "\t" << custName[i] << "\t\t"
            << custPhone[i] << "\t" << custEmail[i] << "\n";
    }
}

// Function to search customer by ID
void searchCustomer() {
    int id;
    bool found = false;

    cout << "\nEnter Customer ID to search: ";
    cin >> id;

    for (int i = 0; i < custCount; i++) {
        if (custId[i] == id) {
            cout << "\n--- Customer Found ---\n";
            cout << "ID: " << custId[i] << "\n";
            cout << "Name: " << custName[i] << "\n";
            cout << "Phone: " << custPhone[i] << "\n";
            cout << "Email: " << custEmail[i] << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nCustomer not found!\n";
    }
}

// Function to load packages from file
void loadPackages() {
    ifstream file("packages.txt");
    if (file) {
        packageCount = 0;
        while (file >> packageId[packageCount]) {
            file.ignore();
            file.getline(destination[packageCount], 50);
            file >> duration[packageCount];
            file >> price[packageCount];
            file.ignore();
            file.getline(packageDesc[packageCount], 100);
            packageCount++;
        }
        file.close();
    }
}

// Function to save packages to file
void savePackages() {
    ofstream file("packages.txt");
    for (int i = 0; i < packageCount; i++) {
        file << packageId[i] << "\n";
        file << destination[i] << "\n";
        file << duration[i] << "\n";
        file << price[i] << "\n";
        file << packageDesc[i] << "\n";
    }
    file.close();
}

// Function to add a new tour package
void addPackage() {
    cout << "\n--- Add New Tour Package ---\n";
    cout << "Enter Package ID: ";
    cin >> packageId[packageCount];
    cin.ignore();

    cout << "Enter Destination: ";
    cin.getline(destination[packageCount], 50);

    cout << "Enter Duration (days): ";
    cin >> duration[packageCount];

    cout << "Enter Price: ";
    cin >> price[packageCount];
    cin.ignore();

    cout << "Enter Description: ";
    cin.getline(packageDesc[packageCount], 100);

    packageCount++;
    savePackages();

    cout << "\nPackage added successfully!\n";
}

// Function to view all tour packages
void viewAllPackages() {
    if (packageCount == 0) {
        cout << "\nNo package records found!\n";
        return;
    }

    cout << "\n========== TOUR PACKAGES ==========\n";
    cout << "ID\tDestination\tDays\tPrice\t\tDescription\n";
    cout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < packageCount; i++) {
        cout << packageId[i] << "\t" << destination[i] << "\t\t"
            << duration[i] << "\t" << price[i] << "\t\t"
            << packageDesc[i] << "\n";
    }
}

// Function to search package by ID
void searchPackage() {
    int id;
    bool found = false;

    cout << "\nEnter Package ID to search: ";
    cin >> id;

    for (int i = 0; i < packageCount; i++) {
        if (packageId[i] == id) {
            cout << "\n--- Package Found ---\n";
            cout << "Package ID: " << packageId[i] << "\n";
            cout << "Destination: " << destination[i] << "\n";
            cout << "Duration: " << duration[i] << " days\n";
            cout << "Price: " << price[i] << "\n";
            cout << "Description: " << packageDesc[i] << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nPackage not found!\n";
    }
}

// Function to load bookings from file
void loadBookings() {
    ifstream file("bookings.txt");
    if (file) {
        bookingCount = 0;
        while (file >> bookingId[bookingCount]) {
            file >> bookCustId[bookingCount];
            file >> bookPackId[bookingCount];
            file.ignore();
            file.getline(bookingDate[bookingCount], 15);
            file.getline(travelDate[bookingCount], 15);
            file >> numPersons[bookingCount];
            file >> totalAmount[bookingCount];
            file.ignore();
            bookingCount++;
        }
        file.close();
    }
}

// Function to save bookings to file
void saveBookings() {
    ofstream file("bookings.txt");
    for (int i = 0; i < bookingCount; i++) {
        file << bookingId[i] << "\n";
        file << bookCustId[i] << "\n";
        file << bookPackId[i] << "\n";
        file << bookingDate[i] << "\n";
        file << travelDate[i] << "\n";
        file << numPersons[i] << "\n";
        file << totalAmount[i] << "\n";
    }
    file.close();
}

// Function to add a new booking
void addBooking() {
    cout << "\n--- Add New Booking ---\n";
    cout << "Enter Booking ID: ";
    cin >> bookingId[bookingCount];

    cout << "Enter Customer ID: ";
    cin >> bookCustId[bookingCount];

    cout << "Enter Package ID: ";
    cin >> bookPackId[bookingCount];
    cin.ignore();

    cout << "Enter Booking Date (DD/MM/YYYY): ";
    cin.getline(bookingDate[bookingCount], 15);

    cout << "Enter Travel Date (DD/MM/YYYY): ";
    cin.getline(travelDate[bookingCount], 15);

    cout << "Enter Number of Persons: ";
    cin >> numPersons[bookingCount];

    cout << "Enter Total Amount: ";
    cin >> totalAmount[bookingCount];

    bookingCount++;
    saveBookings();

    cout << "\nBooking added successfully!\n";
}

// Function to view all bookings
void viewAllBookings() {
    if (bookingCount == 0) {
        cout << "\nNo booking records found!\n";
        return;
    }

    cout << "\n========== BOOKING LIST ==========\n";
    cout << "BookID\tCustID\tPackID\tBookDate\tTravelDate\tPersons\tAmount\n";
    cout << "------------------------------------------------------------------------\n";

    for (int i = 0; i < bookingCount; i++) {
        cout << bookingId[i] << "\t" << bookCustId[i] << "\t"
            << bookPackId[i] << "\t" << bookingDate[i] << "\t"
            << travelDate[i] << "\t\t" << numPersons[i] << "\t"
            << totalAmount[i] << "\n";
    }
}

// Function to search booking by ID
void searchBooking() {
    int id;
    bool found = false;

    cout << "\nEnter Booking ID to search: ";
    cin >> id;

    for (int i = 0; i < bookingCount; i++) {
        if (bookingId[i] == id) {
            cout << "\n--- Booking Found ---\n";
            cout << "Booking ID: " << bookingId[i] << "\n";
            cout << "Customer ID: " << bookCustId[i] << "\n";
            cout << "Package ID: " << bookPackId[i] << "\n";
            cout << "Booking Date: " << bookingDate[i] << "\n";
            cout << "Travel Date: " << travelDate[i] << "\n";
            cout << "Number of Persons: " << numPersons[i] << "\n";
            cout << "Total Amount: " << totalAmount[i] << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nBooking not found!\n";
    }
}

// Function to display menu
void displayMenu() {
    cout << "\n============================================\n";
    cout << "  TOUR AND TRAVEL MANAGEMENT SYSTEM\n";
    cout << "============================================\n";
    cout << "1.  Add Customer\n";
    cout << "2.  View All Customers\n";
    cout << "3.  Search Customer\n";
    cout << "4.  Add Tour Package\n";
    cout << "5.  View All Packages\n";
    cout << "6.  Search Package\n";
    cout << "7.  Add Booking\n";
    cout << "8.  View All Bookings\n";
    cout << "9.  Search Booking\n";
    cout << "10. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    int choice;

    // Load existing data from files
    loadCustomers();
    loadPackages();
    loadBookings();

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            addCustomer();
        }
        else if (choice == 2) {
            viewAllCustomers();
        }
        else if (choice == 3) {
            searchCustomer();
        }
        else if (choice == 4) {
            addPackage();
        }
        else if (choice == 5) {
            viewAllPackages();
        }
        else if (choice == 6) {
            searchPackage();
        }
        else if (choice == 7) {
            addBooking();
        }
        else if (choice == 8) {
            viewAllBookings();
        }
        else if (choice == 9) {
            searchBooking();
        }
        else if (choice == 10) {
            cout << "\nThank you for using the system!\n";
            cout << "Goodbye!\n";
        }
        else {
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 10);

    return 0;
}