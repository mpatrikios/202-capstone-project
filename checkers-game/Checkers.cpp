#include "Checkers.h"
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>

using namespace std;

Checkers::Checkers()
{
    counter = 0;
    // initialize the board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    Board[i][j] = ' ';
                }
                else
                {
                    if (i < 3)
                    {
                        Board[i][j] = 'x';
                    }
                    else if (i > 4)
                    {
                        Board[i][j] = 'o';
                    }
                    else
                    {
                        Board[i][j] = ' ';
                    }
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    if (i < 3)
                    {
                        Board[i][j] = 'x';
                    }
                    else if (i > 4)
                    {
                        Board[i][j] = 'o';
                    }
                    else
                    {
                        Board[i][j] = ' ';
                    }
                }
                else
                {
                    Board[i][j] = ' ';
                }
            }
        }
    }
    // initialize the scores
    score1 = 0;
    score2 = 0;
}
void Checkers::printBoard()
{
    cout << "             X side" << endl;
    cout << "   0   1   2   3   4   5   6   7" << endl; // Print column indices

    for (int i = 0; i < 8; i++) {
        cout << i << " "; // Print row index
        for (int j = 0; j < 8; j++) 
        {
            if (j > 0) 
            {
                cout << "|"; // Print vertical line before each cell except the first one
            }
            cout << " " << Board[i][j] << " "; // Print cell value
        }
        cout << endl;

        if (i < 7) {
            // Print horizontal line after each row except the last one
            cout << "  ";
            for (int j = 0; j < 8; j++) 
            {
                if (j > 0) 
                {
                    cout << "+"; // Print intersection symbol between cells
                }
                cout << "---"; // Print horizontal line
            }
            cout << endl;
        }
    }
    cout << "             O side";
}


void Checkers::movePiece(int &i, int &j, int direction)
{
    char peice = Board[i][j]; // save the peice
    Board[i][j] = ' '; // remove the peice from the board
    if (counter % 2 == 0)  increment = 1; // player 1
    else  increment = -1; // player 2
        
    switch (direction)
    {
    case 0: // FR
        Board[i + increment][j + increment] = peice;
        i += increment;
        j += increment;
        break;

    case 1: // FL
        Board[i + increment][j - increment] = peice;
        i += increment;
        j -= increment;
        break;

    case 2: // BL
        Board[i - increment][j - increment] = peice;
         i -= increment;
         j -= increment;
        break;

    case 3: // BR
        Board[i - increment][j + increment] = peice;
         i -= increment;
         j += increment;
        break;
    }
}

void Checkers::jump(int &i, int &j, int direction)
{
    if (Board[i][j] == 'X' || Board[i][j] == 'x')  score1++; //add points when player jumps a peice
    else score2++;
    
    char peice = Board[i][j];
    Board[i][j] = ' ';

    if (counter % 2 == 0)
    {
        increment = 1;
        jumpIncrement = 2;
    }
    else
    {
        increment = -1;
        jumpIncrement = -2;
    }


    switch (direction)
    {
    case 4: // JFR
        Board[i + jumpIncrement][j + jumpIncrement] = peice;
        Board[i + increment][j + increment] = ' ';
        i += jumpIncrement;
        j += jumpIncrement;
        break;

    case 5: // JFL
        Board[i + jumpIncrement][j - jumpIncrement] = peice;
        Board[i + increment][j - increment] = ' ';
        i += jumpIncrement;
        j -= jumpIncrement;
        break;

    case 8: // JBL
        Board[i - jumpIncrement][j - jumpIncrement] = peice;
        Board[i - increment][j - increment] = ' ';
        i -= jumpIncrement;
        j -= jumpIncrement;
        break;

    case 7: // JBR
        Board[i - jumpIncrement][j + jumpIncrement] = peice;
        Board[i - increment][j + increment] = ' ';
        i -= jumpIncrement;
        j += jumpIncrement;
        break;
    }
     
}


void Checkers::checkBoard() //if player quits before game is over check board for winner
{
    if (score1 == score2)
    {
        cout << "Tie Game!";
    }
    else if (score1 > score2 )
    {
        cout << "Player 1 wins!";
    }
    else if (score2 > score1) 
        cout << "Player 2 wins!";
}

bool Checkers::checkWinner() //check if there is a winner after every move
{
    if (score1 == 12 && score2 == 12)
    {
        cout << "Tie Game!";
        return true;
    }
    else if (score1 == 12)
    {
        cout << "Player 1 wins!";
        return true;
    }
    else if (score2 == 12)
    {
        cout << "Player 2 wins!";
        return true;
    }
    return false;
    
}
char Checkers::makeKing(int i, char peice) //make a peice a king if in the correct row
{
    char newPeice;
    if (peice == 'x' && i == 7)
    {
        newPeice = 'X';
    }
    else if (peice == 'o' && i == 0)
    {
       newPeice = 'O';
    }
    else
    {
        newPeice = peice;
    }
    return newPeice;
}

bool Checkers::isValidMove(int i, int j, int direction) //make sure move is on the board and the spot is open
{
    //cant't jump their own peices 
    char enemy1, enemy2;
    if (Board[i][j] == 'X' || Board[i][j] == 'x')
    {
        enemy1 = 'o';
        enemy2 = 'O';
        increment = 1;
    }
    else
    {
        enemy1 = 'x';
        enemy2 = 'X';
        increment = -1;
    }
    switch (direction){

    case 0: // FR
        if (i + increment < 0 || i + increment > 7 || j + increment < 0 || j + increment > 7)
        {
            return false;
        }
        if (Board[i + increment][j + increment] == ' ')
            return true;
        break;

    case 1: // FL
        if (i + increment < 0 || i + increment > 7 || j - increment < 0 || j - increment > 7)
        {
            return false;
        }
        if (Board[i + increment][j - increment] == ' ') 
            return true;
        break;

    case 2: // BL
        if (i - increment < 0 || i - increment > 7 || j - increment < 0 || j - increment > 7)
        {
            return false;
        }
        if (Board[i][j] != 'X' && Board[i][j] != 'O')
        {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }
        if (Board[i - increment][j - increment] == ' ')
            return true;
        break;

    case 3: // BR
        if (i - increment < 0 || i - increment > 7 || j + increment < 0 || j + increment > 7)
        {
            return false;
        }
        if (Board[i][j] != 'X' && Board[i][j] != 'O')
        {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }
        if (Board[i - increment][j + increment] == ' ')
            return true;
        break;

    default:
        cout << "Invalid move. Try again.";
        return false;
        break;
    }
    if (Board[i][j] == ' ') return false;
 return false;
}

bool Checkers::isValidJump(int i, int j, int direction) //check if jump is on the board, make sure not jumping own peice
{
    char enemy1;
    char enemy2;
    // can't jump their own peice and different increments for x and o since they are moving different directions
    if (Board[i][j] == 'X' || Board[i][j] == 'x')
    { 
        increment = 1;
        jumpIncrement = 2;
        enemy1 = 'o';
        enemy2 = 'O';
    }
    else
    {
        increment = -1;
        jumpIncrement = -2;
        enemy1 = 'x';
        enemy2 = 'X';
    }

    switch (direction)
    {
    case 4: // JFR 
        if (i + increment*2 < 0 || i + increment*2 > 7 || j + increment*2 < 0 || j + increment*2 > 7)
        {
            return false;
        }
        if ((Board[i + increment][j + increment] == enemy1 ||Board[i + increment][j + increment] == enemy2) && Board[i + jumpIncrement][j + jumpIncrement] == ' ')
            return true;
        break;

    case 5: // JFL
        if (i + increment*2 < 0 || i + increment*2 > 7 || j - increment*2 < 0 || j - increment*2 > 7)
        {
            return false;
        }
        if ((Board[i + increment][j - increment] == enemy1 ||Board[i + increment][j + increment] == enemy2) && Board[i + jumpIncrement][j - jumpIncrement] == ' ')
            return true;
        break;

    case 6: // JBL
        if (Board[i][j] != 'X' && Board[i][j] != 'O')
        {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }

        if (i - increment*2 < 0 || i - increment*2 > 7 || j - increment*2 < 0 || j - increment*2 > 7)
        {
            return false;
        }
        if ((Board[i - increment][j - increment] == enemy1 || Board[i - increment][j - increment] == enemy2 )&& Board[i - jumpIncrement][j - jumpIncrement] == ' ')
            return true;
        break;

    case 7: // JBR
        if (Board[i][j] != 'X' && Board[i][j] != 'O')
        {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }

        if (i - increment*2 < 0 || i - increment*2 > 7 || j + increment*2 < 0 || j + increment*2 > 7)
        {
            return false;
        }
        if ((Board[i - increment][j + increment] == enemy1 ||Board[i - increment][j + increment] == enemy2) && Board[i - jumpIncrement][j + jumpIncrement] == ' ')
            return true;
        break;

    default:
        cout << "Invalid jump. Try again.";
        return false;
        break;
    }
    if (Board[i][j] == ' ') return false;
    return false;
}

// Validate user input for piece coordinates and direction
bool Checkers::validateInput(int i, int j, int direction) { 
    // Check if piece coordinates are within the board boundaries
    if (i < 0 || i >= 8 || j < 0 || j >= 8)
    {
        cout << "Invalid piece coordinates. Please enter coordinates within the range [0, 7]." << endl;
        return false;
    }

    // Check if direction is within the valid range (1 to 8)
    if (direction <  0 || direction > 8) 
    {
        cout << "Invalid direction. Please enter a direction given above" << endl;
        return false;
    }
    if (Board[i][j] == ' ')
    {
        return false;
    }
    // Additional validation if needed for specific game rules
    // For example, check if the piece at (i, j) belongs to the current player

    return true; // Input is valid
}

int Checkers::getScore1() 
{
    return score1;
}

int Checkers::getScore2()
{
    return score2;
}

int Checkers::getCounter()
{
    return counter;
}

void Checkers::incrementCounter()
{
    counter++;
}

