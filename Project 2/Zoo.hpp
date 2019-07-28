/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/21/2018
** Description:  header file for Zoo class
*******************************************************************************/

#ifndef ZOO_hpp
#define ZOO_hpp

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Menu.hpp"

class Zoo
{
private:
	const int STARTING_ARRAY_SIZE = 10;
	int moneyInBank = 100000;
	Tiger* tigers;
	Penguin* penguins;
	Turtle* turtles;
	int day = 1;
	int animalsBought;
	int numberTigers;
	int numberPenguins;
	int numberTurtles;
	int bonusPayoff = 0;
	int profit;
	int currentTigerCapacity = STARTING_ARRAY_SIZE;
	int currentPenguinCapacity = STARTING_ARRAY_SIZE;
	int currentTurtleCapacity = STARTING_ARRAY_SIZE;
	void feedAnimals();
	void randomEvent();
	void sickness();
	void attendanceBoom();
	void babyBorn();
	void resizePenguinArray(Penguin*&, int&);
	void resizeTigerArray(Tiger*&, int&);
	void resizeTurtleArray(Turtle*&, int&);
	Menu menu1;

public:
	Zoo();
	void startDay();
	void deductCostOfAnimal(Animal);
	int getMoneyInBank();
	void deleteAnimalArrays();
	void endDay();
	void setMoney(int);


};

#endif // !ZOO_hpp

