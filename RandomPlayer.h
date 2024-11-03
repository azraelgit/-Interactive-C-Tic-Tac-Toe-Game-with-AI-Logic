#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

#include "Player.h"
#include "NBTictactoe1.h"
#include "Coordinate.h"

class RandomPlayer : public Player {
public:
    void getPlayerMove(char player, int &boardX, int &boardY, int &x, int &y, const Coordinate &currentBoard) override {
        getRandomMove(player, boardX, boardY, x, y, currentBoard);
    }

    void getRandomMove(char player, int &boardX, int &boardY, int &x, int &y, const Coordinate &currentBoard) {
            boardX = currentBoard.x;
            boardY = currentBoard.y;
            x = rand() % 3;
            y = rand() % 3;

    }
};

#endif
