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
    game.printBoard();
    cout << "Welcome to Checkers! Each play you will enter the row, column, and direction (F = forward, B = backward (only for kings)) ou would like to move. Player 1 will be X's and Player 2 will be O's. Enter 'Q' to quit the game." << endl;
    while (game.checkWinner() == false) {
       if (counter % 2 == 0) {
           cout << "Player 1's turn. Which space [row column 'F/B' ] would you like to move to:" << endl;
           cin >> i >> j >> direction;
              if (game.isValidMove(i, j, direction) == false) {
                cout << "Invalid move. Try again." << endl;
              } else {
                (game.isValidJump(i, j, direction) == true) ? game.jump(i, j, direction) : game.move(i, j, direction);
                counter++;
              }
       } else {
           cout << "Player 2's turn. Which space [row column 'F/B' ] would you like to move to:" << endl;
           cin >> i >> j >> direction;
              if (game.isValidMove(i, j, direction) == false) {
                cout << "Invalid move. Try again." << endl;
       }else {
           (game.isValidJump(i, j, direction) == true) ? game.jump(i, j, direction) : game.move(i, j, direction);
           counter++;
       }
       }
    }
    return 0;
}