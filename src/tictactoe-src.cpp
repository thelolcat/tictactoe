/*Tic Tac Toe. A simple and fun game, recreated in C++ as a console app.
This project was made as a method for me and my friends to learn the basics of C++.
And I learned Git in the process too! :D - thelolcat
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

char ui[3][10] = { {' ',' ',' ','|',' ',' ',' ','|',' ',' '},
                   {' ',' ',' ','|',' ',' ',' ','|',' ',' '},
                   {' ',' ',' ','|',' ',' ',' ','|',' ',' '}, };
char currentPlayer = 'O';
int input = 0;
bool checkWin();
bool checkDraw();

int main()
{
    while (true) {
        // clears command line
        system("cls");

        // draws UI
        cout << "\033[91mTic \033[94mTac \033[92mToe!\033[0m\n\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                switch (ui[i][j]) {
                case 'X':
                    cout << "\033[31m" << ui[i][j] << "\033[0m"; // gives 'X' with the specified color (red)
                    break;
                case 'O':
                    cout << "\033[32m" << ui[i][j] << "\033[0m"; // gives 'O' with the specified color (green)
                    break;
                default:
                    cout << ui[i][j]; //gives all other characters with the specified color (default)
                }
                // color codes referred from https://www.geeksforgeeks.org/how-to-change-console-color-in-cpp/
            }
            cout << endl;
        }

        // checks for a win or a draw
        if (checkWin() || checkDraw()) {
            if (checkWin()) cout << currentPlayer << " won!";
            else if (checkDraw()) cout << "It's a draw!";

            // triggers restart or closes game based on input
            cout << " Play again? (y/n): ";
            input = cin.get();
            if (input == 'y') {
                for (int i = 1; i < 10; i++) {
                    ui[(int)(9 - i) / 3][(int)((i - 1) % 3) * 4 + 1] = ' ';
                }
                currentPlayer = 'O';
                continue;
            }
            else if (input == 'n') break;
            else continue;
        }


        // gets input, parses it from char to int,
        // and checks if the input is in the set 0 - 9
        input = cin.get();
        if (input == '\n') input = cin.get(); // handles a bug (see appendix 1)
        cin.ignore(INT64_MAX,'\n'); // clears the cin stream of extra input
        input -= 48; // so that '1' becomes 1 and so on
        if (input < 1 || input > 9) continue;

        // processes input and stores it in the UI array.
        // Uses a unique algorithm to calculate the position in the UI to which each number corresponds to
        if (ui[(int)(9 - input)/3][(int)((input - 1) % 3) * 4 + 1] == ' ') {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // changes player
            ui[(int)(9 - input)/3][(int)((input - 1) % 3) * 4 + 1] = currentPlayer;
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

    // checks diagonals
    if (ui[1][5] != ' ') return (ui[0][1] == ui[1][5] && ui[1][5] == ui[2][9])
        || (ui[0][9] == ui[1][5] && ui[1][5] == ui[2][1]);
    else return false;
}

// checks if all spaces are filled (a draw)
bool checkDraw() {
    for (int i = 1; i < 10; i++) {
        if (ui[(int)(9 - i) / 3][(int)((i - 1) % 3) * 4 + 1] == ' ') return false;
    }
    return true;
}

/*Appendices
  1.There was a bug where when the game does not process the first input
    after every restart, due to a '\n' creeping in the cin stream. It can
    also be fixed by clearing the cin stream just before a restart, but
    this method is more efficient and simple.
*/