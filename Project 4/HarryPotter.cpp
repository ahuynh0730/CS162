/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: implementation file for Harry Potter class

*****************************************************/

#include "HarryPotter.hpp"
#include <iostream>

//constructor that sets harry potter's armor to 0 and strength to 10
//also creates dice for attack dice with 6 sides and defense dice with 6 sides, and sets characteristic and type string
HarryPotter::HarryPotter()
{
	armor = 0;
	strength = 10;
	attackDice = new Dice(6);
	defenseDice = new Dice(6);
	numberAttackRolls = 2;
	numberDefenseRolls = 2;
	characterType = "Harry Potter";
	characteristics = "Harry Potter is a wizard. ";
}

HarryPotter::HarryPotter(std::string nameIn)
{
	armor = 0;
	strength = 10;
	attackDice = new Dice(6);
	defenseDice = new Dice(6);
	numberAttackRolls = 2;
	numberDefenseRolls = 2;
	characterType = "Harry Potter";
	characteristics = "Harry Potter is a wizard. ";
	characterName = nameIn;
}

//will call character class' update strength function and update strength
//if drops below 0 and hogwarts is false, then will use hogwarts
void HarryPotter::updateStrength(int damageTaken)
{
	Character::updateStrength(damageTaken);
	if (strength < 0 && Hogwarts == false)
	{
		std::cout << "Dobby has sacrified his life to save Harry Potter's life!" << std::endl;
		Hogwarts = true;
		strength = 20;
	}
}

HarryPotter::~HarryPotter()
{

}