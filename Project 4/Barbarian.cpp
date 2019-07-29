/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: implementation file for barbarian class

*****************************************************/


#include "Barbarian.hpp"
#include <iostream>

//constructor that sets barbarian's armor to 0 and strength to 12
//also creates dice for attack dice with 6 sides and defense dice with 6 sides, and sets characteristic and type string
Barbarian::Barbarian()
{
	armor = 0;
	strength = 12;
	attackDice = new Dice(6);
	defenseDice = new Dice(6);
	numberAttackRolls = 2;
	numberDefenseRolls = 2;
	characterType = "Barbarian";
	characteristics = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso. ";
}

Barbarian::Barbarian(std::string nameIn)
{
	armor = 0;
	strength = 12;
	attackDice = new Dice(6);
	defenseDice = new Dice(6);
	numberAttackRolls = 2;
	numberDefenseRolls = 2;
	characterType = "Barbarian";
	characteristics = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso. ";
	characterName = nameIn;
}

Barbarian::~Barbarian()
{
}

