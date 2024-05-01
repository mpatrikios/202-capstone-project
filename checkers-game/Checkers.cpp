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
            }else{
            if(i < 3){
                Board[i][j] = 'X';
            }else if(i > 4){
                Board[i][j] = 'O';
            }else{
                Board[i][j] = ' ';
            }}
        }
        else{
            if(j % 2 == 0){
            if(i < 3){
                Board[i][j] = 'X';
            }else if(i > 4){
                Board[i][j] = 'O';
            }else{
                Board[i][j] = ' ';
            }}else{
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
    switch(direction){
        case 1: //FR
        Board[i+1][j+1] = Board[i][j];
        Board[i][j] = ' ';
        break;
        case 2: //FL
        Board[i+1][j-1] = Board[i][j];
        Board[i][j] = ' ';
        break;
        case 3: //BL
        Board[i-1][j-1] = Board[i][j];
        Board[i][j] = ' ';
        break;
        case 4: //BR
        Board[i-1][j+1] = Board[i][j];
        Board[i][j] = ' ';
        break;
    }

    }


  void Checkers::jump(int i, int j, int direction){
    switch(direction){
        case 5: //JFR
        if (Board[i][j] == 'X') {
            score1++;
        }else score2++;
        Board[i+2][j+2] = Board[i][j];
        Board[i+1][j+1] = ' ';
        Board[i][j] = ' ';
        break;
        case 6: //JFL
        if (Board[i][j] == 'X') {
            score1++;
        }else score2++;
        Board[i+2][j-2] = Board[i][j];
        Board[i+1][j-1] = ' ';
        Board[i][j] = ' ';
        break;
        case 7: //JBL
        if (Board[i][j] == 'X') {
            score1++;
        }else score2++;
        Board[i-2][j-2] = Board[i][j];
        Board[i-1][j-1] = ' ';  
        Board[i][j] = ' ';
        break;
        case 8: //JBR
        if (Board[i][j] == 'X') {
            score1++;
        }else score2++;
        Board[i-2][j+2] = Board[i][j];
        Board[i-1][j+1] = ' ';
        Board[i][j] = ' ';
        break;
    }
  }
  
  bool Checkers::checkWinner(){
    if (score1 == 12) {
        cout << "Player 1 wins!" << endl;
        return true;
    }else if (score2 == 12) {
        cout << "Player 2 wins!" << endl;
        return true;
    }else return false;
    
  } 
  
  bool Checkers::checkBoard(){
    score1 > score2 ? cout << "Player 1 wins!" : cout << "Player 2 wins!";
  } 

  void Checkers::makeKing(int i, int j, char Board){

  } 

bool Checkers::isValidMove(int i, int j, int direction){
    switch(direction){
        case 1: //FR
        if (Board[i+1][j+1] == ' ') return true;
        break;
        case 2: //FL
        if (Board[i+1][j-1] == ' ') return true;
        break;
        case 3: //BL
        if (Board[i][j] != 'K') {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }if (Board[i-1][j-1] == ' ') return true;
        break;
        case 4: //BR
        if (Board[i][j] != 'K') {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }if (Board[i-1][j+1] == ' ') return true;
        break;
        default:
        cout << "Invalid move. Try again.";
        return false;
        break;
  } 
  }

bool Checkers::isValidJump(int i, int j, int direction){
    switch(direction){
       case 5: //JFR
        if (Board[i+1][j+1] == 'X' && Board[i+2][j+2] == ' ') return true;
        break;
        case 6: //JFL
        if (Board[i+1][j-1] == 'X' && Board[i+2][j-2] == ' ') return true;
        break;
        case 7: //JBL
        if (Board[i][j] != 'K') {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }if (Board[i-1][j-1] == 'X' && Board[i-2][j-2] == ' ') return true;
        break;
        case 8: //JBR
        if (Board[i][j] != 'K') {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }if (Board[i-1][j+1] == 'X' && Board[i-2][j+2] == ' ') return true;
        break;
        default:
        cout << "Invalid jump. Try again.";
        return false;
        break;
    }
}
