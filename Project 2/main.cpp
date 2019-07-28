/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/21/2018
** Description:  main file for zoo simulation
*******************************************************************************/

#include "Zoo.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "inputValidation.hpp"
#include "Menu.hpp"


int main()
{
	srand(time(0));
	int continueGame = 1;
	Menu menu1;
	menu1.addOption("Yes");
	menu1.addOption("No");

	Zoo zoo;
	while (continueGame == 1 && zoo.getMoneyInBank() >= 0)
	{
		zoo.startDay();
		zoo.endDay();
		std::cout << "Would you like to keep playing?" << std::endl;
		menu1.displayMenu();
		continueGame = integerCheck(1, 2);
	}

	if (continueGame == 2 || zoo.getMoneyInBank() < 0)
	{
		if (zoo.getMoneyInBank() < 0)
		{
			std::cout << "You have no money in the bank. " << std::endl;
		}
		std::cout << "The game is now ending." << std::endl;
	}

	

	zoo.deleteAnimalArrays();
	return 0;
}