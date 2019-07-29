#ifndef BOARD_hpp
#define BOARD_hpp

#include "Space.hpp"
#include "DeliverOrder.hpp"
#include "Trash.hpp"
#include "Ingredient.hpp"
#include "Bun.hpp"
#include "Pickle.hpp"
#include "Meat.hpp"
#include "Cheese.hpp"
#include "Onion.hpp"
#include "Tomato.hpp"
#include "Lettuce.hpp"
#include "Player.hpp"


#include <iostream>





class Board
{
private:
	Space * beginningOfGrid;
	Space* locationOfPlayer;
	Space* interactingSpace;
	DeliverOrder* orderLocation;
	const int numColumns = 5;
	const int numRows = 5;
	Player* p1;
	bool scored = false;

public:
	Board();
	~Board();
	void displayGrid();
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
	void displayIngredientList();
	bool getScoredResult();
	void resetBoolVars();
};

#endif // !1

