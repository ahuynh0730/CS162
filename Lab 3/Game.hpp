/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  header file for Game class
*******************************************************************************/

#ifndef GAME_hpp
#define GAME_hpp

#include "Menu.hpp"
#include "Player.hpp"

class Game
{
private:
	Menu menu1;
	int numberOfRounds;
	Player p1;
	Player p2;
	const int MINROUNDS = 1;
	const int MAXROUNDS = 1000;
	const int MINSIDES = 2;
	const int MAXSIDES = 100;
	void roundOfRolling();

public:
	Game();
	bool startOrEnd();
	void setPlayerName();
	void setNumbRounds();
	void getDiceType();
	void setNumbSidesOfDice();
	void playGame();
	
};

#endif // !GAME_hpp

