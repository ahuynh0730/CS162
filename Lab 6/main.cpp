/********************************************

	By: Anthony Huynh
	Date: 11/4/2018
	Description: main file for linked lists program

*********************************************/

#include "inputValidation.hpp"
#include "Menu.hpp"
#include "DoublyLinkedList.hpp"
#include <iostream>

int main()
{
	int userChoice = -1;
	int valueToAdd;
	DoublyLinkedList doublyLinkedList1;

	//creating and displaying menu
	Menu menu1;
	menu1.addOption("Add a node to the head");
	menu1.addOption("Add a new node to the tail");
	menu1.addOption("Delete from head");
	menu1.addOption("Delete from tail");
	menu1.addOption("Traverse the list reversely");
	menu1.addOption("Display the value that the head is pointing to");
	menu1.addOption("Display the value that the tail is pointing to");
	menu1.addOption("Quit");

	while (userChoice != 8)
	{
		std::cout << "What would you like to do?" << std::endl;
		menu1.displayMenu();
		userChoice = integerCheck(1, menu1.getVectorSize());
		switch (userChoice)
		{
		case 1:
			std::cout << "Please enter a positive integer between 1 and 10000: ";
			valueToAdd = integerCheck(1, 10000);
			doublyLinkedList1.addToHead(valueToAdd);
			doublyLinkedList1.displayListForward();
			break;
		case 2:
			std::cout << "Please enter a positive integer between 1 and 10000: ";
			valueToAdd = integerCheck(1, 10000);
			doublyLinkedList1.addToTail(valueToAdd);
			doublyLinkedList1.displayListForward();
			break;
		case 3:
			doublyLinkedList1.deleteFromHead();
			doublyLinkedList1.displayListForward();
			break;
		case 4:
			doublyLinkedList1.deleteFromTail();
			doublyLinkedList1.displayListForward();
			break;
		case 5:
			doublyLinkedList1.displayListBackward();
			break;
		case 6:
			doublyLinkedList1.displayHeadValue();
			break;
		case 7:
			doublyLinkedList1.displayTailValue();
			break;
		case 8:
			break;
		}
	}
	
	doublyLinkedList1.deleteList();
	return 0;
}