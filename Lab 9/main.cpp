/**************************************************
	
	By: Anthony Huynh
	Date: 11/25/2018
	Description: This program will simulate a buffer that has a chance of adding numbers to a queue,
					as well as creating a palindrome string with a stack. 

*************************************************/


#include "inputValidation.hpp"
#include "Menu.hpp"
#include "Lab9Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>


int main()
{
	srand((unsigned int) time(0));
	Menu menu1;
	menu1.addOption("Simulate a buffer");
	menu1.addOption("Create a palindrome");
	menu1.addOption("Quit");
	int menuChoice = 0;
	menu1.displayMenu();
	menuChoice = integerCheck(1, 3);
	while (menuChoice != 3)
	{
		switch (menuChoice)
		{
		case 1:
			simulateBuffer();
			break;
		case 2:
			createPalindrome();
			break;
		}
		std::cout << "What would you like to do?" << std::endl;
		menu1.displayMenu();
		menuChoice = integerCheck(1, 3);
	}

	return 0;
}