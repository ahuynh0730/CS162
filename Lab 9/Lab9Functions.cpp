/**************************************************

	By: Anthony Huynh
	Date: 11/25/2018
	Description: implementation file for any functions needed in lab 9

*************************************************/

#include "Lab9Functions.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <cstdlib>


//if user chose to simulate a buffer
void simulateBuffer()
{
	std::queue<int> queue1;
	int amountRounds;
	int userAddPercent;
	int userRemovePercent;
	int n;
	int randomPercent;
	float averageBufferLength = 0;

	std::cout << "How many rounds would you like to be simulated? ";
	amountRounds = integerCheck(0, 100);

	std::cout << "What is the percent that a randomly generated number will be added to the back? ";
	userAddPercent = integerCheck(0, 100);

	std::cout << "What is the percent that a randomly generated number will be removed from the front? ";
	userRemovePercent = integerCheck(0, 100);
	std::cout << std::endl;

	//to create random number and possibly add it to queue as well as remove a number
	for (int i = 0; i < amountRounds; i++)
	{
		std::cout << "Round " << i + 1 << ":" << std::endl;
		n = rand() % 1000 + 1;
		randomPercent = rand() % 100 + 1;

		//will add to queue if randomAddPercent is less than or equal to userAddPercent
		if (randomPercent <= userAddPercent)
		{
			queue1.push(n);
			std::cout << n << " added" << std::endl;
		}

		//will remove from queue if randomRemovePercent is less than or equal to userRemovePercent and queue is not empty
		randomPercent = rand() % 100 + 1;
		if ((randomPercent <= userRemovePercent) && (!queue1.empty()))
		{
			std::cout << "number removed" << std::endl;
			queue1.pop();

		}

		//will call function displaying buffer and length of buffer
		displayQueue(queue1);
		std::cout << std::endl << "Size of buffer is: " << queue1.size() << std::endl;


		//will calculate and display average length of buffer
		averageBufferLength = calcAverageLength(averageBufferLength, i + 1, queue1.size());
		std::cout << "The average buffer length is " << averageBufferLength << std::endl;

		std::cout << "Round " << i + 1 << " is over!" << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

}

//takes in a queue, and displays front, then pops it off and loops while full
void displayQueue(std::queue<int> queueIn)
{
	if (queueIn.empty())
	{
		std::cout << "Buffer is empty, nothing to display." << std::endl;
	}
	else
	{
		std::cout << "Buffer: " << std::endl;
		int numbOnLine = 0;
		while (!queueIn.empty())
		{
			//to display 10 per line, will move to new line if number is at 10 and reset number to 0
			if (numbOnLine == 10)
			{
				std::cout << std::endl;
				numbOnLine = 0;
			}
			std::cout << queueIn.front() << "   ";
			numbOnLine++;
			queueIn.pop();
		}
		
	}
	
}

//will calculate average length of buffer
float calcAverageLength(float lastAverage, int roundNumber, int bufferLength)
{
	return (lastAverage * (roundNumber - 1) + bufferLength) / roundNumber;
}

//if user decides to create a palindrom
void createPalindrome()
{
	std::stack<char> stack1;
	std::string userInput;
	std::string palindrome;

	std::cout << "What would you like to create a palindrome from? ";
	std::getline(std::cin, userInput);
	palindrome = userInput;
	
	//to push the string onto stack in reverse order
	for (unsigned int i = 0; i < userInput.length(); i++)
	{
		stack1.push(userInput.at(i));
	}

	//to append top of stack to palindrome and pop it off
	while (!stack1.empty())
	{
		palindrome.insert(palindrome.end(), stack1.top());
		stack1.pop();
	}
	

	
	std::cout << palindrome << std::endl << std::endl;
}