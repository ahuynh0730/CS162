/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/14/2018
** Description:  header file for player class
*******************************************************************************/

#ifndef PLAYER_hpp
#define PLAYER_hpp

#include <string>
#include "Dice.hpp"
#include "LoadedDice.hpp"


class Player
{
private:
	std::string name;
	Dice* dice1;
	int currentRoll;
	int score;
	bool hasLoadedDice = false;
	std::string diceType = "regular";

public:
	void setDiceSides(int);
	void setName(std::string);
	std::string getName();
	void rollDice();
	int getRoll();
	void win();
	int getScore();
	void diceIsLoaded();
	std::string getDiceTypeAsString();
	void deleteDice();

	Dice getDice();
};

#endif // !PLAYER_hpp

