#include "checkers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Checkers::Checkers(){
    //initialize the board
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
        if(i % 2 == 0){
            if(j % 2 == 0){
            Board[i][j] = ' ';
            }
            else{
            if(i < 3){
                Board[i][j] = 'X';
            }
            else if(i > 4){
                Board[i][j] = 'O';
            }
            else{
                Board[i][j] = ' ';
            }
            }
        }
        else{
            if(j % 2 == 0){
            if(i < 3){
                Board[i][j] = 'X';
            }
            else if(i > 4){
                Board[i][j] = 'O';
            }
            else{
                Board[i][j] = ' ';
            }
            }
            else{
            Board[i][j] = ' ';
            }
        }
        }
    }
    //initialize the scores
    score1 = 0;
    score2 = 0;
}
void Checkers::printBoard(){
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for(int i = 0; i < 8; i++){
        cout << i << " ";
        for(int j = 0; j < 8; j++){
        cout << Board[i][j] << " ";
        }
        cout << endl;
    }
} 

  void Checkers::movePiece(int i, int j, int direction){

  } 
  
  bool Checkers::checkWinner(){

  } 
  
  bool Checkers::checkBoard(char Board){

  } 

  void Checkers::makeKing(int i, int j, char Board){

  } 

  bool Checkers::isValidMove(int i, int j, int direction){

  } 

  bool Checkers::isValidJump(int i, int j, int direction){

  } 