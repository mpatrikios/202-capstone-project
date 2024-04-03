# 202-capstone-project

** directions for board :
FR - front right (0)
FL - front left  (1)
BL - back left   (2)
BR - back right  (3)
JFR - jump front right (0)
JFL - jump front left (1)
JBL - jump back left (2)
JBR - jump back right (3)


void printBoard(); - prints checkers board 

void movePiece(int i, int j, int direction); int i/j are the coordiantes of the current peice being moved. bool isRight tells if the peice is moving to the right or left

void capturePeice(int i, int j, int direction); - checks if a peice is being captured with this move (ie. if the position they are moving to has the other players peice, remove that peice from the board, increase current players score, and move current peice to the space after the captured peice. If there is an opportunity to double or triple jump, prompt the current player to do so or not)

bool checkWinner(); - compares scores after every jump, if one player's score reaches 12 (total peices per player) that means they won and the game ends

bool checkBoard(char Board); - option to quit game early ("Q"). Compare two scores and determine winner.

void makeKing(int i, int j, char Board); - if a player reaches the opposite end of the board. make their peice a capital letter ( x -> X or o -> O) to indicate king. this will now allow the player to move in all directions

bool isValidMove(int i, int j, int direction)- checks if the move is on the board and valid

bool isValidJump(int i, int j, int direction)- checks if jump is valid (ie. on the board, not jumping their own peice, only moving backwards if king)


