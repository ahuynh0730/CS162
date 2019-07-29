/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: implementation file for character class

*****************************************************/

#ifndef CHARACTER_hpp
#define CHARACTER_hpp

#include <string>
#include "Dice.hpp"
#include <chrono>		//chrono and thread are for when rolling multiple dice is neccessary to simulate 
#include <thread>		//dice rolls being random rather than one number after the next, obtained through stackoverflow

class Character
{
private:

protected:
	int attack;
	int defense;
	int armor;
	int strength;
	int numberAttackRolls;
	int numberDefenseRolls;
	std::string characterType;
	std::string characteristics;
	Dice* attackDice;
	Dice* defenseDice;


public:
	virtual void attackRoll();
	virtual void defenseRoll();
	virtual int calcDamageTaken(int);
	std::string getCharacterType();
	int getRemainingStrength();
	int getArmor();
	int getAttack();
	int getDefense();
	virtual void updateStrength(int);
	~Character();
};



#endif // !CHARACTER_hpp
