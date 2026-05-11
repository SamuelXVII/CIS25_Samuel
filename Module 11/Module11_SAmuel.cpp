#include <iostream>
#include <string>
using namespace std;

struct Patient
{
    int id,age;
    string name;
};

int main() {
    Patient patient1;
    patient1.id = 50;
    patient1.name = "Thragg";
    patient1.age = 2000;
    Patient*p = &patient1;


    //Pointer commands
    cout << "\nID: " << p->id << endl;
    cout << "Name: "<< p->name <<"\n";
    cout << "Age: "<< p->age <<"\n\n";
    return 0;
}