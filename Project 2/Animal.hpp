/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/21/2018
** Description:  header file for Animal class
*******************************************************************************/

#ifndef ANIMAL_hpp
#define ANIMAL_hpp

class Animal
{
protected:
	int age = -1;
	int cost;
	int numberOfBabies;
	int baseFoodCost = 10;
	int payoff;

public:
	int getCost();
	void increaseAge();
	int getFoodCost();
	int getAge();
	bool hasAdult(Animal*, int);
	int getNumberOfBabies();
	int getPayoff();


};

#endif // !ANIMAL_hpp

