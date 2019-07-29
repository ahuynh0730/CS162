/*****************************************************

	Name: Anthony Huynh
	Date: 10/21/18
	Description: main file for OSU information system program

******************************************************/

#include "University.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main()
{
	srand(time(0));
	University university1;
	Menu menu1;

	
	int menuOption = 0;
	menu1.addOption("Create university from scratch.");
	menu1.addOption("Create university from existing file.");
	menu1.addOption("Exit the program. ");
	menu1.displayMenu();
	menuOption = integerCheck(1, 3);
	switch (menuOption)
	{
	case 1:
		university1.startUniversity();
		break;
	case 2:
		university1.readFromFile();
		break;
	case 3:
		std::cout << "Program will now end." << std::endl;
		return 1;
		break;
	}

	//to clear menu and then add new options
	menu1.clearMenu();
	menu1.addOption("Print information on all buildings. ");
	menu1.addOption("Print information on everbody at the university. ");
	menu1.addOption("Choose a person to do work. ");
	menu1.addOption("Add a building. ");
	menu1.addOption("Add a person. ");
	menu1.addOption("Save Data to file.");
	menu1.addOption("Exit the program. ");

	while (menuOption != 7)
	{
		menu1.displayMenu();
		menuOption = integerCheck(1, 7);
		switch (menuOption)
		{
		case 1:
			university1.displayBuildings();
			break;
		case 2:
			university1.displayPeopleInfo();
			break;
		case 3:
			university1.havePersonWork();
			break;
		case 4: 
			university1.addBuilding();
			break;
		case 5:
			university1.addPerson();
			break;
		case 6:
			university1.saveToFile();
			break;
		case 7:
			std::cout << "Program will now end." << std::endl;
			return 1;
			break;
		}

	}

	university1.~University();
	return 0;
}