//includes and constants-----
#include <iostream>
#include <fstream>
using namespace std;
const int WIDTH = 20;
const int HEIGHT = 20;
//---------------------------



void BuildBoard(char bbBoard[HEIGHT][WIDTH]) {
    //iterate line by line and fill them with dashes to represent empty space
    //------------------------------------
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
        {
            bbBoard[i][j] = '-';
        }
    }
    //------------------------------------
    
}
int Options() {
    //print all the options out and get which one the user wants
    int selection = -1;
    //print----------------------------------------
    cout << "0 to load instructions" << endl;
    cout << "1 to rotate counterclockwise" << endl;
    cout << "2 to rotate clockwise" << endl;
    cout << "3 to pick up the pen" << endl;
    cout << "4 to put down the pen" << endl;
    cout << "5 to move forward" << endl;
    cout << "6 to display board" << endl;
    cout << "7 to save board" << endl;
    cout << "8 to reset the turtle" << endl;
    cout << "9 to end the program" << endl;
    //---------------------------------------------
    //Get user input---------------------------------------------
    while (!(cin.fail()) && selection < 0 || selection > 9) {
        cin >> selection;
        if (cin.fail() || selection < 0 || selection > 9) {
            cout << "Invalid, please try again." << endl;
        }
    }
    //-----------------------------------------------------------
    return selection;
}
void Rotate(int rotBy, int& rTurtleFace) {
    //passes in a number and adds it to the turtle face variable
    rTurtleFace += rotBy;
    //check for overflow----------- 
    if (rTurtleFace == 4) {
        rTurtleFace = 0;
    }
    else if (rTurtleFace == -1) {
        rTurtleFace = 3;
    }
    //-----------------------------
}

void MoveForward(char mfBoard[HEIGHT][WIDTH], bool mfPen, int& mfTurtleX, int& mfTurtleY, int mfTurtleFace) {
    //supposed to end the while loop when a successful iteration happens
    bool exitCheck = true;
    //holds the distance the user wants to move
    int distance = 0;
    //keep going until valid input
    while (cin.fail() || exitCheck) {
        cin.clear();
        cin.ignore(255, '\n');
        cout << "How far do you want to move? " << endl;
        cin >> distance;
        switch (mfTurtleFace) {
        case 0: //east
            //check if the turtle can go that far--------
            if (WIDTH - mfTurtleX > distance) {
                for (int i = 0; i < distance; i++) {
                    mfTurtleX++;
                    if (mfPen) {
                        mfBoard[mfTurtleX][mfTurtleY] = '*';
                    }
                }
                exitCheck = false; //exits the while loop
            }
            else {
                cout << "That is too far given the direction" << endl;
            }
            //-------------------------------------------
            break;
        case 1: //south
            //check if the turtle can go that far--------
            if (HEIGHT - mfTurtleY > distance) {
                for (int i = 0; i < distance; i++) {
                    mfTurtleY++;
                    if (mfPen) {
                        mfBoard[mfTurtleX][mfTurtleY] = '*';
                    }
                }
                exitCheck = false; //exits the while loop
            }
            else {
                cout << "That is too far given the direction" << endl;
            }
            //-------------------------------------------
            break;
        case 2: //west
            //check if the turtle can go that far--------
            if (mfTurtleX > distance) {
                for (int i = 0; i < distance; i++) {
                    mfTurtleX--;
                    if (mfPen) {
                        mfBoard[mfTurtleX][mfTurtleY] = '*';
                    }
                }
                exitCheck = false; //exits the while loop
            }
            else {
                cout << "That is too far given the direction" << endl;
            }
            //-------------------------------------------
            break;
        case 3: //north
            //check if the turtle can go that far--------
            if (mfTurtleY > distance) {
                for (int i = 0; i < distance; i++) {
                    mfTurtleY--;
                    if (mfPen) {
                        mfBoard[mfTurtleX][mfTurtleY] = '*';
                    }
                }
                exitCheck = false; //exits the while loop
            }
            else {
                cout << "That is too far given the direction" << endl;
            }
            //-------------------------------------------
            break;
        }
    }
}

void DisplayBoard(char dbBoard[HEIGHT][WIDTH], bool dbPen, int dbTurtleX, int dbTurtleY, int dbTurtleFace) {
    //iterate line by line to print out all the data in the array
    //-----------------------------------
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
        {
            cout << dbBoard[j][i] << ' ';
        }
        cout << "\n";
    }
    //------------------------------------
    //Print out the turtle's facing-------------------
    if (dbTurtleFace == 0) {
        cout << "The turtle is facing east" << endl;
    }
    else if (dbTurtleFace == 1) {
        cout << "The turtle is facing south" << endl;
    }
    else if (dbTurtleFace == 2) {
        cout << "The turtle is facing west" << endl;
    }
    else {
        cout << "The turtle is facing north" << endl;
    }
    //-------------------------------------------------
    //Print out the pen state---------------
    if (dbPen) {
        cout << "The pen is down" << endl;
    }
    else {
        cout << "The pen is up" << endl;
    }
    //--------------------------------------
    //print out the turtle location---------------
    cout << "The turtle is at: " << dbTurtleX << ',' << dbTurtleY << endl;
    //--------------------------------------------
}

bool ProcessRouter(int prUserSel, char prBoard[HEIGHT][WIDTH], bool& prPen, int& prTurtleX, int& prTurtleY, int& prTurtleFace) {
    //compare the selection from the user to actions in the switch
    switch (prUserSel)
    {
    case 0: //load instructions from file
        //LoadInstructions();
        return true;
    case 1: //turn on yo pen
        prPen = true;
        return true;
    case 2: //turn off yo pen
        prPen = true;
        return true;
    case 3: //rotate clockwise
        Rotate(1, prTurtleFace);
        return true;
    case 4: //rotate counterclockwise
        Rotate(-1, prTurtleFace);
        return true;
    case 5: //move the turtle forward, drawing or not drawing based on the pen
        MoveForward(prBoard, prPen, prTurtleX, prTurtleY, prTurtleFace);
        return true;
    case 6: //draw board
        DisplayBoard(prBoard, prPen, prTurtleX, prTurtleY, prTurtleFace);
        return true;
    case 7: //save the board and descriptions to file
        //SaveBoard(pBoard);
        return true;
    case 8: //move the turtle to 0,0 and clear the board
        BuildBoard(prBoard);
        prTurtleY = 0;
        prTurtleX = 0;
        prPen = 0;
        return true;
    case 9: //end the program
        return false;
    default: //shouldn't do anything, but just in *case*
        cout << "Something went wrong!" << endl;
        return true;
    }
    
}



int main() {
    //Declare variables----------
    bool penTgl = false; //whether the pen is up or down. false is up
    bool keepGoing = true; //whether the process keeps going
    char board[HEIGHT][WIDTH]; //board, what else?
    int userSel = 0; //Just initializing which option the user will select
    int turtleFace = 0; //represents the facing of the turtle
    int turtleY = 0;//represents the location of the turtle in the board
    int turtleX = 0;//this too
    //---------------------------

    //run startup functions--
    BuildBoard(board); //pass in the board so that it can be populated
    DisplayBoard(board, penTgl, turtleX, turtleY, turtleFace); //pass in the board for display (might be commented out in the end)
    //-----------------------
  

    //Not quite infinite loop that exits when the user uses 9, I noticed many graphical apps use this method, such as Tkninter for Python
    while (keepGoing) {
        userSel = Options(); //gets the the command the user wants
        keepGoing = ProcessRouter(userSel, board, penTgl, turtleX, turtleY, turtleFace); //decides which functions to call
    }


}
