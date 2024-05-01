#include "Checkers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//are we asking if they want to jump or just jumping for them?
using namespace std;

int main() {
    int i, j, direction;
    int counter = 0;
    Checkers game;
    game.printBoard(); //create Checkers object and print the board
    cout << "Welcome to Checkers! Each play you will enter the row, column, and direction (F = forward, B = backward (only for kings)) ou would like to move. Player 1 will be X's and Player 2 will be O's. Enter 'Q' to quit the game." << endl;
    while (game.checkWinner() == false) { //if no winner, continue game
       if (counter % 2 == 0) { //even counter means player 1's turn
           cout << "Player 1's turn. Which space [row column 'F/B' ] would you like to move to:" << endl;
           if (cin >> i && i == 'Q') { //if input is Q, check winner of game and print message
                game.checkWinner();
               cout << "Thanks for playing!" << endl;
               break;
           }
           cin >> i >> j >> direction; //get input from user, i is row, j is column
              if (game.isValidMove(i, j, direction) == false) { //check valid move
                cout << "Invalid move. Try again." << endl;
              } else {
               if (game.isValidJump(i, j, direction)) {//check if the move is a valid jump, if it is check if they want to double/triple jump
                  game.jump(i, j, direction);
                  //check for double jump and ask if they want to jump again
                } else game.movePiece(i, j, direction); //if the move is not a valid jump, move the piece
                counter++;
              }
       } else {
           cout << "Player 2's turn. Which space [row column 'F/B' ] would you like to move to:" << endl;
           if (cin >> i && i == 'Q') { //if input is Q, check winner of game and print message
               game.checkWinner();
               cout << "Thanks for playing!" << endl;
               break;
           }
            cin >> i >> j >> direction; //get input from user, i is row, j is column
              if (game.isValidMove(i, j, direction) == false) { //check valid move
                cout << "Invalid move. Try again." << endl;
              } else {
               if (game.isValidJump(i, j, direction)) {//check if the move is a valid jump, if it is check if they want to double/triple jump
                  game.jump(i, j, direction);
                  //check for double jump and ask if they want to jump again
                } else game.movePiece(i, j, direction); //if the move is not a valid jump, move the piece
                counter++;
              }
       }
    }
    return 0;
}