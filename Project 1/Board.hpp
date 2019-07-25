/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  header file for board class
*******************************************************************************/

#ifndef BOARD_hpp
#define BOARD_hpp

#include "Ant.hpp"

class Board
{
private:
	char ** grid;
	bool currentSpaceWhite = true, nextSpaceWhite = true;
	bool currentSpaceBlack = false, nextSpaceBlack = false;
	Ant* ant1;
	int currentAntRow, currentAntColumn;
	int nextAntRow, nextAntColumn;


public:
	Board(int, int, Ant*);
	void fillGrid(int, int);
	void antPosition(int, int);
	void displayGrid(int, int);
	void deleteGrid(int);
	void moveAnt();
	void swapSpaceColor();
	void getNextSpace();
};

#endif // !BOARD_hpp

