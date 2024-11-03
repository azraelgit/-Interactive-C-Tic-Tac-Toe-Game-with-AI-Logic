/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

#include "Tictactoe1.h"
#include "NBTictactoe1.h"
#include "NBGame.h"

int main() {

	NBTicTacToe nBTicTacToe(0, 0);
	NBGame game(nBTicTacToe);
	game.play();

	return 0;

}
