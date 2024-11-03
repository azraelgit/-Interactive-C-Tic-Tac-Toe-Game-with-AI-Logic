
#ifndef NBTICTACTOE1_H_
#define NBTICTACTOE1_H_

#include "Coordinate.h"
#include "Tictactoe1.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"

class NBTicTacToe {
public:
	NBTicTacToe(int x, int y) {
		srand(static_cast<unsigned>(time(nullptr)));
	    currentBoard.x = rand() % 3;
	    currentBoard.y = rand() % 3;

	    randomPlayer = new RandomPlayer();
	    humanPlayer = new HumanPlayer();
	    currentPlayer = randomPlayer;
	}

    char currentPlayerSymbol = 'X';
    int boardStatus[3][3] = {0};
    void playerMove(char playerSymbol, int &boardX, int &boardY, int &x, int &y);
    void displayBoards();
    void setCurrentBoard(int x, int y);


    TicTacToe& getGrid(int boardX, int boardY) {
		return grid[boardX][boardY];
	}

    bool isNineBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!grid[i][j].isBoardFull()) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    Player* currentPlayer;
    Player* randomPlayer;
    Player* humanPlayer;
    TicTacToe grid[3][3];
	Coordinate currentBoard{};

};

void NBTicTacToe::setCurrentBoard(int x, int y) {
	currentBoard.x = x;
	currentBoard.y = y;
}

void NBTicTacToe::playerMove(char playerSymbol, int &boardX, int &boardY, int &x, int &y) {
    while (true) {
        currentPlayer->getPlayerMove(playerSymbol, boardX, boardY, x, y, currentBoard);

        if (grid[boardX][boardY].getCellValue(x, y) == 0 && grid[boardX][boardY].isValidMove(x, y)) {
            break;
        } else {
            cout << "Invalid move. Try again." << endl;

        }
    }

    currentPlayer = (currentPlayer == randomPlayer) ? humanPlayer : randomPlayer;
}

void NBTicTacToe::displayBoards() {

    for (int i = 0; i < 3; i++) {

    	cout << (currentBoard.y == 0 && currentBoard.x == i ? "  * * * * * " : "  - - - - - ");
    	cout << " ";
    	cout << (currentBoard.y == 1 && currentBoard.x == i ? "  * * * * * " : "  - - - - - ");
    	cout << " ";
		cout << (currentBoard.y == 2 && currentBoard.x == i ? "  * * * * * " : "  - - - - - ");
    	cout << endl;

        for (int row = 0; row < BOARDSIZE; row++) {
            for (int j = 0; j < 3; j++) {
                for (int col = 0; col < BOARDSIZE; col++) {

                	char playerSymbol = ' ';
                	if (grid[i][j].getCellValue(row, col) == 1)
						playerSymbol = 'X';
					else if (grid[i][j].getCellValue(row, col) == -1)
						playerSymbol = 'O';
                	cout << (currentBoard.x == i && currentBoard.y == j && col == 0 ? "*" : "|");
                	cout << " " << playerSymbol << " " << (currentBoard.x == i && currentBoard.y == j && col == 2 ? "*" : "");

                	if (col == 2) {
                		cout << (currentBoard.x == i && currentBoard.y == j ? "" : "|");
                	}

                	if (col == 2 && j == 2 && row < 2) {
						cout << endl;
						cout << (currentBoard.y == 0 && currentBoard.x == i ? "* -   -   - *" : "| -   -   - |");
						cout << (currentBoard.y == 1 && currentBoard.x == i ? "* -   -   - *" : "| -   -   - |");
						cout << (currentBoard.y == 2 && currentBoard.x == i ? "* -   -   - *" : "| -   -   - |");
					}

                }
                cout << "";
            }
            cout << endl;
        }

        cout << (currentBoard.y == 0 && currentBoard.x == i ? "  * * * * * " : "  - - - - - ");
		cout << " ";
		cout << (currentBoard.y == 1 && currentBoard.x == i ? "  * * * * * " : "  - - - - - ");
		cout << " ";
		cout << (currentBoard.y == 2 && currentBoard.x == i ? "  * * * * * " : "  - - - - - ");
		cout << endl;
        cout << endl;

    }
}



#endif
