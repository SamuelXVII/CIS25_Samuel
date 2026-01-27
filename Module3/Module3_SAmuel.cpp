#include <iostream> 
using namespace std; 



int main(void) 
{ 
	
    //Three required variables for the assignment
    float price; 
    int numberOf; 
    string product; 
 
	cout << "\n\nWhat on your mind? Type in name of the product you would like to purchase. If the product has multiple words,"; 
    cout << " demarcate them with an underscore (_)\n"; 
	cin >> product; //The string variable doesn't store inputs with spaces
	cout << "How much would you like to buy? If just one, enter (1). \n"; 
	cin >> numberOf; 
	cout << "Can you tell me what price the item has? \n\n "; 
	cin >> price; 
 
	cout << "After buying " << numberOf << " "<< product << "(s).\n"; 
	cout << (price * numberOf) << "$ is your total for now.\n"; 
    return 0;
}  