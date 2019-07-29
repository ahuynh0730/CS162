/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  cpp file for input validation
*******************************************************************************/


#include "inputValidation.hpp"

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

//to check if user enters an integer that is between range and returns that number if between range
/*int integerCheck(int minOption, int maxOption)
{
	std::string userInput;
	bool allNumbers = false;
	int userChoice = 0;

	while (allNumbers == false || userChoice < minOption || userChoice > maxOption)
	{
		std::getline(std::cin, userInput);
		//loop that will check all characters of user input
		for (unsigned int i = 0; i < userInput.length(); i++)
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
	
}*/

//to check if user enters a floating number within range and returns that number
//will repeat if student does not enter correct number
float floatCheck(float minNumber, float maxNumber)
{
	std::string userInput;
	bool isAFloat = false;
	float userChoice = 0;
	int decimalCount = 0;

	while (isAFloat == false || userChoice < minNumber || userChoice > maxNumber || decimalCount > 1)
	{
		decimalCount = 0;
		std::getline(std::cin, userInput);
		//loop that will check all characters of user input
		for (unsigned int i = 0; i < userInput.length(); i++)
		{
			//will leave loop upon first nondigit character
			if (userInput[i] != '.' && !(isdigit(userInput[i])))
			{
				break;
			}

			//will break out of loop if more than one decimal is found
			if (userInput[i] == '.')
			{
				decimalCount++;
				if (decimalCount > 1)
				{
					break;
				}
			}

			//if all characters are digits
			else if (i == userInput.length() - 1)
			{
				isAFloat = true;
			}
		}

		if (isAFloat)
		{
			//changes user input to integer
			userChoice = std::stof(userInput);
		}

		//will prompt for user input again
		if (isAFloat == false || userChoice < minNumber || userChoice > maxNumber || decimalCount > 1)
		{
			std::cout << std::fixed << std::setprecision(2) << "Invalid option. Please enter a real number between "
				<< minNumber << " and " << maxNumber << std::endl;
		}

	}

	return userChoice;
}

//to check if user enters an integer(positive or negative) that is between range and returns that number if between range
int integerCheck(int minOption, int maxOption)
{
	std::string userInput;
	bool allNumbers = false;
	int userChoice = 0;
	int negCount = 0;

	while (allNumbers == false || userChoice < minOption || userChoice > maxOption || negCount > 1)
	{
		negCount = 0;
		std::getline(std::cin, userInput);
		//loop that will check all characters of user input
		for (unsigned int i = 0; i < userInput.length(); i++)
		{
			//will leave loop upon first nondigit character or non negative sign
			if (!(isdigit(userInput[i])) && userInput[i] != '-')
			{
				break;
			}

			//will increment neg count upon each - sign
			//will request new input if more than one negative sign or negative sign isn't the first digit
			if (userInput[i] == '-')
			{
				negCount++;
				if (negCount > 1)
				{
					break;
				}
				if (i != 0)
				{
					negCount = 2;
					break;
				}
			}

			//if all characters are digits
			else if (i == userInput.length() - 1)
			{
				allNumbers = true;
			}
		}

		//changes user input to integer
		if (allNumbers)
		{
			userChoice = std::stoi(userInput);
		}

		//will prompt for user input again
		if (allNumbers == false || userChoice < minOption || userChoice > maxOption || negCount > 1)
		{
			std::cout << "Invalid option. Please enter an integer between " << minOption << " and "
				<< maxOption << std::endl;
		}

	}

	return userChoice;

}
