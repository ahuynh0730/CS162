#ifndef PLAYER_hpp
#define Player_hpp

#include "Space.hpp"
#include "Ingredient.hpp"

#include <deque>
#include <iostream>

class Player
{
private:
	Space * currentSpace = nullptr;
	std::deque<Space*> Burger;

public:
	Player();
	Player(Space*);
	~Player();
	void moveToSpace(Space*);
	Space* getCurrentSpace();
	std::deque<Space*> getBurgerDeque();
	void setBurgerDeque(std::deque<Space*>);
};

#endif // !PLAYER_hpp