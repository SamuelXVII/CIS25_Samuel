#include <iostream>
using namespace std;


int main(void) 
{ 
	int janus;
	cout << "\nOne of the choices has a not so secret message."; 
	cout << "\n\n1) Left door 2) Middle door 3) Right door\n"; 
	cout << "\nFeel free. \n"; 
	cin >> janus;

	if (janus == 1) cout << "\nTry the right door. \n\n"; 
	else if (janus == 2) cout << "\nFun fact: Monty hall is interesting, but it only works if agreed on beforehand. \n\n"; 
	else if (janus == 3) cout << "\nThis is the right door but it's not the right door. \n\n"; 
	else cout << "\n Reread the options carefully. \n\n"; 

	return 0; 
} 
