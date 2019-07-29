/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: implementation file for vampire class

*****************************************************/

#include "Vampire.hpp"
#include <iostream>


//constructor that sets vampire's armor to 1 and strength to 18
//also creates dice for attack dice with 12 sides and defense dice with 6 sides, and sets characteristic and type string
Vampire::Vampire()
{
	armor = 1;
	strength = 18;
	attackDice = new Dice(12);
	defenseDice = new Dice(6);
	numberAttackRolls = 1;
	numberDefenseRolls = 1;
	characterType = "Vampire";
	characteristics = "Suave, debonair, but vicious and surprisingly resilient. ";
}

Vampire::Vampire(std::string nameIn)
{
	armor = 1;
	strength = 18;
	attackDice = new Dice(12);
	defenseDice = new Dice(6);
	numberAttackRolls = 1;
	numberDefenseRolls = 1;
	characterType = "Vampire";
	characteristics = "Suave, debonair, but vicious and surprisingly resilient. ";
	characterName = nameIn;
}

//function that activates Charm if an even number is rolled
//will set the bool charmActivated to true
void Vampire::defenseRoll()
{
	defense = defenseDice->roll();
	if (defense % 2 == 0)
	{
		std::cout << "Charm was activated. No damage will be taken this turn. " << std::endl;
		charmActivated = true;
	}
	else
	{
		charmActivated = false;
	}
}

//if charm was activated, will call character's calc damage with 0
//if charm was not activated, will call characters' calc damage with orignal attack taken
int Vampire::calcDamageTaken(int attackTaken)
{
	if (charmActivated == 0)
	{
		return Character::calcDamageTaken(attackTaken);
	}
	else
	{
		attackTaken = 0;
		return Character::calcDamageTaken(attackTaken);
	}
}

Vampire::~Vampire()
{

}

