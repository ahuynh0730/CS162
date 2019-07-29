/**********************************

	By: Anthony Huynh
	Date: 12/5/18
	Description:

***********************************/

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <string>



#include "Board.hpp"



int main()
{
	int stepsRemaining = 700;
	int score = 0;
	char movement = 'm';
	srand(time(0));
	std::string trashString;
	
	
	//instructions
	std::cout << "Welcome to Burger Mania!" << std::endl;
	std::cout << "The goal of this game is to gather ingredients to make a burger. " << std::endl
		<< "The ingredients needed will be listed, and you must gather them in the right order." << std::endl
		<< "Press 'w' to move/interact with the space above, 'd' for left, 's' for down, and 'a' for right." << std::endl
		<< "Any other buttons will perform no actions. If your ingredients are not the in the same order, the burger will be wrong." << std::endl
		<< "Your ingredients will not be listed. If you mess up you must toss what you have in the trash." << std::endl
		<< "You have 700 steps to get a score of 1000 or more." << std::endl
		<< "Key: DEL = Deliver		BUN = Bun		TRA = Trash" << std::endl
		<< "     PIC = Pickle		MEA = Meat		CHZ = Cheese" << std::endl
		<< "     ONI = Onion		TOM = Tomato		LET = Lettuce" << std::endl
		<< "Press enter to begin." << std::endl;

	std::getline(std::cin, trashString);

	Board game1;
	
	//will loop while steps are not 0 and decrement steps after each loop
	//gets input from user to move and collect ingredients and deliver items
	while (stepsRemaining > 0)
	{
		std::cout << "Steps remaining: " << stepsRemaining << std::endl;


		std::cout << "Score: " << score << std::endl;
		game1.displayGrid();
		game1.displayIngredientList();
		
		std::cout << std::endl;
		std::cin >> movement;
		switch (movement)
		{
		case 'w':
			game1.moveUp();
			stepsRemaining--;
			break;
		case 'd':
			game1.moveRight();
			stepsRemaining--;
			break;
		case 's':
			game1.moveDown();
			stepsRemaining--;
			break;
		case 'a':
			game1.moveLeft();
			stepsRemaining--;
			break;
		}
		if (game1.getScoredResult())
		{
			score += 100;
			game1.resetBoolVars();
		}
		std::cout << "Score: " << score << std::endl;
		game1.displayGrid();
		game1.displayIngredientList();

	}

	if (score >= 1000)
	{
		std::cout << "You have won the game!" << std::endl;
	}
	else
	{
		std::cout << "You have lost the game!" << std::endl;
	}
	return 0;
}

