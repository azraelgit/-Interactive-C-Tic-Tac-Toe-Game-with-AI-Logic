#ifndef NBGAME_H_
#define NBGAME_H_

#include "NBTictactoe1.h"
#include "Player.h"
#include <iostream>

class NBGame {
public:
    NBGame(NBTicTacToe& nineBoard) : nineBoard(nineBoard) {}
    void play();

private:
    NBTicTacToe& nineBoard;
};


void NBGame::play() {
    int play = 0;
    int boardX, boardY, x, y;

    while (play == 0) {
        nineBoard.displayBoards();

        cout << "Player " << nineBoard.currentPlayerSymbol << "'s turn." << endl << endl;
        nineBoard.playerMove(nineBoard.currentPlayerSymbol, boardX, boardY, x, y);
        nineBoard.getGrid(boardX, boardY).addMove(boardX, boardY, x, y, (nineBoard.currentPlayerSymbol == 'X') ? 1 : -1);

        play = nineBoard.getGrid(boardX, boardY).gameStatus();
        if (play == 1 || play == -1) {
            nineBoard.displayBoards();
            cout << "Player " << nineBoard.currentPlayerSymbol << " wins on board (" << boardX + 1 << ", " << boardY + 1 << ")!" << endl;
            nineBoard.boardStatus[boardX][boardY] = (nineBoard.currentPlayerSymbol == 'X') ? 1 : -1;
        }

        if (nineBoard.getGrid(boardX, boardY).isBoardFull()) {
			boardX = rand() % 3;
			boardY = rand() % 3;
			nineBoard.setCurrentBoard(x, y);
		} else {
			nineBoard.setCurrentBoard(x, y);
		}

        if (nineBoard.isNineBoardFull()) {
            cout << "All nine boards are full. The game is a draw." << endl;

            break;
        }

        nineBoard.currentPlayerSymbol = (nineBoard.currentPlayerSymbol == 'X') ? 'O' : 'X';
    }
}

#endif
