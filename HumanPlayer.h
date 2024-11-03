#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"
#include "NBTictactoe1.h"
#include "Coordinate.h"

class HumanPlayer : public Player {
public:
    void getPlayerMove(char player, int &boardX, int &boardY, int &x, int &y, const Coordinate &currentBoard) override {
        getHumanMove(player, boardX, boardY, x, y, currentBoard);
    }

    void getHumanMove(char player, int &boardX, int &boardY, int &x, int &y, const Coordinate &currentBoard) {
        cout << "Please enter your move on board (" << currentBoard.x + 1 << ", " << currentBoard.y + 1 << "): ";
        cin >> x >> y;
        x--;
        y--;

        boardX = currentBoard.x;
        boardY = currentBoard.y;
    }
};

#endif
