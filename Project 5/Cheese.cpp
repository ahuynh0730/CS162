#include "Cheese.hpp"



Cheese::Cheese()
{
	Space();
	spaceType = "CHZ";
}

Cheese::Cheese(Space* topIn, Space* rightIn, Space* bottomIn, Space* leftIn)
{
	top = topIn;
	right = rightIn;
	bottom = bottomIn;
	left = leftIn;
	spaceType = "CHZ";
}


Cheese::~Cheese()
{
}

std::deque<Space*> Cheese::interactWithSpace(std::deque<Space*> burgerIn)
{
	std::cout << "adding " << this->getSpaceType() << std::endl;
	burgerIn.push_back(new Cheese());
	return burgerIn;
}
