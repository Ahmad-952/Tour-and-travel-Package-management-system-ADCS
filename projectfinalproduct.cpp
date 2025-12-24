#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Structure definitions
struct Customer {
    int custId;
    char custName[50];
    char custPhone[15];
};

struct Package {
    int packageId;
    char destination[50];
    int duration;
    float price;
};

struct Booking {
    int bookingId;
    int bookCustId;
    int bookPackId;
    char bookingDate[15];
    int numPersons;
    float totalAmount;
};

// Global arrays
Customer customers[100];
Package packages[100];
Booking bookings[100];

int custCount = 0, packageCount = 0, bookingCount = 0;

// Load/Save functions
void loadCustomers() {
    ifstream file("customers.txt");
    if (file.is_open()) {
        custCount = 0;
        while (custCount < 100 && file >> customers[custCount].custId) {
            file.ignore();
            file.getline(customers[custCount].custName, 50);
            file.getline(customers[custCount].custPhone, 15);
            custCount++;
        }
        file.close();
    }
}

void saveCustomers() {
    ofstream file("customers.txt");
    for (int i = 0; i < custCount; i++) {
        file << customers[i].custId << "\n"
             << customers[i].custName << "\n"
             << customers[i].custPhone << "\n";
    }
    file.close();
}

void loadPackages() {
    ifstream file("packages.txt");
    if (file.is_open()) {
        packageCount = 0;
        while (packageCount < 100 && file >> packages[packageCount].packageId) {
            file.ignore();
            file.getline(packages[packageCount].destination, 50);
            file >> packages[packageCount].duration >> packages[packageCount].price;
            file.ignore();
            packageCount++;
        }
        file.close();
    }
}

void savePackages() {
    ofstream file("packages.txt");
    for (int i = 0; i < packageCount; i++) {
        file << packages[i].packageId << "\n"
             << packages[i].destination << "\n"
             << packages[i].duration << "\n"
             << packages[i].price << "\n";
    }
    file.close();
}

void loadBookings() {
    ifstream file("bookings.txt");
    if (file.is_open()) {
        bookingCount = 0;
        while (bookingCount < 100 && file >> bookings[bookingCount].bookingId) {
            file >> bookings[bookingCount].bookCustId
                 >> bookings[bookingCount].bookPackId;
            file.ignore();
            file.getline(bookings[bookingCount].bookingDate, 15);
            file >> bookings[bookingCount].numPersons
                 >> bookings[bookingCount].totalAmount;
            file.ignore();
            bookingCount++;
        }
        file.close();
    }
}

void saveBookings() {
    ofstream file("bookings.txt");
    for (int i = 0; i < bookingCount; i++) {
        file << bookings[i].bookingId << "\n"
             << bookings[i].bookCustId << "\n"
             << bookings[i].bookPackId << "\n"
             << bookings[i].bookingDate << "\n"
             << bookings[i].numPersons << "\n"
             << bookings[i].totalAmount << "\n";
    }
    file.close();
}

// Helper functions
bool customerExists(int id) {
    for (int i = 0; i < custCount; i++) {
        if (customers[i].custId == id) return true;
    }
    return false;
}

bool packageExists(int id) {
    for (int i = 0; i < packageCount; i++) {
        if (packages[i].packageId == id) return true;
    }
    return false;
}

bool bookingExists(int id) {
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingId == id) return true;
    }
    return false;
}

float getPackagePrice(int id) {
    for (int i = 0; i < packageCount; i++) {
        if (packages[i].packageId == id) return packages[i].price;
    }
    return 0;
}

int getPackageDuration(int id) {
    for (int i = 0; i < packageCount; i++) {
        if (packages[i].packageId == id) return packages[i].duration;
    }
    return 0;
}

// Customer functions
void addCustomer() {
    if (custCount >= 100) {
        cout << "\nCustomer limit reached!\n";
        return;
    }
    
    cout << "\n--- Add Customer ---\n";
    cout << "Customer ID: ";
    cin >> customers[custCount].custId;
    
    if (customerExists(customers[custCount].custId)) {
        cout << "Error: ID already exists!\n";
        return;
    }
    
    cin.ignore();
    cout << "Name: ";
    cin.getline(customers[custCount].custName, 50);
    cout << "Phone: ";
    cin.getline(customers[custCount].custPhone, 15);
    
    custCount++;
    saveCustomers();
    cout << "Customer added!\n";
}

void viewCustomers() {
    if (custCount == 0) {
        cout << "\nNo customers found!\n";
        return;
    }
    
    cout << "\n--- CUSTOMERS ---\n";
    for (int i = 0; i < custCount; i++) {
        cout << "ID: " << customers[i].custId
             << " | Name: " << customers[i].custName
             << " | Phone: " << customers[i].custPhone << "\n";
    }
}

void searchCustomer() {
    int id;
    cout << "\nEnter Customer ID: ";
    cin >> id;
    
    for (int i = 0; i < custCount; i++) {
        if (customers[i].custId == id) {
            cout << "\nID: " << customers[i].custId << "\n";
            cout << "Name: " << customers[i].custName << "\n";
            cout << "Phone: " << customers[i].custPhone << "\n";
            return;
        }
    }
    cout << "Customer not found!\n";
}

// Package functions
void addPackage() {
    if (packageCount >= 100) {
        cout << "\nPackage limit reached!\n";
        return;
    }
    
    cout << "\n--- Add Package ---\n";
    cout << "Package ID: ";
    cin >> packages[packageCount].packageId;
    
    if (packageExists(packages[packageCount].packageId)) {
        cout << "Error: ID already exists!\n";
        return;
    }
    
    cin.ignore();
    cout << "Destination: ";
    cin.getline(packages[packageCount].destination, 50);
    cout << "Duration (days): ";
    cin >> packages[packageCount].duration;
    cout << "Price: ";
    cin >> packages[packageCount].price;
    
    packageCount++;
    savePackages();
    cout << "Package added!\n";
}

void viewPackages() {
    if (packageCount == 0) {
        cout << "\nNo packages found!\n";
        return;
    }
    
    cout << "\n--- PACKAGES ---\n";
    for (int i = 0; i < packageCount; i++) {
        cout << "ID: " << packages[i].packageId
             << " | Destination: " << packages[i].destination
             << " | Days: " << packages[i].duration
             << " | Price: " << packages[i].price << "\n";
    }
}

void searchPackage() {
    int id;
    cout << "\nEnter Package ID: ";
    cin >> id;
    
    for (int i = 0; i < packageCount; i++) {
        if (packages[i].packageId == id) {
            cout << "\nID: " << packages[i].packageId << "\n";
            cout << "Destination: " << packages[i].destination << "\n";
            cout << "Duration: " << packages[i].duration << " days\n";
            cout << "Price: " << packages[i].price << "\n";
            return;
        }
    }
    cout << "Package not found!\n";
}

// Booking functions
void addBooking() {
    if (bookingCount >= 100) {
        cout << "\nBooking limit reached!\n";
        return;
    }
    
    cout << "\n--- Add Booking ---\n";
    cout << "Booking ID: ";
    cin >> bookings[bookingCount].bookingId;
    
    if (bookingExists(bookings[bookingCount].bookingId)) {
        cout << "Error: Booking ID already exists!\n";
        return;
    }
    
    cout << "Customer ID: ";
    cin >> bookings[bookingCount].bookCustId;
    if (!customerExists(bookings[bookingCount].bookCustId)) {
        cout << "Error: Customer ID does not exist!\n";
        return;
    }
    
    cout << "Package ID: ";
    cin >> bookings[bookingCount].bookPackId;
    if (!packageExists(bookings[bookingCount].bookPackId)) {
        cout << "Error: Package ID does not exist!\n";
        return;
    }
    
    cout << "Departure Date:\n";
    int day, month, year;
    cout << "  Day (DD): ";
    cin >> day;
    cout << "  Month (MM): ";
    cin >> month;
    cout << "  Year (YYYY): ";
    cin >> year;
    
    // Format the date as DD/MM/YYYY
    sprintf(bookings[bookingCount].bookingDate, "%02d/%02d/%04d", day, month, year);
    
    cout << "Number of Persons: ";
    cin >> bookings[bookingCount].numPersons;
    
    if (bookings[bookingCount].numPersons <= 0) {
        cout << "Error: Number of persons must be greater than 0!\n";
        return;
    }
    
    // Auto-calculate total and show package duration
    float price = getPackagePrice(bookings[bookingCount].bookPackId);
    int duration = getPackageDuration(bookings[bookingCount].bookPackId);
    bookings[bookingCount].totalAmount = price * bookings[bookingCount].numPersons;
    
    cout << "\n--- Booking Summary ---\n";
    cout << "Package Price (per person): " << price << "\n";
    cout << "Number of Persons: " << bookings[bookingCount].numPersons << "\n";
    cout << "Tour Duration: " << duration << " days\n";
    cout << "Total Amount: " << bookings[bookingCount].totalAmount << "\n";
    
    bookingCount++;
    saveBookings();
    cout << "\nBooking added successfully!\n";
}

void viewBookings() {
    if (bookingCount == 0) {
        cout << "\nNo bookings found!\n";
        return;
    }
    
    cout << "\n--- BOOKINGS ---\n";
    for (int i = 0; i < bookingCount; i++) {
        int duration = getPackageDuration(bookings[i].bookPackId);
        cout << "Booking ID: " << bookings[i].bookingId
             << " | Customer ID: " << bookings[i].bookCustId
             << " | Package ID: " << bookings[i].bookPackId
             << " | Date: " << bookings[i].bookingDate
             << " | Duration: " << duration << " days"
             << " | Persons: " << bookings[i].numPersons
             << " | Amount: " << bookings[i].totalAmount << "\n";
    }
}

void searchBooking() {
    int id;
    cout << "\nEnter Booking ID: ";
    cin >> id;
    
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingId == id) {
            int duration = getPackageDuration(bookings[i].bookPackId);
            cout << "\nBooking ID: " << bookings[i].bookingId << "\n";
            cout << "Customer ID: " << bookings[i].bookCustId << "\n";
            cout << "Package ID: " << bookings[i].bookPackId << "\n";
            cout << "Departure Date: " << bookings[i].bookingDate << "\n";
            cout << "Tour Duration: " << duration << " days\n";
            cout << "Persons: " << bookings[i].numPersons << "\n";
            cout << "Total Amount: " << bookings[i].totalAmount << "\n";
            return;
        }
    }
    cout << "Booking not found!\n";
}

// Menu
void displayMenu() {
    cout << "\n========================================\n";
    cout << "  TOUR MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add Customer\n";
    cout << "2. View Customers\n";
    cout << "3. Search Customer\n";
    cout << "4. Add Package\n";
    cout << "5. View Packages\n";
    cout << "6. Search Package\n";
    cout << "7. Add Booking\n";
    cout << "8. View Bookings\n";
    cout << "9. Search Booking\n";
    cout << "10. Exit\n";
    cout << "========================================\n";
    cout << "Choice: ";
}

// Main
int main() {
    loadCustomers();
    loadPackages();
    loadBookings();
    
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: addCustomer(); break;
            case 2: viewCustomers(); break;
            case 3: searchCustomer(); break;
            case 4: addPackage(); break;
            case 5: viewPackages(); break;
            case 6: searchPackage(); break;
            case 7: addBooking(); break;
            case 8: viewBookings(); break;
            case 9: searchBooking(); break;
            case 10: cout << "\nThank you!\n"; break;
            default: cout << "\nInvalid choice!\n";
        }
        
    } while (choice != 10);
    
    return 0;
}
