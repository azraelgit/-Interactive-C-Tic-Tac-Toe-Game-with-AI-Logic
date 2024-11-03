#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "NBTictactoe1.h"

class Player {
public:
    virtual ~Player() {}
    virtual void getPlayerMove(char player, int &boardX, int &boardY, int &x, int &y, const Coordinate &currentBoard) = 0;
};

#endif
