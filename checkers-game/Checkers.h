//Checkers game class header file
//Lab 8 Capstone - 202 - Mia Patrikios and Wyatt Knepp
#ifndef CHECKERS_H
#define CHECKERS_H

class Checkers{
  
private:
  int score1; //score for player 1
  int score2; //score for player 2
  int counter; //counter for turns
  int increment;
  int jumpIncrement;
  

public:
  char Board[8][8]; // 8x8 board
  Checkers(); // default constructor
  int getCounter();
  void printBoard(); // print the board
  bool validateInput(int i, int j, int direction);
  void movePiece(int &i, int &j, int direction); // move a piece
  void jump(int &i, int &j, int direction); // jump a piece
  bool checkWinner(); // check if there is a winner
  void checkBoard(); // check the winner if 'Q' is inputted
  char makeKing(int i, char peice); // make a piece a king
  bool isValidMove(int i, int j, int direction); // check if a move is valid
  bool isValidJump(int i, int j, int direction); // check if a jump is valid
  int getScore1();
  int getScore2();
  void incrementCounter();
};
#endif
