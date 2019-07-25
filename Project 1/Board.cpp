/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  implementation file for board class
*******************************************************************************/

#include "Board.hpp"
#include "Ant.hpp"
#include <iostream>




//constructor with two int parameters for the board dimensions
Board::Board(int numRows, int numColumns, Ant* ant)
{
	ant1 = ant;
	ant1->setMaxColumn(numColumns);
	ant1->setMaxRow(numRows);
	grid = new char*[numRows];
	for (int i = 0; i < numRows; i++)
	{
		grid[i] = new char[numColumns];
	}
}

//to fill grid with spaces
void Board::fillGrid(int numRows, int numColumns)
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numColumns; j++)
		{
			grid[i][j] = ' ';
		}
	}
}

//to place ant's position on board
void Board::antPosition(int antRow, int antColumn)
{
	grid[antRow][antColumn] = '*';
	currentAntRow = antRow;
	currentAntColumn = antColumn;
}

//to display grid
void Board::displayGrid(int numRows, int numColumns)
{
	//to display top piece of frame
	for (int i = 0; i < numColumns + 2; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;

	//to display contents of grid
	for (int i = 0; i < numRows; i++)
	{
		std::cout << "|";	//to display left piece of frame
		for (int j = 0; j < numColumns; j++)
		{
			std::cout << grid[i][j];
		}
		std::cout <<  "|" << std::endl; //to display right piece of frame
	}

	//to display bottom piece of frame
	for (int i = 0; i < numColumns + 2; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}

//to delete grid
void Board::deleteGrid(int numRows)
{
	
	for (int i = 0; i < numRows; i++)
	{
		delete[] grid[i];
	}
	delete[] grid;
}

//to move ant
void Board::moveAnt()
{
	if (nextSpaceWhite)
	{
		ant1->onWhiteSquare();
		currentSpaceWhite = true;
		currentSpaceBlack = false;
	}

	if (nextSpaceBlack)
	{
		ant1->onBlackSquare();
		currentSpaceWhite = false;
		currentSpaceBlack = true;
	}

	//changes ant's orientation and gets ants current location
	ant1->changeOrientation();
	

	currentAntRow = ant1->getAntRow();
	currentAntColumn = ant1->getAntColumn();
	grid[currentAntRow][currentAntColumn] = ' ';	//to delete current * representing ant's location
	
	if (ant1->getOrientation() == UP)
	{
		ant1->moveUp();		//updating ant's location in ant class
	}

	else if (ant1->getOrientation() == LEFT)
	{
		ant1->moveLeft();
	}

	else if (ant1->getOrientation() == RIGHT)
	{
		ant1->moveRight();
	}

	else if (ant1->getOrientation() == DOWN)
	{
		ant1->moveDown();
	}
	
	nextAntRow = ant1->getAntRow();	//updating row
	nextAntColumn = ant1->getAntColumn();//updating column

	//to get next space's color before ant goes on it
	getNextSpace();
	grid[nextAntRow][nextAntColumn] = '*'; //printing * for ant 

	//to update previous square ant was on
	swapSpaceColor();
}

//to swap space color
void Board::swapSpaceColor()
{
	//to switch from white to black
	if (currentSpaceWhite)
	{
		grid[currentAntRow][currentAntColumn] = '#';
	}

	//to switch from black to white
	if (currentSpaceBlack)
	{
		grid[currentAntRow][currentAntColumn] = ' ';
	}

	//to switch from black to white
}

//to get next space's color before ant goes on it
void Board::getNextSpace()
{
	if (grid[nextAntRow][nextAntColumn] == ' ')
	{
		nextSpaceWhite = true;
		nextSpaceBlack = false;
	}

	if (grid[nextAntRow][nextAntColumn] == '#')
	{
		nextSpaceWhite = false;
		nextSpaceBlack = true;
	}
}