#include <iostream>
#include <string>
#include <fstream>
#include <sstream> //parse csv by commas

using namespace std;
// 10 rows, 5 columns.
//Name, Stances, W/L/D. 
//10 fighters, 5 fields. Either we read across or we learn how to skip.
//We cout, Fighter uses this stance, with a record of, _ wins, _ losses, _draws.
//For loop, 10 times stops on 5th entry.
//class is required for assignment.
class Fighter {
    public:
    string name, stance, line; //name variable
    int weight, win,loss, draw; //weight variable
    
    void readFile () {
    ifstream ufc ("ufc.csv");
    if (ufc.is_open()) { 
        cout << "UFC Statistics\n";
            while (getline (ufc, line)) { 
            stringstream ss(line);           // create a stream from the line
            string newline;
            
        while (getline(ss, newline, ',')) {  // parse columns by comma
            cout << newline << '\n';
        }
            
               // cout << "Standing at "<< weight <<"lbs Fighter "<< name <<" uses "<< stance <<" with a record of,";
          //  cout << win <<" wins, "<< loss <<" losses, "<< draw <<" draws.\n\n";

        
       } 
       ufc.close(); 
    }else { 
           cout << "Error\n" << endl; 
       }
}
};

int main() {
    Fighter x;
            x.readFile();
    return 0;
}