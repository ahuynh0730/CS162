/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: implementation file for blue men class

*****************************************************/

#include "BlueMen.hpp"

//constructor that sets BlueMen's armor to 3 and strength to 12
//also creates dice for attack dice with 10 sides and defense dice with 6 sides, and sets characteristic and type string
BlueMen::BlueMen()
{
	armor = 3;
	strength = 12;
	attackDice = new Dice(10);
	defenseDice = new Dice(6);
	numberAttackRolls = 2;
	numberDefenseRolls = 3;
	characterType = "Blue Men";
	characteristics = "	They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage.They can also do a LOT of damage when they crawl inside enemies’ armor or clothing. ";
}

BlueMen::BlueMen(std::string nameIn)
{
	armor = 3;
	strength = 12;
	attackDice = new Dice(10);
	defenseDice = new Dice(6);
	numberAttackRolls = 2;
	numberDefenseRolls = 3;
	characterType = "Blue Men";
	characteristics = "	They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage.They can also do a LOT of damage when they crawl inside enemies’ armor or clothing. ";
	characterName = nameIn;
}

//will use strength to determine number of dice, and then call the defense roll from character class
void BlueMen::defenseRoll()
{
	switch (strength)
	{
	case 12:
	case 11:
	case 10:
	case 9:
		numberDefenseRolls = 3;
		break;
	case 8:
	case 7:
	case 6:
	case 5:
		numberDefenseRolls = 2;
		break;
	case 4:
	case 3:
	case 2:
	case 1:
		numberDefenseRolls = 1;
		break;
	default:
		break;
	}
	Character::defenseRoll();
}

BlueMen::~BlueMen()
{

}