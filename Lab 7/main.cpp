/******************************************

	By: Anthony Huynh
	Date: 11/11/18
	Description: main file for creating a queue data structure utilizing circular linked list

**********************************************/

#include "Queue.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"
#include <iostream>

int main()
{
	//creating menu
	Menu menu1;
	menu1.addOption("Enter a value to be added to the back of the queue.");
	menu1.addOption("Display first node(front) value.");
	menu1.addOption("Remove first node(front) value.");
	menu1.addOption("Display the Queue contents.");
	menu1.addOption("Quit.");
	int userChoice = 0;
	int valueToAdd;

	//creating queue
	Queue queue1;
	while (userChoice != 5)
	{
		menu1.displayMenu();
		userChoice = integerCheck(1, menu1.getVectorSize());
		switch (userChoice)
		{
		case 1:
			std::cout << "Please enter a number between 1 and 1000." << std::endl;
			valueToAdd = integerCheck(1, 1000);
			queue1.addToBack(valueToAdd);
			break;
		case 2:
			if (!queue1.isEmpty())
			{
				std::cout << "The front value is " << queue1.getFront() << "." << std::endl;
			}
			else
			{
				std::cout << "Queue is empty." << std::endl;
			}
			break;
		case 3:
			if (!queue1.isEmpty())
			{
				std::cout << queue1.getFront() << " is being removed." << std::endl;
				queue1.removeFront();
			}
			else
			{
				std::cout << "Queue is empty." << std::endl;
			}
			break;
		case 4:
			queue1.displayQueue();
			break;
		case 5:
			break;
		}
	}

	
	return 0;
}