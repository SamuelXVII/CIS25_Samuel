#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Shopping cart class menu
//Option 1 is add item, user enters name/price/quantity, then save to cart.txt
//Option 2 is read from cart.txt, then multiply price & quantity displaying total. Then add all total variables

//read from cart.txt, showing price, quantity, total, & grand total

class item {
    public:
    string name; //name variable
    double price; //price variable
    int quantity; //amount of item
    double getTotalPrice() { //didn't use this variable anywhere.
        double total;
        total = price * quantity;
        return total;
    }
    void saveToFile() {
        ofstream out("cart.txt", ios::app); //opens file named item.txt, appends instead of overwrite
        if (out.is_open()) { //if file is open
            out << name << " " << price << " " << quantity << endl; //????
            out.close();
            cout << "Item successfully saved.\n";
        }
        else {
            cout << "Error\n";

        }
    } 
    //Option 1 is add item, user enters name/price/quantity, then save to cart.txt
    //Complete
    void Option1 () {
    cout << "Enter item name: ";
    cin >> name;
    cout << "\nEnter item price: ";
    cin >> price;
    cout << "\nEnter item quantity: ";
    cin >> quantity;
    cout << "\nItem added to cart.\n";
    //saveToFile();
}
//Option 2 is read from cart.txt, then multiply price & quantity displaying total. Then add all total variables
//
void Option2 () {
    double total = 0;
    double grandtotal = 0;
    ifstream in ("cart.txt");
    if (in.is_open()) { 
        cout << "===== CHECKOUT =====\n";
            while ( in >> name >> quantity >> price) { //reads data & sets them as variables, seperated by whitespace. Returns false if fields are missing.
            total = quantity * price; 
            grandtotal += total;
            cout << name << " - $" << price << " x " << quantity << " = " << total << endl;

         // add to running total
       } 
       cout << "-------------------\n";
       cout << "Total: $" << grandtotal << endl;
       in.close(); 
    }else { 
           cout << "Error\n" << endl; 
       }
}
};

void Menu() {
    cout << "\n===== SHOPPING CART MENU =====\n1. Add item to cart\n2. View checkout\n3. Exit\nChoose an option:";
}

void Exit() { //Option 3
    cout << "Thank you for shopping!\n";
}

int main() {
    int x;
    item y;
    do {
    Menu();
    cin >> x;
    if (x==1) {
        y.Option1();
        y.saveToFile(); //copies to the file
    }
    else if (x==2) {
        y.Option2();
    }
   }while(x !=3);
   
   Exit();
   return 0;
}

