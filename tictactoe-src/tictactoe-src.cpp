#include <iostream>
#include <stdlib.h>

using namespace std;

char ui[3][10] = { {' ',' ',' ','|',' ',' ',' ','|',' ',' '},
                   {' ',' ',' ','|',' ',' ',' ','|',' ',' '},
                   {' ',' ',' ','|',' ',' ',' ','|',' ',' '}, };

char currentPlayer = 'X';
bool checkWin();

int main()
{
    while (true) {
        system("cls");

        // drawing
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

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

        // get input
        char input = cin.get();

        //process input
        switch (input) {
        case '7':
            if (ui[0][1] == ' ') {
                ui[0][1] = currentPlayer;
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        case '8':
            if (ui[0][5] == ' ') {
                ui[0][5] = currentPlayer;
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        case '9':
            if (ui[0][9] == ' ') {
                ui[0][9] = currentPlayer;
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        case '4':
            if (ui[1][1] == ' ') {
                ui[1][1] = currentPlayer;
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        case '5':
            if (ui[1][5] == ' ') {
                ui[1][5] = currentPlayer;
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        case '6':
            if (ui[1][9] == ' ') {
                ui[1][9] = currentPlayer;
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        case '1':
            if (ui[2][1] == ' ') {
                ui[2][1] = currentPlayer;
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        case '2':
            if (ui[2][5] == ' ') {
                ui[2][5] = currentPlayer;
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        case '3':
            if (ui[2][9] == ' ') {
                ui[2][9] = currentPlayer;
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        default:
            break;
        }
    }
}

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

/*
o | o | o
o | o | o
o | o | o

*/