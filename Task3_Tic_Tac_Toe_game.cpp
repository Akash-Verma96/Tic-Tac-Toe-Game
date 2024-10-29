#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for(int i = 0; i < BOARD_SIZE; ++i)
        for(int j = 0; j < BOARD_SIZE; ++j)
            board[i][j] = ' ';
}

void printBoard() {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < BOARD_SIZE - 1) cout << "--+---+--" << endl;
    }
}

bool checkWin(char player) {
    for(int i = 0; i < BOARD_SIZE; ++i)
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

    for(int j = 0; j < BOARD_SIZE; ++j)
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool checkDraw() {
    for(int i = 0; i < BOARD_SIZE; ++i)
        for(int j = 0; j < BOARD_SIZE; ++j)
            if(board[i][j] == ' ')
                return false;
    return true;
}

void playGame() {
    char currentPlayer = 'X';
    while(true) {
        printBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if(row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row-1][col-1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row-1][col-1] = currentPlayer;

        if(checkWin(currentPlayer)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if(checkDraw()) {
            printBoard();
            cout << "The game is a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}
