/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  header file for Dice class
*******************************************************************************/

#ifndef DICE_hpp
#define DICE_hpp

class Dice
{
protected:
	int numberOfSides;

public:
	Dice();
	Dice(int);
	int getNumbSides();
	virtual int roll();

};

#endif // !DICE_hpp

