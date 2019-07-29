#pragma once
#include "Ingredient.hpp"
class Lettuce :
	public Ingredient
{
public:
	Lettuce();
	Lettuce(Space*, Space*, Space*, Space*);
	~Lettuce();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);
};

