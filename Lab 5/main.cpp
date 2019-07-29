/****************************************************

	Name: Anthony Huynh
	Date: 10/28/18
	Description: main file for recursion lab

******************************************************/

#include <string>
#include "Recursion.hpp"
#include <iostream>
#include "Menu.hpp"
#include "inputValidation.hpp"

int main()
{
	const int ARRAY_MAX = 100;
	const int MIN_INTEGER = 0;
	const int MAX_INTEGER = 100;
	const int MAX_TRIANGLE_NUMBER = 40;
	int userChoice = 0;
	std::string userString;
	std::string reversedString;
	int arraySize;
	int * array;
	int sumOfArray;
	int triangNumber;
	int triangSum;
	Menu menu1;
	menu1.addOption("Reverse a string.");
	menu1.addOption("Calculate the sum of an array of integers.");
	menu1.addOption("Calculates the triangle number of an integer.");
	menu1.addOption("Quit the program.");
	while (userChoice != 4)
	{
		menu1.displayMenu();
		userChoice = integerCheck(1, 4);
		switch (userChoice)
		{
		//if user chooses 1, will ask for string and call string reverse
		case 1:
			std::cout << "Please enter a string to be reversed using recursion. " << std::endl;
			std::getline(std::cin, userString);
			stringReverse(userString);
			break;
		// if user chooses 2, will ask for size of array and numbers to fill array
		//then call array sum function
		case 2:
			std::cout << "How many elements are in the array? ";
			arraySize = integerCheck(1, ARRAY_MAX);
			array = new int[arraySize];
			for (int i = 0; i < arraySize; i++)
			{
				std::cout << "What is array element " << i + 1 << "? ";
				array[i] = integerCheck(MIN_INTEGER, MAX_INTEGER);
			}
			sumOfArray = arraySum(array, arraySize);
			std::cout << "The sum of the array is " << sumOfArray << ". " << std::endl;
			delete array;
			break;
		//if user chose 3, then will ask for what number to calculate triangle number of
		case 3:
			std::cout << "What is the triangle number that you would like to calculate? ";
			triangNumber = integerCheck(1, MAX_TRIANGLE_NUMBER);
			triangSum = calcTriangNumber(triangNumber);
			std::cout << "The triangle number of " << triangNumber << " is " << triangSum << "." << std::endl;
			break;
		case 4:
			std::cout << "Program will now exit." << std::endl;
			return 0;
			break;
		}
	}
	return 0;
}
