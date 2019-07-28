/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/21/2018
** Description:  implementation file for Turtle class
*******************************************************************************/

#include "Turtle.hpp"

//constructor with 0 parameters
Turtle::Turtle()
{
}

//constructor with an int for parameter to set the tiger's age
Turtle::Turtle(int a)
{
	age = a;
	cost = 100;
	numberOfBabies = 10;
	baseFoodCost /= 2;
	payoff = cost / 20;
}