/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/14/2018
** Description:  implementation file for loaded dice class
*******************************************************************************/

#include "LoadedDice.hpp"
#include <stdlib.h>
#include <iostream>


LoadedDice::LoadedDice(int numbSides)
{
	numberOfSides = numbSides;
}

//will roll dice up to the number of rerolls(3) if result is less than half
int LoadedDice::roll() 
{
	//next line is commented out but was used for testing to make sure loaded dice was rolled
	//std::cout << "loaded dice is rolled" << std::endl;
	int roll = 0;
	for (int i = 0; i < numberRerolls; i++)
	{
		if (roll < (numberOfSides / 2) + 1)
		{
			roll = (rand() % numberOfSides) + 1;
		}
	}
	return roll;
}
