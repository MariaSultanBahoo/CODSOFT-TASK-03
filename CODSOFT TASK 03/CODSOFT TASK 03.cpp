// CODSOFT TASK 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

const int s = 3;
char board[s][s] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };
char current_turn = 'X';

bool check_win(char turn) {
    // Check rows
    for (int i = 0; i < s; ++i) {
        if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < s; ++j) {
        if (board[0][j] == turn && board[1][j] == turn && board[2][j] == turn) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) {
        return true;
    }
    if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) {
        return true;
    }

    return false;
}

bool is_board_full() {
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void player_turn() {
    int row, col;

    do {
        cout << "Player " << current_turn << "'s turn. Enter row number (1-3): ";
        cin >> row;
        cout << "Enter column number (1-3): ";
        cin >> col;
    } while (row < 1 || row > s || col < 1 || col > s || board[row - 1][col - 1] != ' ');

    board[row - 1][col - 1] = current_turn;

    current_turn = (current_turn == 'X') ? 'O' : 'X';
}

void display_board() {
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;

    while (true) {
        display_board();
        player_turn();

        if (check_win(current_turn)) {
            display_board();
            cout << "Player " << current_turn << " wins!" << endl;
            break;
        }
        else if (is_board_full()) {
            display_board();
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}