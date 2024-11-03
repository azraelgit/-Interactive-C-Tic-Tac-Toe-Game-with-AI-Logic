
#ifndef TICTACTOE1_H_
#define TICTACTOE1_H_

const int BOARDSIZE = 3;

class TicTacToe {
private:
    int board[BOARDSIZE][BOARDSIZE];
    int noOfMoves;

public:
    TicTacToe();
    int moves[BOARDSIZE][BOARDSIZE];
    bool isValidMove(int, int);
    void addMove(int &boardX, int &boardY, int x, int y, int player);
    int gameStatus();
    int getCellValue(int, int);
    bool isBoardFull() const;

};

TicTacToe::TicTacToe() {
    for (int row = 0; row < BOARDSIZE; row++)
        for (int col = 0; col < BOARDSIZE; col++)
            board[row][col] = 0;

    noOfMoves = 0;
}

bool TicTacToe::isValidMove(int x, int y) {
    if (x >= 0 && x < BOARDSIZE && y >= 0 && y < BOARDSIZE && board[x][y] == 0)
        return true;
    else
        return false;
}

void TicTacToe::addMove(int &boardX, int &boardY, int x, int y, int player) {
    board[x][y] = player;
    moves[boardX][boardY]++;
    noOfMoves++;
}

int TicTacToe::gameStatus() {
    for (int i = 0; i < BOARDSIZE; i++) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    if (board[1][1] != 0 && ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
                            (board[0][2] == board[1][1] && board[1][1] == board[2][0]))) {
        return board[1][1];
    }

    return 0;
}

int TicTacToe::getCellValue(int x, int y) {
    return board[x][y];
}

bool TicTacToe::isBoardFull() const {
    for (int row = 0; row < BOARDSIZE; row++) {
        for (int col = 0; col < BOARDSIZE; col++) {
            if (board[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}


#endif
