/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  cpp file for Game class
*******************************************************************************/

#include "Game.hpp"
#include <iostream>
#include <string>
#include "inputValidation.hpp"

//the next two include are to use sleep_for() function
#include <chrono>	
#include <thread>


//constructor that displays menu upon construction
Game::Game()
{
	menu1.addOption("Play Game");
	menu1.addOption("Exit Game");
	menu1.displayMenu();
}

//to determine if user wants to start game or end
bool Game::startOrEnd()
{
	//will return a 1 if user does not quit

	int userChoice = integerCheck(1, 2);
	if (userChoice == 2)
	{
		std::cout << "Program is now ending!" << std::endl;
		return 0;
	}
	return 1;
}

void Game::setPlayerName()
{
	std::string name;
	std::cout << "What is Player 1's name? ";
	std::cin >> name;
	p1.setName(name);

	std::cout << "What is Player 2's name? ";
	std::cin >> name;
	p2.setName(name);
}

//to get number of rounds from user that must be between 1 and 1000
void Game::setNumbRounds()
{
	std::cout << "How many rounds would you like to play? ";
	numberOfRounds = integerCheck(MINROUNDS, MAXROUNDS);
}

//to have user choose between loaded and regular dice
void Game::getDiceType()
{
	int diceOption = 0;
	std::cout << "What kind of dice would you like for " << p1.getName() << std::endl;
	menu1.clearMenu();
	menu1.addOption("Regular");
	menu1.addOption("Loaded");
	menu1.displayMenu();
	diceOption = integerCheck(1, 2);
	if (diceOption == 2)
	{
		p1.diceIsLoaded();
	}

	std::cout << "What kind of dice would you like for " << p2.getName() << std::endl;
	menu1.displayMenu();
	diceOption = integerCheck(1, 2);
	if (diceOption == 2)
	{
		p2.diceIsLoaded();
	}

}

//to have user decide number of sides for the dice for each player
void Game::setNumbSidesOfDice()
{
	int numbSides;
	std::cout << "How many sides will the dice for " << p1.getName() << " have? ";
	numbSides = integerCheck(MINSIDES, MAXSIDES);
	p1.setDiceSides(numbSides);

	std::cout << "How many sides will the dice for " << p2.getName() << " have? ";
	numbSides = integerCheck(MINSIDES, MAXSIDES);
	p2.setDiceSides(numbSides);
}

//each round of rolling, will also display detailed results after each round
void Game::roundOfRolling()
{
	//will pause for twenty milliseconds in between each roll to help seed be different numbers if 
	//dice have same number of sides
	p1.rollDice();
	std::this_thread::sleep_for(std::chrono::milliseconds(20)); //used stack overflow for this
	p2.rollDice();

	//to see which player won and increment their score accordingly
	if (p1.getRoll() > p2.getRoll())
	{
		p1.win();
	}
	else if (p1.getRoll() < p2.getRoll())
	{
		p2.win();
	}



	//to display detailed results of each roll
	std::cout << p1.getName() << " had a " << p1.getDice().getNumbSides() << " sided " << p1.getDiceTypeAsString()
		<< " dice and rolled a " << p1.getRoll() <<". Their new score is " << p1.getScore() << "." << std::endl;
	std::cout << p2.getName() << " had a " << p2.getDice().getNumbSides() << " sided " << p2.getDiceTypeAsString()
		<< " dice and rolled a " << p2.getRoll() <<". Their new score is " << p2.getScore() << "." << std::endl;
}

//to play game, will consist of calling round of rolling a certain number of times
//and will display final score and final winner of game after all rounds
void Game::playGame()
{
	for (int i = 0; i < numberOfRounds; i++)
	{
		std::cout << "Round " << i + 1 << ":" << std::endl;
		roundOfRolling();
		std::cout << std::endl;
	}

	std::cout << "          Final Score" << std::endl;
	std::cout << p1.getName() << " has " << p1.getScore() << " points." << std::endl;
	std::cout << p2.getName() << " has " << p2.getScore() << " points." << std::endl;

	if (p1.getScore() > p2.getScore())
	{
		std::cout << p1.getName() << " is the winner!!" << std::endl;
	}

	else if (p1.getScore() < p2.getScore())
	{
		std::cout << p2.getName() << " is the winner!!" << std::endl;
	}

	else if (p1.getScore() == p2.getScore())
	{
		std::cout << "This game ends in a tie!" << std::endl;
	}

	p1.deleteDice();
	p2.deleteDice();
}



