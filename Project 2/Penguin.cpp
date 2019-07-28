/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/21/2018
** Description:  implementation file for Penguin class
*******************************************************************************/

#include "Penguin.hpp"

//constructor with 0 parameters
Penguin::Penguin()
{
}

//constructor with an int for parameter to set the penguin's age
Penguin::Penguin(int a)
{
	age = a;
	cost = 1000;
	numberOfBabies = 5;
	payoff = cost / 10;
}