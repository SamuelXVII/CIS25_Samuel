#include <iostream>
#include <string>
using namespace std;


class Product { //private by default
   int id;
   string name;
   float price;
public:
//Constructor
   Product(int i, string n, float p) 
      : id(i), name(n), price(p)
      {
      //id = i;
      //name = n;
      //price = p;
      cout << "\nConstructor called\n";
   }
~Product() {
   cout << "\nDestructor called\n";
}
void printDetails() {
   cout << "\nID: " << id << ", Name: "<< name << " Price: $" << price <<"\n";
}
};

int main() {
    Product p(77, "Beyblade", 19.99);
    p.printDetails();
    return 0;
}