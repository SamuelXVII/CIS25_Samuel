#include <iostream>
#include <string>
#include <iostream>
using namespace std;

//struct & array & binary search
const int SIZE = 5;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

Patient patients[SIZE];
int patientCount = 0;  // Tracks how many patients are added

// Function to add a new patient
void addPatient() { // ID, Name, Age, Gender, Diagnosis
    if (patientCount >= SIZE) {
        cout << "Sorry, databse is at full capacity.\n";
        return;
    }

    Patient &p = patients[patientCount];  // Reference to current patient

    cout << "Enter Patient ID: ";
    cin >> p.id;
    cout << "Enter Patient Name: ";
    cin >> p.name;
    cout << "Enter Patient Age: ";
    cin >> p.age;
    cout << "Enter Patient Gender: ";
    cin >> p.gender;
    cout << "Enter Patient Diagnosis: ";
    cin >> p.diagnosis;

    patientCount++;
}

// Function to display all patients
void displayPatient() { // ID, Name, Age, Gender, Diagnosis
    if (patientCount == 0) {
        cout << "No entries on file.\n";
        return;
    }

    for (int i = 0; i < patientCount; i++) { //for loop
        Patient &p = patients[i];
        cout << "\nID: " << p.id
             << "\nName: " << p.name
             << "\nAge: " << p.age
             << "\nGender: " << p.gender
             << "\nDiagnosis: " << p.diagnosis << "\n";
    }
}

int binarySearch(Patient patients[], int size, int searchID)
{
int left = 0; //first value in array is zero
int right = size - 1; //since it starts at zero the farthest value is size-1.
while (left <= right) //while left is less or equal to the right 
{
int mid = (left + right) / 2; //mid is set to (left + right)/2

if (patients[mid].id == searchID) {
return mid;
}

if (patients[mid].id < searchID) {
left = mid + 1;

}else {
right = mid - 1;
}
}
return -1;
}

void searchPatient() {
    if (patientCount == 0) {
        cout << "No entries on file.\n";
        return;
    }
    
    int searchID;
    cout << "Enter Patient ID to search: ";
    cin >> searchID;
    
    int result = binarySearch(patients, SIZE, searchID);
if (result != -1) {
    Patient &p = patients[result];
    cout << "\nPatient Found:\n";
            cout << "ID: " << p.id
                 << "\nName: " << p.name
                 << "\nAge: " << p.age
                 << "\nGender: " << p.gender
                 << "\nDiagnosis: " << p.diagnosis << "\n";
            return;
}
}
void updatePatient () { // overwrite not append
    //if (flag == true) {
    
    
}



//int count
//count++
void Menu() {
    cout << "\nHospital Patient System\n1. Add patient\n2. Display Patient\n3. Search Patient\n";
    cout << "4. Update Patient\n5. Exit\nEnter choice: ";
}


 int main() {
    int choice;
    Patient guide;
    do { //Add, Display, Search, Update, Exit
    Menu();
    cin >> choice;
    if (choice==1) {
        addPatient(); //clear
       // y.saveToFile(); //copies to the file, rework after update gets finished.
    }
    else if (choice==2) { //clear
        displayPatient();
    }
    else if (choice==3) { //current
        searchPatient();
    }
    else if (choice==4) { //after
       updatePatient();
    }
   }while(choice !=5); //clear
   cout << "\nFeel free to try again later.";
   //Exit();
   return 0;
}