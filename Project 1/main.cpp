/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  main file for Langston's Ant
*******************************************************************************/

#include <iostream>
#include "inputValidation.hpp"
#include "Menu.hpp"
#include "Board.hpp"
#include "Ant.hpp"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	
	const int maxRows = 10000, maxColumns = 10000, maxSteps = 10000;

	Menu menu1;
	menu1.addOption("Start Langton's Ant Simulation");
	menu1.addOption("Quit");
	menu1.displayMenu();

	int userChoice = 0, numRows = 0, numColumns = 0, numSteps = 0, startRow = 0, startColumn = 0;
	userChoice = integerCheck(1, 2);

	while (userChoice == 1)
	{
		//to get info from user
		cout << "Please enter the number of rows: ";
		numRows = integerCheck(1, maxRows);

		cout << "Please enter the number of columns: ";
		numColumns = integerCheck(1, maxColumns);

		cout << "Please enter the number of steps that the ant should take: ";
		numSteps = integerCheck(0, maxSteps);

		//range for start row/column is between 1 and the numbered entered for rows/columns
		//the -1 is to account for index starting at 0
		cout << "What row would you like the ant to start at?: ";
		startRow = integerCheck(1, numRows) - 1;

		cout << "What column would you like the ant to start at?: ";
		startColumn = integerCheck(1, numColumns) - 1;

		Ant* ant1 = new Ant(startRow, startColumn);
		Board board(numRows, numColumns, ant1);


		board.fillGrid(numRows, numColumns);

		board.antPosition(startRow, startColumn);

		board.displayGrid(numRows, numColumns);



		//loop that moves ant appropiate number of times and displays board after moving
		for (int i = 0; i < numSteps; i++)
		{
			board.moveAnt();
			board.displayGrid(numRows, numColumns);
		}

		//asks the user if they want to play again
		menu1.clearMenu();
		menu1.addOption("Play Again");
		menu1.addOption("Quit");
		menu1.displayMenu();

		//causes loop to repeat if user selects 1
		userChoice = integerCheck(1, 2);

		board.deleteGrid(numRows);
		delete ant1;
	}

	//causes program to quit if user selects 2
	if (userChoice == 2)
		return 0;

	
	
	

	return 0;
}