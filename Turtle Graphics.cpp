//includes and constants-----
#include <iostream>
#include <fstream>
using namespace std;
const int WIDTH = 20;
const int HEIGHT = 20;
//---------------------------
//(class?) variable-
int turtleFace = 0;
//------------------

void DisplayBoard(char pArray[HEIGHT][WIDTH], bool ppPen) {
    //iterate line by line to print out all the data in the array
    //-----------------------------------
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
        {
            cout << pArray[i][j] << ' ';
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
    if (ppPen) {
        cout << "The pen is down" << endl;
    }
    else {
        cout << "The pen is up" << endl;
    }
}
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
    cout << "3 to save instructions" << endl;
    cout << "4 to load instructions" << endl;
    cout << "5 to toggle the pen" << endl;
    cout << "6 to move forward" << endl;
    cout << "7 to rotate counterclockwise" << endl;
    cout << "8 to rotate clockwise" << endl;
    cout << "9 to reset the turtle" << endl;
    cout << "10 to end the program" << endl;
    //---------------------------------------------
    //Get user input---------------------------------------------
    while (!(cin.fail()) && selection < 0 || selection > 10) {
        cin >> selection;
        if (cin.fail() || selection < 0 || selection > 10) {
            cout << "Invalid, please try again." << endl;
        }
    }
    //-----------------------------------------------------------
    return selection;
}
void Rotate(int rotBy) {
    //passes in a number and adds it to the turtle face (class?) variable
    turtleFace += rotBy;
    //check for overflow----------- 
    if (turtleFace == 4) {
        turtleFace = 0;
    }
    else if (turtleFace == -1) {
        turtleFace = 3;
    }
    //-----------------------------
    //cout << "turtle facing " << turtleFace << endl; //debug line
}

void MoveForward(char ppBoard[HEIGHT][WIDTH], bool ppPen, int ppTurtLOC[2]) {
    bool validCheck = true;
    int distance = 0;
    while (validCheck) {
        cout << "How far do you want to move? " << endl;
        cin >> distance;
        
    }
}
void processRouter(int pUserSel, char pBoard[HEIGHT][WIDTH], bool& pPen, int pTurtLOC[2]) {
    //compare the selection from the user to actions in the switch
    switch (pUserSel)
    {
    case 1: //draw board
        DisplayBoard(pBoard, pPen);
        break;
    case 2: //save the board and descriptions to file
        //SaveBoard(pBoard);
        break;
    case 3: //save the instructions to file
        //SaveInstructions();
        break;
    case 4: //load instructions from file
        //LoadInstructions();
        break;
    case 5: //toggle the pen
        pPen = !(pPen);
        break;
    case 6: //move the turtle forward, drawing or not drawing based on the pen
        MoveForward(pBoard, pPen, pTurtLOC);
        break;
    case 7: //rotate counterclockwise
        Rotate(-1);
        break;
    case 8: //rotate clockwise
        Rotate(1);
        break;
    case 9: //move the turtle to 0,0 and clear the board
        BuildBoard(pBoard);
        pTurtLOC[0] = 0;
        pTurtLOC[1] = 0;
        pPen = 0;
        break;
    case 10: //end the program
        exit(0);
        break;
    default: //shouldn't do anything, but just in *case*
        cout << "Something went wrong!" << endl;
        break;
    }
    return;
}



int main() {
    //Declare variables----------
    bool penTgl = false; //whether the pen is up or down. false is up
    int turtleLOC[2] = { 0,0 }; //represents the location of the turtle in the board
    char board[HEIGHT][WIDTH]; //board, what else?
    int userSel = 0; //Just initializing which option the user will select
    //---------------------------

    //run startup functions--
    BuildBoard(board); //pass in the board so that it can be populated
    DisplayBoard(board, penTgl); //pass in the board for display (might be commented out in the end)
    //-----------------------
  

    //Infinite loop that exits when the user uses 10, I noticed many graphical apps use this method, such as Tkninter for Python
    while (true) {
        userSel = Options(); //gets the the command the user wants
        processRouter(userSel, board, penTgl, turtleLOC); //decides which functions to call
    }


}
