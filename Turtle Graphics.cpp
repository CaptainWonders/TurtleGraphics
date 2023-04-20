//includes and constants-----
#include <iostream>
#include <fstream>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
const short EAST = 0;
const short SOUTH = 1;
const short WEST = 2;
const short NORTH = 3;
//---------------------------



void BuildBoard(char bbBoard[HEIGHT][WIDTH]) {
    //iterate line by line and fill them with dashes to represent empty space
    //------------------------------------
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
        {
            bbBoard[j][i] = '-';
        }
    }
    //------------------------------------
    
}


void DisplayBoard(char dbBoard[HEIGHT][WIDTH], bool dbPen, int dbTurtleX, int dbTurtleY, int dbTurtleFace) {
    //iterate line by line to print out all the data in the array
    //-----------------------------------
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
        {
            cout << dbBoard[i][j] << ' ';
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


int Options() {
    //print all the options out and get which one the user wants
    int selection = -1;
    //print----------------------------------------
    cout << "0 to load instructions" << endl;
    cout << "1 to pick up the pen" << endl;
    cout << "2 to put down the pen" << endl;
    cout << "3 to rotate clockwise" << endl;
    cout << "4 to rotate counterclockwise" << endl;
    cout << "5 to move forward" << endl;
    cout << "6 to display board" << endl;
    cout << "7 to save board" << endl;
    cout << "8 to reset the turtle and clear the board" << endl;
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

void SaveBoard(char sbBoard[HEIGHT][WIDTH], bool sbPen, int sbTurtleX, int sbTurtleY, int sbTurtleFace) {
    string fileLocation;
   
    cout << "Please enter your file destination (Without a file extension): ";
    cin >> fileLocation;

    ofstream saveFile(fileLocation + ".txt");
    if (saveFile.is_open())
    {
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j)
            {
                saveFile << sbBoard[i][j];
            }
            saveFile << '\n';
        }
        //Print out the turtle's facing-------------------
        if (sbTurtleFace == EAST) {
            saveFile << "The turtle is facing east" << endl;
        }
        else if (sbTurtleFace == SOUTH) {
            saveFile << "The turtle is facing south" << endl;
        }
        else if (sbTurtleFace == WEST) {
            saveFile << "The turtle is facing west" << endl;
        }
        else {
            saveFile << "The turtle is facing north" << endl;
        }
        //-------------------------------------------------
        //Print out the pen state---------------
        if (sbPen) {
            saveFile << "The pen is down" << endl;
        }
        else {
            saveFile << "The pen is up" << endl;
        }
        //--------------------------------------
        //print out the turtle location---------------
        saveFile << "The turtle is at: " << sbTurtleX << ',' << sbTurtleY << endl;
        //--------------------------------------------
        saveFile.close();
    }
    else {
        cout << "Unable to generate file";
    }
}

void MoveForward(char mfBoard[HEIGHT][WIDTH], bool mfPen, int& mfTurtleX, int& mfTurtleY, int mfTurtleFace, int mfDistance) {
    //supposed to end the while loop when a successful iteration happens

    switch (mfTurtleFace) {
    case 0: //east
        //check if the turtle can go that far--------
        if (WIDTH - mfTurtleX > mfDistance) {
            for (int i = 0; i < mfDistance; i++) {
                mfTurtleX++;
                if (mfPen) {
                    mfBoard[mfTurtleY][mfTurtleX] = '*';
                }
            }
                //exits the while loop
        }
        else {
            cout << "That is too far given the direction" << endl;
        }
        //-------------------------------------------
        break;
    case 1: //south
        //check if the turtle can go that far--------
        if (HEIGHT - mfTurtleY > mfDistance) {
            for (int i = 0; i < mfDistance; i++) {
                mfTurtleY++;
                if (mfPen) {
                    mfBoard[mfTurtleY][mfTurtleX] = '*';
                }
            }
                
        }
        else {
            cout << "That is too far given the direction" << endl;
        }
        //-------------------------------------------
        break;
    case 2: //west
        //check if the turtle can go that far--------
        if (mfTurtleX > mfDistance) {
            for (int i = 0; i < mfDistance; i++) {
                mfTurtleX--;
                if (mfPen) {
                    mfBoard[mfTurtleY][mfTurtleX] = '*';
                }
            }
                
        }
        else {
            cout << "That is too far given the direction" << endl;
        }
        //-------------------------------------------
        break;
    case 3: //north
        //check if the turtle can go that far--------
        if (mfTurtleY > mfDistance) {
            for (int i = 0; i < mfDistance; i++) {
                mfTurtleY--;
                if (mfPen) {
                    mfBoard[mfTurtleY][mfTurtleX] = '*';
                }
            }
                
        }
        else {
            cout << "That is too far given the direction" << endl;
        }
        //-------------------------------------------
        break;
    }
}

void LoadInstructions(char liBoard[HEIGHT][WIDTH], bool& liPen, int& liTurtleX, int& liTurtleY, int& liTurtleFace) {

    string fileLocation; //holds the filepath
    bool keepGoing = true; //for ending the while loop if the instructions contain an end instruction
    int nextInstruction; //contains the instruction from the file

    //prompt the user for the instruction file path---
    cout << "Please enter your file source: ";
    cin >> fileLocation;
    ifstream loadInstruction(fileLocation); //define file object
    //------------------------------------------------

    while (loadInstruction.good() && keepGoing) {
        loadInstruction >> nextInstruction; //load the instruction we care about
        //cout << nextInstruction << endl; //debug line

        //blatently stolen from ProcessRouter-------------------------------------------
        switch (nextInstruction)
        {
        case 0: //load instructions from file
            cout << "You cannot load instructions while loading instructions" << endl; //cease the wierd ahh hack
            break;
        case 1: //turn off yo pen
            liPen = false;
            break;
        case 2: //turn on yo pen
            liPen = true;
            break;
        case 3: //rotate clockwise
            Rotate(1, liTurtleFace);
            break;
        case 4: //rotate counterclockwise
            Rotate(-1, liTurtleFace);
            break;
        case 5: //move the turtle forward, drawing or not drawing based on the pen
            loadInstruction >> nextInstruction; //grab the next load instruction in the file for the amount to move
            MoveForward(liBoard, liPen, liTurtleX, liTurtleY, liTurtleFace, nextInstruction);
            break;
        case 6: //draw board
            DisplayBoard(liBoard, liPen, liTurtleX, liTurtleY, liTurtleFace);
            break;
        case 7: //save the board and descriptions to file
            SaveBoard(liBoard, liPen, liTurtleX, liTurtleY, liTurtleFace);
            break;
        case 8: //move the turtle to 0,0 and clear the board
            BuildBoard(liBoard);
            liTurtleY = 0;
            liTurtleX = 0;
            liPen = 0;
            break;
        case 9: //end the program
            keepGoing = false;
            break;
        default: //shouldn't do anything, but just in *case*
            cout << "Invalid instruction" << endl;
            break;
        }
        //------------------------------------------------------------------------------
    }
    loadInstruction.close(); //just in case
}

bool ProcessRouter(int prUserSel, char prBoard[HEIGHT][WIDTH], bool& prPen, int& prTurtleX, int& prTurtleY, int& prTurtleFace) {
    int movDistance = 0;
    bool exitCheck = true;
    //compare the selection from the user to actions in the switch
    switch (prUserSel)
    {
    case 0: //load instructions from file
        LoadInstructions(prBoard, prPen, prTurtleX, prTurtleY, prTurtleFace);
        return true;
    case 1: //turn off yo pen
        prPen = false;
        return true;
    case 2: //turn on yo pen
        prPen = true;
        return true;
    case 3: //rotate clockwise
        Rotate(1, prTurtleFace);
        return true;
    case 4: //rotate counterclockwise
        Rotate(-1, prTurtleFace);
        return true;
    case 5: //move the turtle forward, drawing or not drawing based on the pen
        while (cin.fail() || exitCheck) {
            cin.clear();
            cin.ignore(255, '\n');
            cout << "How far do you want to move? " << endl;
            cin >> movDistance;
            exitCheck = false;
        }
        MoveForward(prBoard, prPen, prTurtleX, prTurtleY, prTurtleFace, movDistance);
        return true;
    case 6: //draw board
        DisplayBoard(prBoard, prPen, prTurtleX, prTurtleY, prTurtleFace);
        return true;
    case 7: //save the board and descriptions to file
        SaveBoard(prBoard, prPen, prTurtleX, prTurtleY, prTurtleFace);
        return true;
    case 8: //move the turtle to 0,0 and clear the board
        BuildBoard(prBoard);
        prTurtleY = 0;
        prTurtleX = 0;
        prPen = 0;
        prTurtleFace = 0;
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
    bool pen = false; //whether the pen is up or down. false is up
    bool keepGoing = true; //whether the process keeps going
    char board[HEIGHT][WIDTH]; //board, what else?
    int userSel = 0; //Just initializing which option the user will select
    int turtleFace = EAST; //represents the facing of the turtle
    int turtleY = 0;//represents the location of the turtle in the board
    int turtleX = 0;//this too
    //---------------------------

    //run startup functions--
    BuildBoard(board); //pass in the board so that it can be populated
    DisplayBoard(board, pen, turtleX, turtleY, turtleFace); //pass in the board for display (might be commented out in the end)
    //-----------------------
  

    //Not quite infinite loop that exits when the user uses 9, I noticed many graphical apps use this method, such as Tkninter for Python
    while (keepGoing) {
        userSel = Options(); //gets the the command the user wants
        keepGoing = ProcessRouter(userSel, board, pen, turtleX, turtleY, turtleFace); //decides which functions to call
    }


}
