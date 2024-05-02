#include "Checkers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//are we asking if they want to jump or just jumping for them?

using namespace std;

int main() {
    int i, j, direction;
    char quitOption;
    string inputDirection;
    Checkers game;
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
    while (!game.checkWinner()) { //if no winner, continue game
    cout << "Player " << (game.getCounter() % 2 == 0 ? 1 : 2) << "'s turn. Which piece would you like to move [row column direction] ('Q' to quit): ";
    cin >> quitOption;
    if (quitOption == 'Q') { // Check for quit option
        game.checkBoard();
        cout << "Thanks for playing!" << endl;
        break;
    }

    cin >> i >> j >> inputDirection; //get input from user, i is row, j is column
    if (!game.validateInput(i, j, direction)) {
        // If input is not valid, skip the rest of the loop iteration
        continue;
    }
    // Convert input direction to integer
    if (inputDirection == "FR") {
        direction = 1;
    } else if (inputDirection == "FL") {
        direction = 2;
    } else if (inputDirection == "BL") {
        direction = 3;
    } else if (inputDirection == "BR") {
        direction = 4;
    } else if (inputDirection == "JFR") {
        direction = 5;
    } else if (inputDirection == "JFL") {
        direction = 6;
    } else if (inputDirection == "JBL") {
        direction = 7;
    } else if (inputDirection == "JBR") {
        direction = 8;
    } 

    if (!game.validateInput(i, j, direction)) {
        // If input is not valid, skip the rest of the loop iteration
        continue;
    }
    // Validate move or jump
    if (direction < 5) {
        if (game.isValidMove(i, j, direction)){
            game.movePiece(i, j, direction);
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    } else {
        if (game.isValidJump(i, j, direction)) {
            game.jump(i, j, direction);
            // Check for double jump and ask if they want to jump again
        } else {
            cout << "Invalid jump. Try again." << endl;
        }
    }
    game.incrementCounter();
    if (game.checkWinner()){
        game.checkBoard();
        cout << "Player " << (game.getCounter() % 2 == 0 ? 1 : 2) << " wins!" << endl;
        cout << "Thanks for playing!" << endl;
        break;
    }
}
return 0;
}


