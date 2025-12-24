#include <iostream>
#include <fstream>
using namespace std;

//  STRUCTURES 

struct Patient {
    int id;
    char name[50];
    int age;
    char contact[15];
};

struct Appointment {
    int patientId;
    char doctorName[50];
    char date[15];
};

struct Treatment {
    int patientId;
    char disease[50];
    char medicine[50];
};

struct Bill {
    int patientId;
    int roomDays;
    float totalAmount;
};

//  ARRAYS

Patient patients[50];
Appointment appointments[50];
Treatment treatments[50];
Bill bills[50];

int pCount = 0, aCount = 0, tCount = 0, bCount = 0;

//  LOAD DATA  (FIXED FOR SPACES)

void loadData() {
    ifstream pFile("patients.txt");
    while (pFile >> patients[pCount].id) {
        pFile.ignore();
        pFile.getline(patients[pCount].name, 50);
        pFile >> patients[pCount].age
              >> patients[pCount].contact;
        pCount++;
    }
    pFile.close();

    ifstream aFile("appointments.txt");
    while (aFile >> appointments[aCount].patientId) {
        aFile.ignore();
        aFile.getline(appointments[aCount].doctorName, 50);
        aFile >> appointments[aCount].date;
        aCount++;
    }
    aFile.close();

    ifstream tFile("treatments.txt");
    while (tFile >> treatments[tCount].patientId
                 >> treatments[tCount].disease
                 >> treatments[tCount].medicine) {
        tCount++;
    }
    tFile.close();

    ifstream bFile("bills.txt");
    while (bFile >> bills[bCount].patientId
                 >> bills[bCount].roomDays
                 >> bills[bCount].totalAmount) {
        bCount++;
    }
    bFile.close();
}

//  ADD PATIENT  (GETLINE ADDED)

void addPatient() {
    Patient p;
    cout << "\nEnter Patient ID: ";
    cin >> p.id;
    cin.ignore();   // ? important

    for (int i = 0; i < pCount; i++) {
        if (patients[i].id == p.id) {
            cout << "Patient already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin.getline(p.name, 50);
    cout << "Enter Age: ";
    cin >> p.age;
    cout << "Enter Contact: ";
    cin >> p.contact;

    patients[pCount++] = p;

    ofstream file("patients.txt");
    file << p.id << endl
         << p.name << endl
         << p.age << " " << p.contact << endl;
    file.close();

    cout << "Patient Added Successfully!\n";
}

//  UPDATE PATIENT  (GETLINE ADDED)

void updatePatient() {
    int id;
    cout << "\nEnter Patient ID to update: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < pCount; i++) {
        if (patients[i].id == id) {
            cout << "New Name: ";
            cin.getline(patients[i].name, 50);
            cout << "New Age: ";
            cin >> patients[i].age;
            cout << "New Contact: ";
            cin >> patients[i].contact;

            ofstream file("patients.txt");
            for (int j = 0; j < pCount; j++) {
                file << patients[j].id << endl
                     << patients[j].name << endl
                     << patients[j].age << " "
                     << patients[j].contact << endl;
            }
            file.close();

            cout << "Patient Updated!\n";
            return;
        }
    }
    cout << "Patient not found!\n";
}

// ---------------- ADD APPOINTMENT ----------------

void addAppointment() {
    Appointment a;
    cout << "Patient ID: ";
    cin >> a.patientId;
    cin.ignore();

    cout << "Doctor Name: ";
    cin.getline(a.doctorName, 50);
    cout << "Date: ";
    cin >> a.date;

    appointments[aCount++] = a;

    ofstream file("appointments.txt");
    file << a.patientId << endl
         << a.doctorName << endl
         << a.date << endl;
    file.close();

    cout << "Appointment Added!\n";
}

// ---------------- ADD TREATMENT ----------------

void addTreatment() {
    Treatment t;
    cout << "Patient ID: ";
    cin >> t.patientId;
    cout << "Disease: ";
    cin >> t.disease;
    cout << "Medicine: ";
    cin >> t.medicine;

    treatments[tCount++] = t;

    ofstream file("treatments.txt");
    file << t.patientId << " "
         << t.disease << " "
         << t.medicine << endl;
    file.close();

    cout << "Treatment Added!\n";
}

// ---------------- ADD BILL ----------------

void addBill() {
    Bill b;
    const float DOCTOR_FEE = 500;
    const float ROOM_CHARGE = 1000;

    cout << "Patient ID: ";
    cin >> b.patientId;
    cout << "Room Days: ";
    cin >> b.roomDays;

    b.totalAmount = DOCTOR_FEE + (b.roomDays * ROOM_CHARGE);
    bills[bCount++] = b;

    ofstream file("bills.txt");
    file << b.patientId << " "
         << b.roomDays << " "
         << b.totalAmount << endl;
    file.close();

    cout << "Total Bill: " << b.totalAmount << endl;
}

// ---------------- TRACK PATIENT ----------------

void trackPatient() {
    int id;
    cout << "\nEnter Patient ID: ";
    cin >> id;

    cout << "\n--- PATIENT INFO ---\n";
    for (int i = 0; i < pCount; i++) {
        if (patients[i].id == id) {
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Contact: " << patients[i].contact << endl;
        }
    }

    cout << "\n--- APPOINTMENTS ---\n";
    for (int i = 0; i < aCount; i++) {
        if (appointments[i].patientId == id) {
            cout << appointments[i].doctorName
                 << " | " << appointments[i].date << endl;
        }
    }

    cout << "\n--- TREATMENTS ---\n";
    for (int i = 0; i < tCount; i++) {
        if (treatments[i].patientId == id) {
            cout << treatments[i].disease
                 << " | " << treatments[i].medicine << endl;
        }
    }

    cout << "\n--- BILLS ---\n";
    for (int i = 0; i < bCount; i++) {
        if (bills[i].patientId == id) {
            cout << "Amount: " << bills[i].totalAmount << endl;
        }
    }
}

// ---------------- MAIN ----------------

int main() {
    loadData();
    int choice;

    do {
    	cout<<"========HOSPITAL MANAGEMENT SYSTEM======="<<endl;
        cout << "\n1.Add Patient";
        cout << "\n2.Update Patient";
        cout << "\n3.Add Appointment";
        cout << "\n4.Add Treatment";
        cout << "\n5.Add Bill";
        cout << "\n6.Track Patient";
        cout << "\n0.Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                updatePatient();
                break;
            case 3:
                addAppointment();
                break;
            case 4:
                addTreatment();
                break;
            case 5:
                addBill();
                break;
            case 6:
                trackPatient();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
                break;
        }

    } while (choice != 0);

    return 0;
}


