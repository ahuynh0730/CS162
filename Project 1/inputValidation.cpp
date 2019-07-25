/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  cpp file for input validation
*******************************************************************************/


#include "inputValidation.hpp"

#include <iostream>
#include <string>
#include <cctype>

//to check if user enters an integer that is between range and returns that number if between range
int integerCheck(int minOption, int maxOption)
{
	
	std::string userInput;
	bool allNumbers = false;
	int userChoice = 0;
	
	while (allNumbers == false || userChoice < minOption || userChoice > maxOption)
	{
		std::cin >> userInput;
		//loop that will check all characters of user input
		for (int i = 0; i < userInput.length(); i++)
		{
			//will leave loop upon first nondigit character
			if (!(isdigit(userInput[i])))
			{
				break;
			}

			//if all characters are digits
			else if (i == userInput.length() - 1)
			{
				allNumbers = true;
			}
		}

		if (allNumbers)
		{
			//changes user input to integer
			userChoice = std::stoi(userInput);
		}

		//will prompt for user input again
		if (allNumbers == false || userChoice < minOption || userChoice > maxOption)
		{
			std::cout << "Invalid option. Please enter an integer between " << minOption << " and "
				<< maxOption << std::endl;
		}

	}
	
	return userChoice;
}

