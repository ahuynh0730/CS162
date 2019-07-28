/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/14/2018
** Description:  header file for loaded dice class
*******************************************************************************/

#ifndef LOADEDDICE_hpp
#define LOADEDDICE_hpp

#include "Dice.hpp"

class LoadedDice : public Dice
{
private:
	const int numberRerolls = 3;

public:
	LoadedDice(int);
	int roll();

};

#endif // !LOADEDDICE_hpp

