#include <iostream>
using namespace std;


int main(void) 
{ 
	//added commas, and semicolon at the end. Matter of format
    float n1,n2,n3;
    cout << "\nEnter three numbers: \n";
    //Missing ">" symbol between each input & changed the extra 1 into 2
    cin >> n1 >> n2 >> n3;

    //changed "=" to ">=",
    if (n1>n2 && n1 >n3) {
        cout << "\nLargest number: " <<n1;
        
    }
    if (n1==n2 && n1 >n3) {
         cout << "\nLargest numbers are: " <<n1;
    }
    //changed "==" to ">=",
    if (n2>n1 && n2>n3) {
        //n1->n2,
        cout << "\nLargest number: " <<n2;
    }
    if (n2==n3 && n2 >n1) {
         cout << "\nLargest numbers are: \n" <<n2;
    }
    if (n3>n1 && n3>n2) {
        //n2->n3,
        cout << "\nLargest number: " <<n3;
    }
    if (n3==n1 && n1 >n2) {
         cout << "\nLargest numbers are: \n" <<n3;
    }
    else if (n1==n2 && n2==n3) {
    cout << "\nAll the numbers are the same. \n";
    }

	return 0; 
} 