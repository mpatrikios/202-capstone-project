#include "Checkers.h"
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>

using namespace std;

Checkers::Checkers()
{
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
    cout << "   0   1   2   3   4   5   6   7" << endl; // Print column indices

    for (int i = 0; i < 8; i++) {
        cout << i << " "; // Print row index
        for (int j = 0; j < 8; j++) {
            if (j > 0) {
                cout << "|"; // Print vertical line before each cell except the first one
            }
            cout << " " << Board[i][j] << " "; // Print cell value
        }
        cout << endl;

        if (i < 7) {
            // Print horizontal line after each row except the last one
            cout << "  ";
            for (int j = 0; j < 8; j++) {
                if (j > 0) {
                    cout << "+"; // Print intersection symbol between cells
                }
                cout << "---"; // Print horizontal line
            }
            cout << endl;
        }
    }
}


void Checkers::movePiece(int i, int j, int direction)
{
    char peice = Board[i][j];
    Board[i][j] = ' ';
    if (counter % 2 == 0)  increment = 1;
    else  increment = -1;
        
    switch (direction)
    {
    case 1: // FR
        Board[i + increment][j + increment] = peice;
        break;
    case 2: // FL
        Board[i + increment][j - increment] = peice;
        break;
    case 3: // BL
        Board[i - increment][j - increment] = peice;
        break;
    case 4: // BR
        Board[i - increment][j + increment] = peice;
        break;
    }
}

void Checkers::jump(int i, int j, int direction)
{
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
    case 5: // JFR
        Board[i + jumpIncrement][j + jumpIncrement] = peice;
        Board[i + increment][j + increment] = ' ';
        break;
    case 6: // JFL
        Board[i + jumpIncrement][j - jumpIncrement] = peice;
        Board[i + increment][j - increment] = ' ';
        break;
    case 7: // JBL
        Board[i - jumpIncrement][j - jumpIncrement] = peice;
        Board[i - increment][j - increment] = ' ';
        break;
    case 8: // JBR
        Board[i - jumpIncrement][j + jumpIncrement] = peice;
        Board[i - increment][j + increment] = ' ';
        break;
    }
     if (Board[i][j] == 'X')  score1++;
        else score2++;
}


bool Checkers::checkBoard()
{
    if (score1 == score2){
        cout << "Tie Game!";
    }else score1 > score2 ? cout << "Player 1 wins!" : cout << "Player 2 wins!";
}

bool Checkers::checkWinner()
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
    }return false;
    
}
void Checkers::makeKing(int i, int j, char Board)
{
}

bool Checkers::isValidMove(int i, int j, int direction)
{
    char enemy1, enemy2;
    if (counter % 2 == 0)
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
    switch (direction)
    {
    case 1: // FR
        if (Board[i + increment][j + increment] == ' ')
            return true;
        break;
    case 2: // FL
        if (Board[i + increment][j - increment] == ' ')
            return true;
        break;
    case 3: // BL
        if (Board[i][j] != 'X' || 'O')
        {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }
        if (Board[i - increment][j - increment] == ' ')
            return true;
        break;
    case 4: // BR
        if (Board[i][j] != 'X' || 'O')
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
 return false;
}

bool Checkers::isValidJump(int i, int j, int direction)
{
    char enemy1;
    char enemy2;
    // can't jump their own peice and
    if (counter % 2 == 0)
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
    case 5: // JFR 
        if ((Board[i + increment][j + increment] == enemy1 ||Board[i + increment][j + increment] == enemy2) && Board[i + 2][j + 2] == ' ')
            return true;
        break;
    case 6: // JFL
        if ((Board[i + increment][j - increment] == enemy1 ||Board[i + increment][j + increment] == enemy2) && Board[i + 2][j - 2] == ' ')
            return true;
        break;
    case 7: // JBL
        if (Board[i][j] != 'K')
        {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }
        if ((Board[i - increment][j - increment] == enemy1 || Board[i - increment][j - increment] == enemy2 )&& Board[i - 2][j - 2] == ' ')
            return true;
        break;
    case 8: // JBR
        if (Board[i][j] != 'K')
        {
            cout << "Not a King. Cannot move backwards.";
            return false;
        }
        if ((Board[i - increment][j + increment] == enemy1 ||Board[i - increment][j + increment] == enemy2) && Board[i - 2][j + 2] == ' ')
            return true;
        break;
    default:
        cout << "Invalid jump. Try again.";
        return false;
        break;
    }
}

// Validate user input for piece coordinates and direction
bool Checkers::validateInput(int i, int j, int direction) {
    // Check if piece coordinates are within the board boundaries
    if (i < 0 || i >= 8 || j < 0 || j >= 8) {
        cout << "Invalid piece coordinates. Please enter coordinates within the range [0, 7]." << endl;
        return false;
    }

    // Check if direction is within the valid range (1 to 8)
    if (direction < 1 || direction > 8) {
        cout << "Invalid direction. Please enter a direction between 1 and 8." << endl;
        return false;
    }

    // Additional validation if needed for specific game rules
    // For example, check if the piece at (i, j) belongs to the current player

    return true; // Input is valid
}

int Checkers::getCounter()
{
    return counter;
}

void Checkers::incrementCounter()
{
    counter++;
}