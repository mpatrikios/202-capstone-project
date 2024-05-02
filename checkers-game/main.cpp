#include "Checkers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//are we asking if they want to jump or just jumping for them?

using namespace std;

int convertString(string inputDirection, int counter) {
    int direction;
   if (counter % 2 == 0) { //different directions for X
        if (inputDirection == "FR") {
        direction = 0;
    } else if (inputDirection == "FL") {
        direction = 1;
    } else if (inputDirection == "BL") {
        direction = 2;
    } else if (inputDirection == "BR") {
        direction = 3;
    } else if (inputDirection == "JFR") {
        direction = 4;
    } else if (inputDirection == "JFL") {
        direction = 5;
    } else if (inputDirection == "JBL") {
        direction = 6;
    } else if (inputDirection == "JBR") {
        direction = 7;
    } else {
       direction = -1;
    }
     }
    else {
    if (inputDirection == "FR") {
        direction = 1;
    } else if (inputDirection == "FL") {
        direction = 0;
    } else if (inputDirection == "BL") {
        direction = 3;
    } else if (inputDirection == "BR") {
        direction = 2;
    } else if (inputDirection == "JFR") {
        direction = 5;
    } else if (inputDirection == "JFL") {
        direction = 4;
    } else if (inputDirection == "JBL") {
        direction = 7;
    } else if (inputDirection == "JBR") {
        direction = 6;
    } else {
        direction = -1;
    }
    }
    return direction;
}


int main() {
    int i, j, direction;
    string inputDirection;
    Checkers game;
    vector <int> jumpAgainOptions;
    game.printBoard(); //create Checkers object and print the board
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
    while (!game.checkWinner()) {
        int i = -1;
        cout << endl;
        game.printBoard();
        cout << endl;
        cout << "Player " << (game.getCounter() % 2 == 0 ? 1 : 2) << "'s turn. Which piece would you like to move [row column direction] ('Q' to quit): ";
        cout << endl;

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
    if (direction < 0 || direction > 8) {
        cout << "Invalid direction. Try again." << endl;
        continue; // Go back to the start of the loop to prompt for valid input
    }
    // if (game.getCounter() % 2 == 0) { //different directions for X
    //     if (inputDirection == "FR") {
    //     direction = 0;
    // } else if (inputDirection == "FL") {
    //     direction = 1;
    // } else if (inputDirection == "BL") {
    //     direction = 2;
    // } else if (inputDirection == "BR") {
    //     direction = 3;
    // } else if (inputDirection == "JFR") {
    //     direction = 4;
    // } else if (inputDirection == "JFL") {
    //     direction = 5;
    // } else if (inputDirection == "JBL") {
    //     direction = 6;
    // } else if (inputDirection == "JBR") {
    //     direction = 7;
    // } else {
    //     cout << "Invalid direction. Try again." << endl;
    //     continue; // Go back to the start of the loop to prompt for valid input
    // }
    //  }
    // else {
    // if (inputDirection == "FR") {
    //     direction = 1;
    // } else if (inputDirection == "FL") {
    //     direction = 0;
    // } else if (inputDirection == "BL") {
    //     direction = 3;
    // } else if (inputDirection == "BR") {
    //     direction = 2;
    // } else if (inputDirection == "JFR") {
    //     direction = 5;
    // } else if (inputDirection == "JFL") {
    //     direction = 4;
    // } else if (inputDirection == "JBL") {
    //     direction = 7;
    // } else if (inputDirection == "JBR") {
    //     direction = 6;
    // } else {
    //     cout << "Invalid direction. Try again." << endl;
    //     continue; // Go back to the start of the loop to prompt for valid input
    // }
    // }
        
    if (!game.validateInput(i, j, direction)) {
        continue; // Go back to the start of the loop to prompt for valid input
    }
    
    // Validate move or jump
    if (direction < 4) { //not jumping so just check if it is a valid move
        if (game.isValidMove(i, j, direction)) { 
            game.movePiece(i, j, direction);
        } else {
            cout << "Invalid move. Try again." << endl;
            continue; // Go back to the start of the loop to prompt for valid input
        }
    } 
    else { //else it is a jump so check for valid jump
        if(game.isValidJump(i, j, direction)){ //check if it is a valid jump
            game.jump(i, j, direction);
        } else {
            cout << "Invalid jump. Try again." << endl;
            continue; // Go back to the start of the loop to prompt for valid input
        }

        
        for(int d = 4; d < 8; d++){ //check if there are any other jumps available    
            if(game.isValidJump(i, j, d)){
                jumpAgainOptions.push_back(d); //add possible jumps to a vector
            }
        }
        
        if (jumpAgainOptions.size() != 0 && game.getCounter()%2 == 0){ //if there are options and X is playing
            
            cout << "Would you like to jump again? (Y/N): ";
            char jumpAgain = 'a';
        
            
            do {
                cin >> jumpAgain;
               } while (jumpAgain != 'Y' && jumpAgain != 'y' && jumpAgain != 'N' && jumpAgain != 'n');

            if(jumpAgain == 'Y' || jumpAgain == 'y'){ //if they want to jump again list their options
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
                cin >> inputDirection;
                direction = convertString(inputDirection, game.getCounter()); //convert their choice to a direction
                game.jump(i, j, direction); //jump 
            } 
            
            else if (jumpAgain == 'N' || jumpAgain == 'n'){ //if they don't want to jump again
                game.incrementCounter(); //increment the counter
            } 
        }
    }
        game.incrementCounter();

        if (game.checkWinner()) {
            game.checkBoard();
            cout << "Player " << (game.getCounter() % 2 == 0 ? 1 : 2) << " wins!" << endl;
            cout << " Thanks for playing!" << endl;
            break;
        }
    }
    return 0;
}