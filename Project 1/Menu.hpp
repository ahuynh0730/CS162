/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  header file for menu class
*******************************************************************************/

#ifndef MENU_hpp
#define MENU_hpp

#include <vector>
#include <string>

class Menu
{
private:
	std::vector<std::string> menuOptions;

public:
	void addOption(std::string);
	void displayMenu();
	void clearMenu();
};

#endif // !MENU_hpp
