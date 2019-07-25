/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  implementation file for ant class
*******************************************************************************/

#include "Ant.hpp"
#include <iostream>

//constructor that has two parameters for starting location
Ant::Ant(int row, int column)
{
	antRow = row;
	antColumn = column;
	orientation = UP;
}

void Ant::setMaxColumn(int max)
{
	maxColumn = max - 1;
}

void Ant::setMaxRow(int max)
{
	maxRow = max -1;
}

void Ant::moveUp()
{
	if (antRow == 0)
	{
		antRow = maxRow;
	}
	else
	{
		antRow--;
	}
}

void Ant::moveLeft()
{
	if (antColumn == 0)
	{
		antColumn = maxColumn;
	}
	else
	{
		antColumn--;
	}
}

void Ant::moveDown()
{
	if (antRow == maxRow)
	{
		antRow = 0;
	}
	else
	{
		antRow++;
	}
}

void Ant::moveRight()
{
	if (antColumn == maxColumn)
	{
		antColumn = 0;
	}
	else
	{
		antColumn++;
	}
}

direction Ant::getOrientation()
{
	return orientation;
}

//changes orientation of ant based on color of square
void Ant::changeOrientation()
{
	if (onWhiteSpace)
	{
		orientation = static_cast<direction> ((orientation + 3) % 4);
	}

	if (onBlackSpace)
	{
		orientation = static_cast<direction> ((orientation + 1) % 4);
	}
}

int Ant::getAntRow()
{
	return antRow;
}

int Ant::getAntColumn()
{
	return antColumn;
}

void Ant::onWhiteSquare()
{
	onBlackSpace = false;
	onWhiteSpace = true;
}

void Ant::onBlackSquare()
{
	onBlackSpace = true;
	onWhiteSpace = false;
}