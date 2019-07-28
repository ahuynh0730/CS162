/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/14/2018
** Description:  implementation file for player
*******************************************************************************/

#include "Player.hpp"
#include <string>

void Player::setDiceSides(int diceSides)
{
	if (hasLoadedDice == false)
	{
		dice1 = new Dice(diceSides);
	}
	else if (hasLoadedDice == true)
	{
		dice1 = new LoadedDice(diceSides);
	}
}

void Player::setName(std::string nameIn)
{
	name = nameIn;
}

std::string Player::getName()
{
	return name;
}

void Player::rollDice()
{
	currentRoll = dice1->roll();
}

int Player::getRoll()
{
	return currentRoll;
}

void Player::win()
{
	score++;
}

int Player::getScore()
{
	return score;
}

Dice Player::getDice()
{
	return *dice1;
}

//sets hasLoadedDice to true and changes diceType string to loaded
void Player::diceIsLoaded()
{
	hasLoadedDice = true;
	diceType = "loaded";
}

std::string Player::getDiceTypeAsString()
{
	return diceType;
}

void Player::deleteDice()
{
	delete dice1;
}