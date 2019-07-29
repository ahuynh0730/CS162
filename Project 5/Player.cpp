#include "Player.hpp"



Player::Player()
{
}

//constructor that takes a space pointer which will point on which space the character is on
Player::Player(Space* spaceIn)
{
	currentSpace = spaceIn;
}


//will delete dynamically allocated deque
Player::~Player()
{
	while (!Burger.empty())
	{
		delete Burger.front();
		Burger.pop_front();
	}
}

//will have space pointer point to new space that character should be on
void Player::moveToSpace(Space* spaceIn)
{
	currentSpace->removePlayer();
	currentSpace = spaceIn;
	currentSpace->placePlayer();
}

Space * Player::getCurrentSpace()
{
	return currentSpace;
}

std::deque<Space*> Player::getBurgerDeque()
{
	return Burger;
}

void Player::setBurgerDeque(std::deque<Space*> burgerIn)
{
	Burger = burgerIn;
}


