#include <iostream>
#include <fstream>
using namespace std;


class Chessboard {
private:
    int array[4][4]; //protection of the game board

public:
    int x, y;
    int space, contact, placement, chance, attempt, end;

Chessboard() {
        placement = 0; // keeps track of queens count on board
        chance = 2; // failsafe measure
        attempt = 0; // saved to file to keep track of attempts to solve the puzzle
        end = 0; //ends program when set to 1
    }

void setArray() {
        for (int i = 0; i < 4; i++) // for loop that repeats for times that initializes the array
            for (int j = 0; j < 4; j++) //for loop into 4 loop is 16 iterations which is exactly the matrix I'm aiming
                array[i][j] = 0; //Sets each placement to 0
    }

void saveToFile() {
        ofstream out("Score.txt", ios::app); //appends the Score.txt
        if (out.is_open()) { // If so that User is aware if the file is opened or not
            out << attempt << " Stage 1" << endl; //Places attempt count and stage based on user capabilities
            out.close();
            cout << "Attempt count added to file.\n"; //Inform user
        } else {
            cout << "Error\n";
        }
    }

void checkSpace() { //Point of this function is to set a loop later that continues if there are open areas.
        space = 0; //this prevents errors such that space = 1 only is set to 1 when rest of the function is through
        for (int i = 0; i < 4; i++) 
            for (int j = 0; j < 4; j++) //checks matrix for 0's to determine space.
                if (array[i][j] == 0)
                    space = 1;
    }

void noContact(int x, int y) {
        if (x < 0 || x > 3 || y < 0 || y > 3) { //prevents out of bound coordinates that can cause errors.
            cout << "Out of bounds\n";
            contact = 0;
            return;
        }

        contact = (array[x][y] == 0); //Simplification of 2nd essential part
        //After checking if there's spaces then you check if the selected coordinates are actual free.
    }

void Queen() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if ((i - x == j - y) || (i - x == -(j - y)) || i == x || j == y) { //explained in the power point
                    array[i][j] = 1; //This combines the queen placement and its line of fire
                }
            }
        }
    }

void checkChances() { //in powerpoint
        if (chance == 0) {
            attempt += 1;
            end = 1;
        }
    }

void userInput() { //heart of the code
        checkChances(); 
        checkSpace(); //grabs what variable is stored at space, needed below

        if (space == 1) { //takes user input if there is space
            cout << "\nInput x coordinate: ";
            cin >> x;
            cout << "Input y coordinate: ";
            cin >> y;

            noContact(x, y); //checks if the coordinates are legal

            if (contact == 1) { //after check if it passes runs the Queen function
                Queen();
                placement += 1;
                displayBoard();
            } else { //starts eating up chances
                cout << "Occupied position, invalid coordinates.\n";
                chance -= 1;
            }
        }
    }

void displayBoard() { //most important in coordinate setting otherwise y-values are inverted.
        for (int j = 3; j >= 0; j--) {
            for (int i = 0; i < 4; i++) {
                cout << array[i][j];
            }
            cout << endl;
        }
    }
};

//2nd class with standard 8 by 8 board
//Code is repeated from this point onward with minor changes

class Chessboard2 {
private:
    int array[8][8]; //protection of the game board

public:
    int x, y;
    int space, contact, placement, chance, attempt, end;

    Chessboard2() {
        placement = 0;
        chance = 5;
        attempt = 0;
        end = 0;
    }

void setArray() {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                array[i][j] = 0;
    }

void checkSpace() {
        space = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (array[i][j] == 0)
                    space = 1;
    }

void noContact(int x, int y) {
        if (x < 0 || x > 7 || y < 0 || y > 7) {
            cout << "Out of bounds\n";
            contact = 0;
            return;
        }

        contact = (array[x][y] == 0);
    }

void Queen() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((i - x == j - y) || (i - x == -(j - y)) || i == x || j == y) {
                    array[i][j] = 1;
                }
            }
        }
    }

void checkChances() {
        if (chance == 0) {
            attempt += 1;
            end = 1;
        }
    }

void userInput() {
        checkChances();
        checkSpace();

        if (space == 1) {
            cout << "\nInput x coordinate: ";
            cin >> x;
            cout << "Input y coordinate: ";
            cin >> y;

            noContact(x, y);

            if (contact == 1) {
                Queen();
                placement += 1;
                displayBoard();
            } else {
                cout << "Occupied position, invalid coordinates.\n";
                chance -= 1;
            }
        }
    }

void displayBoard() {
        for (int j = 7; j >= 0; j--) {
            for (int i = 0; i < 8; i++) {
                cout << array[i][j];
            }
            cout << endl;
        }
    }
};


int main() {

    char stage; //in powerpoint
    char iteration;

    Chessboard c1;
    Chessboard2 c2;

    c1.setArray();
    c1.checkSpace();

    while (c1.space == 1 && c1.end == 0) {
        c1.userInput();
    }

    if (c1.placement == 4) {

        cout << "\nBravo. Continue to the 8 Queens?\n";
        cout << "(y/n): ";

        cin >> stage;

    switch(stage) { //switch case execution that allows user decision to continue to 8 queens

    case 'y':

                c2.setArray();
                c2.checkSpace();

                while (c2.space == 1 && c2.end == 0) {
                    c2.userInput();
                }

                if (c2.placement == 8) {

                    cout << "\nPuzzle completed.\n";

                } else {

                    cout << "\nNot as easy as the 4 by 4.\n";
                }

                break;

        case 'n':

                cout << "\nClosing program.\n";
                break;

        default: //takes care of inputs outside of the given options

                cout << "\nInvalid input.\n";
        }
    }

    else if (c1.end == 1) { //Alternate ending if misinputs forces an early closure.

        cout << "Failed Queen placement due to coordinate misinput\n";

        c1.attempt += 1;

        c1.saveToFile();

        cout << "Try again? (y/n): ";
        cin >> iteration;

        switch(iteration) {

        case 'y':

                main(); //returns to to top of int main(); to begin program again
                break;

        case 'n':

                cout << "\nClosing program.\n";
                break;

        default:

                cout << "\nInvalid input.\n";
        }
    }

    else {

        cout << "You couldn't place 4 queens on the board.\n";
        cout << "Try again? (y/n): ";

        cin >> iteration; //Same event situation slight difference, this case is a normal loss meaning less than 4 queens

        c1.attempt += 1;

        c1.saveToFile();

        switch(iteration) {

        case 'y':

                main();
                break;

        case 'n':

                cout << "\nClosing program.\n";
                break;

        default:

                cout << "\nInvalid input.\n";
        }
    }

    return 0;
}
//change above with formula given, position, xy. x+y & x-y (take absolute value) numbers have to be less than 8
// (x-i)+ (y-j) =0 and (x-i) - (y -j) = 0 bishop
//|x2−x1|=|y2−y1|>0 this formula determines if a bishop made a legal move. Both formulas are the same
//x & y is piece coordinates, i & j is square being analyzed


//Next step is to combine diagonals with the columns & rows
//If the array has a 1 then you cannot select coordinates to place a queen 
//If the board is filled then you have to retry.
//If 4 coordinates have been chosen without retrying copy to a file and increase difficulty or something. 