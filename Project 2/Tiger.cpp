/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/21/2018
** Description:  implementation file for Tiger class
*******************************************************************************/

#include "Tiger.hpp"
#include <iostream>


//constructor with 0 parameters
Tiger::Tiger()
{
}

//constructor with an int for parameter to set the tiger's age
Tiger::Tiger(int a)
{
	age = a;
	cost = 10000;
	numberOfBabies = 1;
	baseFoodCost *= 5;
	payoff = cost / 5;
}



/*Tiger::~Tiger()
{

}*/

