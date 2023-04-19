//includes and constants-----
#include <iostream>
#include <fstream>
using namespace std;
const int WIDTH = 20;
const int HEIGHT = 20;
//---------------------------
//(class?) variable-
int turtleFace = 0; //represents the facing of the turtle
//represents the location of the turtle in the board
int turtleY = 0;
int turtleX = 0;
//------------------


void BuildBoard(char pArray[HEIGHT][WIDTH]) {
    //iterate line by line and fill them with dashes to represent empty space
    //------------------------------------
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
        {
            pArray[i][j] = '-';
        }
    }
    //------------------------------------
    
}
int Options() {
    //print all the options out and get which one the user wants
    int selection = -1;
    //print----------------------------------------
    cout << "1 to display board" << endl;
    cout << "2 to save board" << endl;
    cout << "3 to load instructions" << endl;
    cout << "4 to toggle the pen" << endl;
    cout << "5 to move forward" << endl;
    cout << "6 to rotate counterclockwise" << endl;
    cout << "7 to rotate clockwise" << endl;
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
void Rotate(int rotBy) {
    //passes in a number and adds it to the turtle face variable
    turtleFace += rotBy;
    //check for overflow----------- 
    if (turtleFace == 4) {
        turtleFace = 0;
    }
    else if (turtleFace == -1) {
        turtleFace = 3;
    }
    //-----------------------------
}

void MoveForward(char ppBoard[HEIGHT][WIDTH], bool ppPen) {
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
        switch (turtleFace) {
        case 0: //east
            //check if the turtle can go that far--------
            if (WIDTH - turtleX > distance) {
                for (int i = 0; i < distance; i++) {
                    turtleX++;
                    if (ppPen) {
                        ppBoard[turtleX][turtleY] = '*';
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
            if (HEIGHT - turtleY > distance) {
                for (int i = 0; i < distance; i++) {
                    turtleY++;
                    if (ppPen) {
                        ppBoard[turtleX][turtleY] = '*';
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
            if (turtleX > distance) {
                for (int i = 0; i < distance; i++) {
                    turtleX--;
                    if (ppPen) {
                        ppBoard[turtleX][turtleY] = '*';
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
            if (turtleY > distance) {
                for (int i = 0; i < distance; i++) {
                    turtleY--;
                    if (ppPen) {
                        ppBoard[turtleX][turtleY] = '*';
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

void DisplayBoard(char pBoard[HEIGHT][WIDTH], bool ppPen) {
    //iterate line by line to print out all the data in the array
    //-----------------------------------
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
        {
            cout << pBoard[j][i] << ' ';
        }
        cout << "\n";
    }
    //------------------------------------
    //Print out the turtle's facing-------------------
    if (turtleFace == 0) {
        cout << "The turtle is facing east" << endl;
    }
    else if (turtleFace == 1) {
        cout << "The turtle is facing south" << endl;
    }
    else if (turtleFace == 2) {
        cout << "The turtle is facing west" << endl;
    }
    else {
        cout << "The turtle is facing north" << endl;
    }
    //-------------------------------------------------
    //Print out the pen state---------------
    if (ppPen) {
        cout << "The pen is down" << endl;
    }
    else {
        cout << "The pen is up" << endl;
    }
    //--------------------------------------
    //print out the turtle location---------------
    cout << "The turtle is at: " << turtleX << ',' << turtleY << endl;
    //--------------------------------------------
}

bool ProcessRouter(int pUserSel, char pBoard[HEIGHT][WIDTH], bool& pPen) {
    //compare the selection from the user to actions in the switch
    switch (pUserSel)
    {
    case 1: //draw board
        DisplayBoard(pBoard, pPen);
        return true;
    case 2: //save the board and descriptions to file
        //SaveBoard(pBoard);
        return true;
    case 3: //load instructions from file
        //LoadInstructions();
        return true;
    case 4: //toggle the pen
        pPen = !(pPen);
        return true;
    case 5: //move the turtle forward, drawing or not drawing based on the pen
        MoveForward(pBoard, pPen);
        return true;
    case 6: //rotate counterclockwise
        Rotate(-1);
        return true;
    case 7: //rotate clockwise
        Rotate(1);
        return true;
    case 8: //move the turtle to 0,0 and clear the board
        BuildBoard(pBoard);
        turtleY = 0;
        turtleX = 0;
        pPen = 0;
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
    //---------------------------

    //run startup functions--
    BuildBoard(board); //pass in the board so that it can be populated
    DisplayBoard(board, penTgl); //pass in the board for display (might be commented out in the end)
    //-----------------------
  

    //Not quite infinite loop that exits when the user uses 9, I noticed many graphical apps use this method, such as Tkninter for Python
    while (keepGoing) {
        userSel = Options(); //gets the the command the user wants
        keepGoing = ProcessRouter(userSel, board, penTgl); //decides which functions to call
    }


}
