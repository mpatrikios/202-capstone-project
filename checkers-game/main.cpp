#include "Checkers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//are we asking if they want to jump or just jumping for them?

using namespace std;

int main() {
    int i, j, direction;
    string inputDirection;
    int counter = 0;
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
    while (game.checkWinner() == false) { //if no winner, continue game
       if (counter % 2 == 0) { //even counter means player 1's turn
             cout << "Player 1's turn. Which peice would you like to move[row column direction]: " << endl;
             if (cin >> i && i == 'Q') { //if input is Q, check winner of game and print message
              game.checkBoard();
               cout << "Thanks for playing!" << endl;
               break;
             }
             cin >> i >> j >> inputDirection; //get input from user, i is row, j is column
             if (inputDirection == "FR") { //change to direction to int
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
              if (game.isValidMove(i, j, direction) == false) { //check valid move
                cout << "Invalid move. Try again." << endl;
              } else {
               if (game.isValidJump(i, j, direction)) {//check if the move is a valid jump, if it is check if they want to double/triple jump
                  game.jump(i, j, direction);
                  game.checkWinner();
                  //check for double jump and ask if they want to jump again
                } else game.movePiece(i, j, direction); //if the move is not a valid jump, move the piece
                counter++;
              }
       } else {
           cout << "Player 2's turn. Which peice would you like to move[row column direction]: " << endl;
           if (cin >> i && i == 'Q') { //if input is Q, check winner of game and print message
               game.checkBoard();
               cout << "Thanks for playing!" << endl;
               break;
           }
            cin >> i >> j >> inputDirection; //get input from user, i is row, j is column
            if (inputDirection == "FR") { //change direction to int
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
              } if (direction < 5) {
               if (game.isValidMove(i, j, direction)){
                game.movePiece(i, j, direction);
               } else cout << "Invalid move. Try again." << endl;
              } else {
               if (game.isValidJump(i, j, direction)) {//check if the move is a valid jump, if it is check if they want to double/triple jump
                  game.jump(i, j, direction);
                  game.checkWinner();
                  //check for double jump and ask if they want to jump again
                } else game.movePiece(i, j, direction); //if the move is not a valid jump, move the piece
                counter++;
              }
       }
    }
    return 0;
}