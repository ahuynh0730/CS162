/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: implementation file for medusa class

*****************************************************/

#include "Medusa.hpp"
#include <iostream>

//constructor that sets medusa's armor to 3 and strength to 8
//also creates dice for attack dice with 6 sides and defense dice with 6 sides, and sets characteristic and type string
Medusa::Medusa()
{
	armor = 3;
	strength = 8;
	attackDice = new Dice(6);
	defenseDice = new Dice(6);
	numberAttackRolls = 2;
	numberDefenseRolls = 1;
	characterType = "Medusa";
	characteristics = "Scrawny lady with snakes for hair which helps her during combat.Just don’t look at her! ";
}

//will call character class' attack
//if it is 12, then will set attack to 1000 
void Medusa::attackRoll()
{
	Character::attackRoll();
	if (attack == 12)
	{
		std::cout << "Medusa's glare was activated." << std::endl;
		attack = 1000;
	}
}