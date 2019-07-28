/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  implementation file for Dice class
*******************************************************************************/

#include "Dice.hpp"
#include <stdlib.h>

Dice::Dice()
{

}

Dice::Dice(int numbSides)
{
	numberOfSides = numbSides;
}

int Dice::getNumbSides()
{
	return numberOfSides;
}

int Dice::roll()
{
	return ((rand() % numberOfSides) + 1);
}