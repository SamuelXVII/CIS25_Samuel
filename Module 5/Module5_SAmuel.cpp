#include <iostream>
#include <string>
using namespace std;

//3 options, Add to list & Display, Joke, Exit, which will print message.
//The list will be limited to 3 items max, 0-3.

//has to bring up menu after in each if statement
void Menu() {
    int x;
    cout << "\nAt List program, we have: \n1) Create list\n2) Hear joke \n3) End";
    cout << "\nPlease enter the numerical value correspondent to the option you wish to access.\n\n";
    
}
void joke() {
    cout << "Why did the chicken the road?\nIt wanted to know what all the jokes were about.\n";
    }

void addToList() {
    string a,b,c;
    cout << "\nWhat would you like to add to your list? (Maximum of three items)\n";
    cin >> a >> b >> c;
cout << "\nYou have completed your list\n"<< a <<", "<< b <<", "<< c <<"\nselect End to remake list.\n\n";
            return;
//list(a,b,c);

}

//No longer brings up menu, program closes
void End() {
    cout << "\nThis will clear your list. Thank you for your time.\n";
}

//DoWhile loops are 1 or more iterations that stop when condition is met
int main() 
{ 
    int x;
    string a,b,c;
    do {
        Menu();
        cin >> x;
        if (x==1) {
        addToList();
        
    }
    if (x==2) {
        joke();
    } 
    } while (x!=3);
    
    if (x==3) {
        End();

    }
    return 0;

}