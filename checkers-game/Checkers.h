#ifndef CHECKERS_H
#define CHECKERS_H

class Checkers{
  
private:
  char Board[8][8]; // 8x8 board
  int score1; //score for player 1
  int score2; //score for player 2

public:
  Checkers(); // default constructor
  void printBoard(); //prints board
  void movePiece(int i, int j); //moves checkers peice and checks if captured and if valid
  bool checkWinner(int i, int j, char Board); //check number of captured peices for winner
  bool checkBoard(char Board); //checks for winner if game is quit
  void makeKing(int i, int j, char Board); //makes peice a king
};
#endif