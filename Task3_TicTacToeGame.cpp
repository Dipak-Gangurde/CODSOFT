/*
 TASK 3
 TIC-TAC-TOE GAME

 Build a simple console-based Tic-Tac-Toe game that
 allows two players to play against each other

Game Board: Create a 3x3 grid as the game board.
 Players: Assign "X" and "O" to two players.
 Display Board: Show the current state of the board.
 Player Input: Prompt the current player to enter their move.
 Update Board: Update the game board with the player's move.
 Check for Win: Check if the current player has won.
 Check for Draw: Determine if the game is a draw.
 Switch Players: Alternate turns between "X" and "O" players.
 Display Result: Show the result of the game (win, draw, or ongoing).
 Play Again: Ask if the players want to play another game.
*/

#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string name1, name2;
char token = 'X';
int digit, row, column;
bool tie = false;
char choice;

void displayBoard() {
  cout <<endl<< "     |     |     " << endl;
  cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  "
       << space[0][2] << "  " << endl;
  cout << "-----|-----|-----" << endl;
  cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  "
       << space[1][2] << "  " << endl;
  cout << "-----|-----|-----" << endl;
  cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  "
       << space[2][2] << "  " << endl;
  cout << "     |     |     " << endl<<endl;
}

void getPlayerInput() {
  if (token == 'X') {
    cout << name1 << " please enter your move:   ";
    cin >> digit;
  }
  if (token == 'O') {
    cout << name2 << " please enter your move:   ";
    cin >> digit;
  }

  if (digit == 1) {
    row = 0;
    column = 0;
  }
  if (digit == 2) {
    row = 0;
    column = 1;
  }
  if (digit == 3) {
    row = 0;
    column = 2;
  }
  if (digit == 4) {
    row = 1;
    column = 0;
  }
  if (digit == 5) {
    row = 1;
    column = 1;
  }
  if (digit == 6) {
    row = 1;
    column = 2;
  }
  if (digit == 7) {
    row = 2;
    column = 0;
  }
  if (digit == 8) {
    row = 2;
    column = 1;
  }
  if (digit == 9) {
    row = 2;
    column = 2;
  } else if (digit < 3 && digit > 9)
    cout << "Invalid move!" << endl;

  if (token == 'X' && space[row][column] != 'X' && space[row][column] != 'O') {
    space[row][column] = 'X';
    token = 'O';
  } else if (token == 'O' && space[row][column] != 'X' &&
             space[row][column] != 'O') {
    space[row][column] = 'O';
    token = 'X';
  } else {
    cout << "This space is already filled!!" << endl;
    getPlayerInput();
  }
}

bool checkGameResult() {
  for (int i = 0; i < 3; i++)
    if (space[i][0] == space[i][1] && space[i][0] == space[i][2] ||
        space[0][i] == space[1][i] && space[0][i] == space[2][i])
      return true;

  if (space[0][0] == space[1][1] && space[1][1] == space[2][2] ||
      space[0][2] == space[1][1] && space[1][1] == space[2][0])
    return true;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (space[i][j] != 'X' && space[i][j] != 'O')
        return false;

  tie = true;
  return false;
}

int main() {
  cout << "\n\t\tTASK 3";
  cout << "\n\t\tTIC-TAC-TOE GAME\n" << endl;

  cout << "Enter first player name:   ";
  cin >> name1;
  cout << "Enter second player name:   ";
  cin >> name2;

  do {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        space[i][j] = '1' + i * 3 + j;

    token = 'X';
    tie = false;

    cout << endl << name1 << " you will  play first move. " << endl;
    cout << name2 << " you will play second move." << endl;

    while (!checkGameResult()) {
      displayBoard();
      getPlayerInput();
      checkGameResult();
    }
    displayBoard();

    if (token == 'X' && tie == false)
      cout << name2 << " you win the game!!!" << endl;
    else if (token == 'O' && tie == false)
      cout << name1 << " you win the game!!!" << endl;
    else
      cout << "Game is draw" << endl;

    cout << "\n\tDo you want to play again this game? "
         << "\n\t\tIf yes then press -> 'y': "
         << "\n\t\tIf no then press -> 'n': "
         << "\n\t\t\t ";
    cin >> choice;

  } while (choice == 'y');
}