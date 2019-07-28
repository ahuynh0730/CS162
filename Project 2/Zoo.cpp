/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/21/2018
** Description:  implementation file for Zoo class
*******************************************************************************/

#include "Zoo.hpp"
#include <iostream>
#include "inputValidation.hpp"
#include <array>
#include <iterator>
#include <algorithm>

//constructor that creates 3 arrays, one per animal
//I use a const int that equals 10 rather than an integer 10 to initialize each
//array so that this could easily be changed to a different size if desired in the future

Zoo::Zoo()
{
	tigers = new Tiger[STARTING_ARRAY_SIZE];
	penguins = new Penguin[STARTING_ARRAY_SIZE];
	turtles = new Turtle[STARTING_ARRAY_SIZE];
}


//function that will begin start of each day
//will have an if statement to different day 1 activites
//from rest of days

void Zoo::startDay()
{
	std::cout << "Welcome to the start of day " << day << "." << std::endl;
	std::cout << "You have " << moneyInBank << " at the beginning of day " << day << "." << std::endl;
	//Asking user how many animals to buy at the start of day 1
	if (day == 1)
	{
		//how many tigers to start with
		std::cout << "Would you like to buy 1 or 2 tigers to start with? ";
		animalsBought = integerCheck(1, 2);
		for (int i = 0; i < animalsBought; i++)
		{
			tigers[i] = Tiger(1);
			deductCostOfAnimal(tigers[i]);
		}
		numberTigers = animalsBought;
	

		//how many penguins to start with
		std::cout << "Would you like to buy 1 or 2 penguins to start with? ";
		animalsBought = integerCheck(1, 2);
		for (int i = 0; i < animalsBought; i++)
		{
			penguins[i] = Penguin(1);
			deductCostOfAnimal(penguins[i]);
		}
		numberPenguins = animalsBought;

		//how many turtles to start with
		std::cout << "Would you like to buy 1 or 2 turtles to start with? ";
		animalsBought = integerCheck(1, 2);
		for (int i = 0; i < animalsBought; i++)
		{
			turtles[i] = Turtle(1);
			deductCostOfAnimal(turtles[i]);
		}
		numberTurtles = animalsBought;
	}
	//if day is greater than 1, then will age each animal, feed them, and cause a random event
	else if (day > 1)
	{
		//to start aging each animal by a day
		for (int i = 0; i < numberTigers ; i++)
		{
			tigers[i].increaseAge();
		}

		for (int i = 0; i < numberPenguins; i++)
		{
			penguins[i].increaseAge();
		}

		for (int i = 0; i < numberTurtles; i++)
		{
			turtles[i].increaseAge();
		}

		feedAnimals();
		randomEvent();

	}
}



//function that buys an animal
//will decrease cost of animal from money in bank

void Zoo::deductCostOfAnimal(Animal a)
{
	moneyInBank -= a.getCost();
}

int Zoo::getMoneyInBank()
{
	return moneyInBank;
}

void Zoo::deleteAnimalArrays()
{
	delete[] tigers;
	delete[] penguins;
	delete[] turtles;
}

//function for feeding animals and subtracting cost from money in bank
void Zoo::feedAnimals()
{
	for (int i = 0; i < numberTigers; i++)
	{
		moneyInBank -= tigers[i].getFoodCost();
	}

	for (int i = 0; i < numberPenguins; i++)
	{
		moneyInBank -= penguins[i].getFoodCost();
	}

	for (int i = 0; i < numberTurtles; i++)
	{
		moneyInBank -= turtles[i].getFoodCost();
	}
}

//random event that happens in the zoo
void Zoo::randomEvent()
{
	int randomEventNumber = (rand() % 3) + 1;
	switch (randomEventNumber)
	{
	case 1:
		sickness();
		break;
	case 2:
		attendanceBoom();
		break;
	case 3:
		babyBorn();
		break;
	default:
		break;
	}
}

//function if random event is sickness
void Zoo::sickness()
{
	int animalKilled = (rand() % 3 + 1);
	switch (animalKilled)
	{
	//to kill a tiger
	case 1:
		std::cout << "A kid has fallen in the tiger pen causing a tiger to die from "
			<< "fright of the sound of the kid landing!" << std::endl;
		tigers[numberTigers - 1] = Tiger(-1);
		numberTigers--;
		break;
	//to kill a penguin
	case 2:
		std::cout << "A kid fell into the penguin's enclosure and began to drown. A brave and valiant penguin"
			<< " swam over to save the kid. This penguin did not think of the weight difference between the "
			<< "5 pound penguin and the 100 pound kid. The kid smooshed the penguin until the penguin could "
			<< "no longer breathe." << std::endl;
		penguins[numberPenguins - 1] = Penguin(-1);
		numberPenguins--;
		break;
	//to kill a turtle
	case 3:
		std::cout << "A kid was eating a salad, then all of a sudden, he fell into the turtles' enclosure. One "
			<< "of the turtles was quite hungry and 'sped' over to take the salad from the kid. 10 minutes later, this "
			<< "turtle was spotted, and a zookeeper had to put the turtle down for the safety of the kid." << std::endl;
		turtles[numberTurtles - 1] = Turtle(-1);
		numberTurtles--;
		break;
	default:
		break;
	}
}

//function for when there is an attendance boom in the zoo
void Zoo::attendanceBoom()
{
	//random number will be chosen between 0 and 250, then add 250 to put it between 250 and 500
	int bonusPayoffAmount = (rand() % 251) + 250;
	std::cout << "You got an extra " << bonusPayoffAmount << " per tiger today!" << std::endl;
	bonusPayoff = bonusPayoffAmount * numberTigers;
}

//function for when a baby/babies are born
void Zoo::babyBorn()
{
	//to pick an animal
	int babyChoice = (rand() % 3) + 1;
	int pendingBabies;
	switch (babyChoice)
	{
	//if tiger is chosen
	case 1:
		if (tigers->hasAdult(tigers, numberTigers))
		{
			pendingBabies = tigers->getNumberOfBabies();
			//will resize array if pendingBabies plus number of Tigers is greater than capacity of array
			if (pendingBabies + numberTigers > currentTigerCapacity)
			{
				resizeTigerArray(tigers, currentTigerCapacity);
			}
			//will create new babies and increase number of tigers
			for (int i = 0; i < pendingBabies; i++)
			{
				tigers[numberTigers] = Tiger(0);
				numberTigers++;
			}
			std::cout << "1 tiger was born! You now have " << numberTigers << " tigers!" << std::endl;
		}
		break;
	//if penguin is chosen
	case 2:
		if (penguins->hasAdult(penguins, numberPenguins))
		{
			pendingBabies = penguins->getNumberOfBabies();
			//will resize array if pendingBabies plus number of penguins is greater than capacity of array
			if (pendingBabies + numberPenguins > currentPenguinCapacity)
			{
				resizePenguinArray(penguins, currentPenguinCapacity);
			}
			//will create new babies and increase number of penguins
			for (int i = 0; i < pendingBabies; i++)
			{
				penguins[numberPenguins] = Penguin(0);
				numberPenguins++;
			}
			std::cout << "5 penguins were born! You now have " << numberPenguins << " penguins!" << std::endl;
			
		}
		break;
	//for when turtles are chosen
	case 3:
		if (turtles->hasAdult(turtles, numberTurtles))
		{
			pendingBabies = turtles->getNumberOfBabies();
			//will resize array if pendingBabies plus number of turtles is greater than capacity of array
			if (pendingBabies + numberTurtles > currentTurtleCapacity)
			{
				resizeTurtleArray(turtles, currentTurtleCapacity);
			}
			//will create new babies and increase number of penguins
			for (int i = 0; i < pendingBabies; i++)
			{
				turtles[numberTurtles] = Turtle(0);
				numberTurtles++;
			}
			std::cout << "10 turtles were born! You now have " << numberTurtles << " turtles!" << std::endl;
		}
		break;
	default:
		break;
	}
}

//to double current array capacity for penguins if incoming animals would put it over its capacity
void Zoo::resizePenguinArray(Penguin*& penguins, int& arrayCapacity)
{
	int newArrayCapacity = arrayCapacity * 2;
	Penguin * newPenguins;
	newPenguins = new Penguin[newArrayCapacity];
	for (int i = 0; i < arrayCapacity; i++)
	{
		newPenguins[i] = penguins[i];
	}
	delete[] penguins;
	penguins = newPenguins;
	arrayCapacity = newArrayCapacity;
}

//to double current array capacity for turtles if incoming animals would put it over its capacity
void Zoo::resizeTurtleArray(Turtle*& turtles, int& arrayCapacity)
{
	int newArrayCapacity = arrayCapacity * 2;
	Turtle * newTurtles;
	newTurtles = new Turtle[newArrayCapacity];
	for (int i = 0; i < arrayCapacity; i++)
	{
		newTurtles[i] = turtles[i];
	}
	delete[] turtles;
	turtles = newTurtles;
	arrayCapacity = newArrayCapacity;
}

//to double current array capacity for tigers if incoming animals would put it over its capacity
void Zoo::resizeTigerArray(Tiger*& turtles, int& arrayCapacity)
{
	int newArrayCapacity = arrayCapacity * 2;
	Tiger * newTigers;
	newTigers = new Tiger[newArrayCapacity];
	for (int i = 0; i < arrayCapacity; i++)
	{
		newTigers[i] = tigers[i];
	}
	delete[] tigers;
	tigers = newTigers;
	arrayCapacity = newArrayCapacity;
}

//function for the end of the day
void Zoo::endDay()
{

	//calculate and display payoff/bonus
	profit = (numberTigers * tigers[0].getPayoff()) + (numberPenguins * penguins[0].getPayoff()) +
		(numberTurtles * turtles[0].getPayoff());
	std::cout << "You made " << profit << " dollars today from your animals!" << std::endl;
	if (bonusPayoff != 0)
	{
		std::cout << "You also made " << bonusPayoff << " from an attendance boom today!" << std::endl;
	}
	moneyInBank += profit;
	moneyInBank += bonusPayoff;
	bonusPayoff = 0;
	

	//asks users if they want to buy a new animal
	std::cout << "Would you like to buy a new adult animal?" << std::endl;
	menu1.addOption("Tiger");
	menu1.addOption("Penguin");
	menu1.addOption("Turtle");
	menu1.addOption("No");
	menu1.displayMenu();
	menu1.clearMenu();

	//switch statement based on user's choice
	int userChoice = integerCheck(1, 4);
	switch (userChoice)
	{
	case 1:
		if (numberTigers + 1> currentTigerCapacity)
		{
			resizeTigerArray(tigers, currentTigerCapacity);
		}
		tigers[numberTigers] = Tiger(3);
		numberTigers++;
		deductCostOfAnimal(tigers[0]);
		std::cout << "You bought a tiger! Now you have " << numberTigers << " tigers!" << std::endl;
		break;
	case 2:
		if (numberPenguins + 1 > currentPenguinCapacity)
		{
			resizePenguinArray(penguins, currentPenguinCapacity);
		}
		penguins[numberPenguins] = Penguin(3);
		numberPenguins++;
		deductCostOfAnimal(penguins[0]);
		std::cout << "You bought a penguin! Now you have " << numberPenguins << " penguins!" << std::endl;
		break;
	case 3:
		if (numberTurtles + 1 > currentTurtleCapacity)
		{
			resizeTurtleArray(turtles, currentTurtleCapacity);
		}
		turtles[numberTurtles] = Turtle(3);
		numberTurtles++;
		deductCostOfAnimal(turtles[0]);
		std::cout << "You bought a turtle! Now you have " << numberTurtles << " turtles!" << std::endl;
		break;
	default:
		break;
	}

	std::cout << "You are ending day " << day << " with " << moneyInBank << " dollars." << std::endl;

	//to increment day
	day++;
}


void Zoo::setMoney(int a)
{
	moneyInBank = a;
}