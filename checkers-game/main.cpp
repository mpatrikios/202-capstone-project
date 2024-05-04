#include "Checkers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//are we asking if they want to jump or just jumping for them?

using namespace std;

//Converts given string into a number that represents the direction (ex: FR to 0)
int convertString(string inputDirection, int counter) {
    int direction = -1;

    if (counter % 2 == 0) { //different directions for X
        if (inputDirection == "FR") {
            direction = 0;
        } 
        else if (inputDirection == "FL") {
            direction = 1;
        } 
        else if (inputDirection == "BL") {
            direction = 2;
        } 
        else if (inputDirection == "BR") {
            direction = 3;
        } 
        else if (inputDirection == "JFR") {
            direction = 4;
        } 
        else if (inputDirection == "JFL") {
            direction = 5;
        } 
        else if (inputDirection == "JBL") {
            direction = 6;
        } 
        else if (inputDirection == "JBR") {
            direction = 7;
        }     
        else {
            direction = -1;
        }
    }
    
    //Different directions for O
    else {
        if (inputDirection == "FR") {
            direction = 1;
        } 
        else if (inputDirection == "FL") {
            direction = 0;
        } 
        else if (inputDirection == "BL") {
            direction = 3;
        } 
        else if (inputDirection == "BR") {
            direction = 2;
        } 
        else if (inputDirection == "JFR") {
            direction = 5;
        } 
        else if (inputDirection == "JFL") {
            direction = 4;
        } 
        else if (inputDirection == "JBL") {
            direction = 7;
        } 
        else if (inputDirection == "JBR") {
            direction = 6;
        } 
        else {
            direction = -1;
        }
    }
    return direction;
}


int main() {
    int i, j, direction; //i: row, j: column, direction: direction of move
    string inputDirection; //User input
    Checkers game; //Create Checkers object
    vector <int> jumpAgainOptions; //Available jump options after jump
    
    game.printBoard(); //print the board after setup

    //Explain UI
    cout << "Welcome to Checkers! The direction you would like to move corresponds to the following:" << endl; 
    cout << "FR - front right" << endl;
    cout << "FL - front left" << endl;
    cout << "BL - back left " << endl;
    cout << "BR - back right " << endl;
    cout << "JFR - jump front right" << endl;
    cout << "JFL - jump front left" << endl;
    cout << "JBL - jump back left" << endl;
    cout << "JBR - jump back right" << endl;
    cout << "Player 1 will be X's and Player 2 will be O's. Enter 'Q' to quit the game." << endl;
    
    //Game loop
    while (!game.checkWinner()) {
        i = -1; //If i is -1 at the end, the user wants to quit
        
        //Print the board and prompt the user for input
        cout << endl;
        game.printBoard();
        cout  << endl;
        cout << "Player " << (game.getCounter() % 2 == 0 ? 1 : 2) << "'s turn. Which piece would you like to move [row column direction] ('Q' to quit): ";

        // Read in i, j, and inputDirection
        cin >> i >> j >> inputDirection;
        // cout << i << j << inputDirection << endl;

        if (i == -1) { // Check for quit option
            game.checkBoard();
            cout << " Thanks for playing!" << endl;
            break;
        }

        // Convert input direction to integer    
        direction = convertString(inputDirection, game.getCounter());
    
        //Checks if direction will segfault
        if (direction < 0 || direction > 8) {
            cout << "Invalid direction. Try again." << endl;
            continue; // Go back to the start of the loop to prompt for valid input
        }

        // Checks if input provided was valid, else restarts loop    
        if (!game.validateInput(i, j, direction)) {
            continue; // Go back to the start of the loop to prompt for valid input
        }
    
        // Validate move or jump
        //not jumping so just check if it is a valid move
        if (direction < 4) { 

            //If move is valid then move piece
            if (game.isValidMove(i, j, direction)) { 
                game.movePiece(i, j, direction);
                game.Board[i][j] = game.makeKing(i, game.Board[i][j]); //check if piece is a king
            } 
            
            //Else restart loop
            else {
                cout << "Invalid move. Try again." << endl;
                continue; // Go back to the start of the loop to prompt for valid input
            }
        } 
        
        //else it is a jump so check for valid jump
        else { 

            //check if it is a valid jump
            if (game.isValidJump(i, j, direction)){ 
                game.jump(i, j, direction);
                game.Board[i][j] = game.makeKing(i, game.Board[i][j]); //check if piece is a king
            } 

            //Else restart loop
            else {
                cout << "Invalid jump. Try again." << endl;
                continue; // Go back to the start of the loop to prompt for valid input
            }

            //Check if the piece is a king, if so, add backwards jumps checks       
            int loopEnd = 6;
            if(game.Board[i][j] == 'X' || game.Board[i][j] == 'O'){
                loopEnd = 8;
            }

            //check which jumps are available and adds them to list    
            for (int d = 4; d < loopEnd; d++){ 
                //If jump is valid then add to vector
                if(game.isValidJump(i, j, d)){
                    jumpAgainOptions.push_back(d); //add possible jumps to a vector
                }
            }
            

            //if there are options and X is playing
            if (jumpAgainOptions.size() != 0){    
                game.printBoard(); //print the board 
                cout << "Would you like to jump again? (Y/N): ";
                char jumpAgain = 'a';
            
                //Take input from user
                cin >> jumpAgain;
                
                //If input is invalid, ask again
                while (jumpAgain != 'Y' && jumpAgain != 'y' && jumpAgain != 'N' && jumpAgain != 'n') {
                    cout << "Invalid input - please enter 'Y' or 'N'" << endl;
                    cin >> jumpAgain;
                }

                //if they want to jump again list their options
                if((jumpAgain == 'Y' || jumpAgain == 'y') && game.getCounter() % 2 == 0){ 
                    
                    cout << "Which direction would you like to jump? Your options are: ";
            
                    for(int d = 0; d < jumpAgainOptions.size(); d++){        
                        if (jumpAgainOptions[d] == 4) {
                            cout << "JFR ";
                        } 
                
                        else if (jumpAgainOptions[d] == 5) {
                            cout << "JFL ";
                        } 
                
                        else if (jumpAgainOptions[d] == 6) {
                            cout << "JBL ";
                        } 
                
                        else if (jumpAgainOptions[d] == 7) {
                            cout << "JBR ";
                        }
                    } 
                
                    cout << endl << "Enter your choice: "; //ask for their choice

                    //Take input and convert to direction
                    cin >> inputDirection;
                    direction = convertString(inputDirection, game.getCounter()); 
                    game.jump(i, j, direction); //jump 
                    game.Board[i][j] = game.makeKing(i, game.Board[i][j]); //check if piece is a king
                } 

                //options for O to jump again
                if((jumpAgain == 'Y' || jumpAgain == 'y') && game.getCounter() % 2 == 1){ 
                    
                    cout << "Which direction would you like to jump? Your options are: ";
            
                    for(int d = 0; d < jumpAgainOptions.size(); d++){        
                        if (jumpAgainOptions[d] == 5) {
                            cout << "JFR ";
                        } 
                
                        else if (jumpAgainOptions[d] == 4) {
                            cout << "JFL ";
                        } 
                
                        else if (jumpAgainOptions[d] == 7) {
                            cout << "JBL ";
                        } 
                
                        else if (jumpAgainOptions[d] == 6) {
                            cout << "JBR ";
                        }
                    } 
                
                    cout << endl << "Enter your choice: "; //ask for their choice

                    //Take input and convert to direction
                    cin >> inputDirection;
                    direction = convertString(inputDirection, game.getCounter()); 
                    game.jump(i, j, direction); //jump 
                    game.Board[i][j] = game.makeKing(i, game.Board[i][j]); //check if piece is a king
                } 
                
                else if (jumpAgain == 'N' || jumpAgain == 'n') //if they don't want to jump again
                { 
                    game.incrementCounter(); //increment the counter
                } 
            }
        }
        game.incrementCounter();

        if (game.checkWinner()) 
        {
            game.checkBoard();
            cout << endl << "Player 1 had " << game.getScore1() << " points and Player 2 had " << game.getScore2() << " points." << endl;
            break;
        }
    }
    return 0;
}