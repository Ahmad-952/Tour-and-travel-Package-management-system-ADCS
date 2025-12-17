    #include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Structure definitions
struct Customer {
    int custId;
    char custName[50];
    char custPhone[15];
    char custEmail[50];
};

struct Package {
    int packageId;
    char destination[50];
    int duration;
    float price;
    char packageDesc[100];
};

struct Schedule {
    int scheduleId;
    int schedPackId;
    char schedDestination[50];
    char departureDate[15];
    char returnDate[15];
    char departureTime[10];
    char guideName[50];
    int availableSeats;
};

struct Booking {
    int bookingId;
    int bookCustId;
    int bookPackId;
    char bookingDate[15];
    char travelDate[15];
    int numPersons;
    float totalAmount;
};

// Global arrays using structures
Customer customers[100];
Package packages[100];
Schedule schedules[100];
Booking bookings[100];

int custCount = 0, packageCount = 0, scheduleCount = 0, bookingCount = 0;

// Function to load customers from file
void loadCustomers() {
    ifstream file("customers.txt");
    if (file) {
        custCount = 0;
        while (file >> customers[custCount].custId) {
            file.ignore();
            file.getline(customers[custCount].custName, 50);
            file.getline(customers[custCount].custPhone, 15);
            file.getline(customers[custCount].custEmail, 50);
            custCount++;
        }
        file.close();
    }
}

// Function to save customers to file
void saveCustomers() {
    ofstream file("customers.txt");
    for (int i = 0; i < custCount; i++) {
        file << customers[i].custId << "\n";
        file << customers[i].custName << "\n";
        file << customers[i].custPhone << "\n";
        file << customers[i].custEmail << "\n";
    }
    file.close();
}

// Function to add a new customer
void addCustomer() {
    cout << "\n--- Add New Customer ---\n";
    cout << "Enter Customer ID: ";
    cin >> customers[custCount].custId;
    cin.ignore();
    
    cout << "Enter Name: ";
    cin.getline(customers[custCount].custName, 50);
    
    cout << "Enter Phone: ";
    cin.getline(customers[custCount].custPhone, 15);
    
    cout << "Enter Email: ";
    cin.getline(customers[custCount].custEmail, 50);
    
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
        cout << customers[i].custId << "\t" << customers[i].custName << "\t\t" 
             << customers[i].custPhone << "\t" << customers[i].custEmail << "\n";
    }
}

// Function to search customer by ID
void searchCustomer() {
    int id;
    bool found = false;
    
    cout << "\nEnter Customer ID to search: ";
    cin >> id;
    
    for (int i = 0; i < custCount; i++) {
        if (customers[i].custId == id) {
            cout << "\n--- Customer Found ---\n";
            cout << "ID: " << customers[i].custId << "\n";
            cout << "Name: " << customers[i].custName << "\n";
            cout << "Phone: " << customers[i].custPhone << "\n";
            cout << "Email: " << customers[i].custEmail << "\n";
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
        while (file >> packages[packageCount].packageId) {
            file.ignore();
            file.getline(packages[packageCount].destination, 50);
            file >> packages[packageCount].duration;
            file >> packages[packageCount].price;
            file.ignore();
            file.getline(packages[packageCount].packageDesc, 100);
            packageCount++;
        }
        file.close();
    }
}

// Function to save packages to file
void savePackages() {
    ofstream file("packages.txt");
    for (int i = 0; i < packageCount; i++) {
        file << packages[i].packageId << "\n";
        file << packages[i].destination << "\n";
        file << packages[i].duration << "\n";
        file << packages[i].price << "\n";
        file << packages[i].packageDesc << "\n";
    }
    file.close();
}

// Function to add a new tour package
void addPackage() {
    cout << "\n--- Add New Tour Package ---\n";
    cout << "Enter Package ID: ";
    cin >> packages[packageCount].packageId;
    cin.ignore();
    
    cout << "Enter Destination: ";
    cin.getline(packages[packageCount].destination, 50);
    
    cout << "Enter Duration (days): ";
    cin >> packages[packageCount].duration;
    
    cout << "Enter Price: ";
    cin >> packages[packageCount].price;
    cin.ignore();
    
    cout << "Enter Description: ";
    cin.getline(packages[packageCount].packageDesc, 100);
    
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
        cout << packages[i].packageId << "\t" << packages[i].destination << "\t\t" 
             << packages[i].duration << "\t" << packages[i].price << "\t\t" 
             << packages[i].packageDesc << "\n";
    }
}

// Function to search package by ID
void searchPackage() {
    int id;
    bool found = false;
    
    cout << "\nEnter Package ID to search: ";
    cin >> id;
    
    for (int i = 0; i < packageCount; i++) {
        if (packages[i].packageId == id) {
            cout << "\n--- Package Found ---\n";
            cout << "Package ID: " << packages[i].packageId << "\n";
            cout << "Destination: " << packages[i].destination << "\n";
            cout << "Duration: " << packages[i].duration << " days\n";
            cout << "Price: " << packages[i].price << "\n";
            cout << "Description: " << packages[i].packageDesc << "\n";
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\nPackage not found!\n";
    }
}

// Function to load schedules from file
void loadSchedules() {
    ifstream file("schedules.txt");
    if (file) {
        scheduleCount = 0;
        while (file >> schedules[scheduleCount].scheduleId) {
            file >> schedules[scheduleCount].schedPackId;
            file.ignore();
            file.getline(schedules[scheduleCount].schedDestination, 50);
            file.getline(schedules[scheduleCount].departureDate, 15);
            file.getline(schedules[scheduleCount].returnDate, 15);
            file.getline(schedules[scheduleCount].departureTime, 10);
            file.getline(schedules[scheduleCount].guideName, 50);
            file >> schedules[scheduleCount].availableSeats;
            file.ignore();
            scheduleCount++;
        }
        file.close();
    }
}

// Function to save schedules to file
void saveSchedules() {
    ofstream file("schedules.txt");
    for (int i = 0; i < scheduleCount; i++) {
        file << schedules[i].scheduleId << "\n";
        file << schedules[i].schedPackId << "\n";
        file << schedules[i].schedDestination << "\n";
        file << schedules[i].departureDate << "\n";
        file << schedules[i].returnDate << "\n";
        file << schedules[i].departureTime << "\n";
        file << schedules[i].guideName << "\n";
        file << schedules[i].availableSeats << "\n";
    }
    file.close();
}

// Function to add a new schedule
void addSchedule() {
    cout << "\n--- Add New Tour Schedule ---\n";
    cout << "Enter Schedule ID: ";
    cin >> schedules[scheduleCount].scheduleId;
    
    cout << "Enter Package ID: ";
    cin >> schedules[scheduleCount].schedPackId;
    cin.ignore();
    
    cout << "Enter Destination: ";
    cin.getline(schedules[scheduleCount].schedDestination, 50);
    
    cout << "Enter Departure Date (DD/MM/YYYY): ";
    cin.getline(schedules[scheduleCount].departureDate, 15);
    
    cout << "Enter Return Date (DD/MM/YYYY): ";
    cin.getline(schedules[scheduleCount].returnDate, 15);
    
    cout << "Enter Departure Time (HH:MM): ";
    cin.getline(schedules[scheduleCount].departureTime, 10);
    
    cout << "Enter Guide Name: ";
    cin.getline(schedules[scheduleCount].guideName, 50);
    
    cout << "Enter Available Seats: ";
    cin >> schedules[scheduleCount].availableSeats;
    
    scheduleCount++;
    saveSchedules();
    
    cout << "\nSchedule added successfully!\n";
}

// Function to view all schedules
void viewAllSchedules() {
    if (scheduleCount == 0) {
        cout << "\nNo schedule records found!\n";
        return;
    }
    
    cout << "\n========== TOUR SCHEDULES ==========\n";
    cout << "SchedID\tPackID\tDestination\tDeparture\tReturn\t\tTime\tGuide\t\tSeats\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    
    for (int i = 0; i < scheduleCount; i++) {
        cout << schedules[i].scheduleId << "\t" << schedules[i].schedPackId << "\t" 
             << schedules[i].schedDestination << "\t" << schedules[i].departureDate << "\t" 
             << schedules[i].returnDate << "\t" << schedules[i].departureTime << "\t" 
             << schedules[i].guideName << "\t" << schedules[i].availableSeats << "\n";
    }
}

// Function to search schedule by ID
void searchSchedule() {
    int id;
    bool found = false;
    
    cout << "\nEnter Schedule ID to search: ";
    cin >> id;
    
    for (int i = 0; i < scheduleCount; i++) {
        if (schedules[i].scheduleId == id) {
            cout << "\n--- Schedule Found ---\n";
            cout << "Schedule ID: " << schedules[i].scheduleId << "\n";
            cout << "Package ID: " << schedules[i].schedPackId << "\n";
            cout << "Destination: " << schedules[i].schedDestination << "\n";
            cout << "Departure Date: " << schedules[i].departureDate << "\n";
            cout << "Return Date: " << schedules[i].returnDate << "\n";
            cout << "Departure Time: " << schedules[i].departureTime << "\n";
            cout << "Guide Name: " << schedules[i].guideName << "\n";
            cout << "Available Seats: " << schedules[i].availableSeats << "\n";
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\nSchedule not found!\n";
    }
}

// Function to load bookings from file
void loadBookings() {
    ifstream file("bookings.txt");
    if (file) {
        bookingCount = 0;
        while (file >> bookings[bookingCount].bookingId) {
            file >> bookings[bookingCount].bookCustId;
            file >> bookings[bookingCount].bookPackId;
            file.ignore();
            file.getline(bookings[bookingCount].bookingDate, 15);
            file.getline(bookings[bookingCount].travelDate, 15);
            file >> bookings[bookingCount].numPersons;
            file >> bookings[bookingCount].totalAmount;
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
        file << bookings[i].bookingId << "\n";
        file << bookings[i].bookCustId << "\n";
        file << bookings[i].bookPackId << "\n";
        file << bookings[i].bookingDate << "\n";
        file << bookings[i].travelDate << "\n";
        file << bookings[i].numPersons << "\n";
        file << bookings[i].totalAmount << "\n";
    }
    file.close();
}

// Function to add a new booking
void addBooking() {
    cout << "\n--- Add New Booking ---\n";
    cout << "Enter Booking ID: ";
    cin >> bookings[bookingCount].bookingId;
    
    cout << "Enter Customer ID: ";
    cin >> bookings[bookingCount].bookCustId;
    
    cout << "Enter Package ID: ";
    cin >> bookings[bookingCount].bookPackId;
    cin.ignore();
    
    cout << "Enter Booking Date (DD/MM/YYYY): ";
    cin.getline(bookings[bookingCount].bookingDate, 15);
    
    cout << "Enter Travel Date (DD/MM/YYYY): ";
    cin.getline(bookings[bookingCount].travelDate, 15);
    
    cout << "Enter Number of Persons: ";
    cin >> bookings[bookingCount].numPersons;
    
    cout << "Enter Total Amount: ";
    cin >> bookings[bookingCount].totalAmount;
    
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
        cout << bookings[i].bookingId << "\t" << bookings[i].bookCustId << "\t" 
             << bookings[i].bookPackId << "\t" << bookings[i].bookingDate << "\t" 
             << bookings[i].travelDate << "\t\t" << bookings[i].numPersons << "\t" 
             << bookings[i].totalAmount << "\n";
    }
}

// Function to search booking by ID
void searchBooking() {
    int id;
    bool found = false;
    
    cout << "\nEnter Booking ID to search: ";
    cin >> id;
    
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingId == id) {
            cout << "\n--- Booking Found ---\n";
            cout << "Booking ID: " << bookings[i].bookingId << "\n";
            cout << "Customer ID: " << bookings[i].bookCustId << "\n";
            cout << "Package ID: " << bookings[i].bookPackId << "\n";
            cout << "Booking Date: " << bookings[i].bookingDate << "\n";
            cout << "Travel Date: " << bookings[i].travelDate << "\n";
            cout << "Number of Persons: " << bookings[i].numPersons << "\n";
            cout << "Total Amount: " << bookings[i].totalAmount << "\n";
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
    cout << "7.  Add Tour Schedule\n";
    cout << "8.  View All Schedules\n";
    cout << "9.  Search Schedule\n";
    cout << "10. Add Booking\n";
    cout << "11. View All Bookings\n";
    cout << "12. Search Booking\n";
    cout << "13. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    int choice;
    
    // Load existing data from files
    loadCustomers();
    loadPackages();
    loadSchedules();
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
            addSchedule();
        }
        else if (choice == 8) {
            viewAllSchedules();
        }
        else if (choice == 9) {
            searchSchedule();
        }
        else if (choice == 10) {
            addBooking();
        }
        else if (choice == 11) {
            viewAllBookings();
        }
        else if (choice == 12) {
            searchBooking();
        }
        else if (choice == 13) {
            cout << "\nThank you for using the system!\n";
            cout << "Goodbye!\n";
        }
        else {
            cout << "\nInvalid choice! Please try again.\n";
        }
        
    } while (choice != 13);
    
    return 0;
}
