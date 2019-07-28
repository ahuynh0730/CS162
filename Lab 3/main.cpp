/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/14/2018
** Description:  main file for dice rolling game
*******************************************************************************/

#include "Game.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "LoadedDice.hpp"

using std::cout;
using std::endl;

int main()
{
	//to start random seed
	srand(time(0));

	Game game1;
	if (!game1.startOrEnd())
	{
		return 1;
	}
	game1.setPlayerName();
	game1.setNumbRounds();
	game1.getDiceType();
	game1.setNumbSidesOfDice();
	game1.playGame(); 

	
	/*LoadedDice dice1(6);
	dice1.roll();*/
	

	
	
	

	return 0;
}