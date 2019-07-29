/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: implementation file for character class

*****************************************************/

#include "Character.hpp"
#include <iostream>


//function that returns an int representing the characters' attack value
void Character::attackRoll()
{
	//loop that will roll dice the approximate number of times per character
	int attackSum = 0;
	for (int i = 0; i < numberAttackRolls; i++)
	{
		attackSum += attackDice->roll();
		//to wait 25 milliseconds before rolling next dice
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
	}
	attack = attackSum;
}

//function that returns an int representing the characters' defense value
void Character::defenseRoll()
{
	int defenseSum = 0;
	for (int i = 0; i < numberDefenseRolls; i++)
	{
		defenseSum += defenseDice->roll();
		//to wait 25 milliseconds before rolling next dice
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
	}
	defense = defenseSum;

}

//function that takes in an int (should be attack value) to determine amount of damage taken
int Character::calcDamageTaken(int attackTaken)
{
	int damageTaken = attackTaken - armor - defense;
	if (damageTaken > 0)
	{
		return damageTaken;
	}
	else
	{
		return 0;
	}
}

//will take an int, and subtract that int from strength
void Character::updateStrength(int damageTaken)
{
	strength -= damageTaken;
}

//function that returns character type
std::string Character::getCharacterType()
{
	return characterType;
}

int Character::getRemainingStrength()
{
	return strength;
}
int Character::getArmor()
{
	return armor;
}
int Character::getAttack()
{
	return attack;
}
int Character::getDefense()
{
	return defense;
}

//destructor that deletes dynamically allocated dice
Character::~Character()
{
	delete attackDice;
	delete defenseDice;
}