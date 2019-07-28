/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/21/2018
** Description:  implementation file for Animal class
*******************************************************************************/

#include "Animal.hpp"
#include <iostream>

int Animal::getCost()
{
	return cost;
}

void Animal::increaseAge()
{
	age++;
}

int Animal::getFoodCost()
{
	return baseFoodCost;
}

//if age is -1, animal either doesn't exist or has died
int Animal::getAge()
{
	return age;
}

bool Animal::hasAdult(Animal* animals, int numberOfAnimals)
{
	for (int i = 0; i < numberOfAnimals; i++)
	{
		if (animals[i].age >= 3)
			return true;
	}
	std::cout << "There were no adults, so no new babies were born." << std::endl;
	return false;
}


int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}

int Animal::getPayoff()
{
	return payoff;
}