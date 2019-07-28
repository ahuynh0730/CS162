/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  implementation file for menu class
*******************************************************************************/

#include "Menu.hpp"
#include <vector>
#include <string>
#include <iostream>



//to add an option to the menu
void Menu::addOption(std::string option)
{
	menuOptions.push_back(option);
}

//to display the menu
void Menu::displayMenu()
{
	for (int i = 0; i < menuOptions.size(); i++)
	{
		std::cout << i + 1 << ". " << menuOptions[i] << std::endl;
	}
}

//to clear menu
void Menu::clearMenu()
{
	menuOptions.clear();
}

