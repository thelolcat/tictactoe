/*Tic Tac Toe. A simple and fun game, recreated in C++ as a console app.
This project was made as a method for me and my friends to learn the basics of C++.
And I learned Git in the process too! :D
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

char ui[3][10] = { {' ',' ',' ','|',' ',' ',' ','|',' ',' '},
                   {' ',' ',' ','|',' ',' ',' ','|',' ',' '},
                   {' ',' ',' ','|',' ',' ',' ','|',' ',' '}, };

char currentPlayer = 'X';
int input = 0;
bool checkWin();

int main()
{
    while (true) {
        // clears command line
        system("cls");

        // draws UI
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                cout << ui[i][j];
            }
            cout << endl;
        }

        // checks for a win
        if (checkWin()) {
            cout << currentPlayer << " won!\nPlay again?(y/n)";
        }

        // changes player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

        // gets input, modifies it such that '1' becomes 1 and so on,
        // and checks if the input is in the set 0 - 9
        input = cin.get();
        input -= 48;
        if (input < 1 || input > 9) continue;

        // processes input and stores it in UI.
        // Uses a unique algorithm to calculate the position in the UI to which each number corresponds to
        if (ui[(int)(9 - input)/3][(int)((input - 1) % 3) * 4 + 1] == ' ') {
            ui[(int)(9 - input)/3][(int)((input - 1) % 3) * 4 + 1] = currentPlayer;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

// checks each row, column, and the two diagonals for a streak of Os or Xs
bool checkWin() {
    // checks columns
    for (int i = 0; i < 3; i++) {
        if (ui[i][1] == ui[i][5] && ui[i][5] == ui[i][9] && ui[i][1] != ' ') return true;
    }
    // checks rows
    for (int i = 1; i <= 9; i += 4) {
        if (ui[0][i] == ui[1][i] && ui[0][i] == ui[2][i] && ui[0][i] != ' ') return true;
    }
    return false;
}