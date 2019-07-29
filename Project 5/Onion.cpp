#include "Onion.hpp"



Onion::Onion()
{
	Space();
	spaceType = "ONI";
}

Onion::Onion(Space* topIn, Space* rightIn, Space* bottomIn, Space* leftIn)
{
	top = topIn;
	right = rightIn;
	bottom = bottomIn;
	left = leftIn;
	spaceType = "ONI";
}


Onion::~Onion()
{
}

std::deque<Space*> Onion::interactWithSpace(std::deque<Space*> burgerIn)
{
	std::cout << "adding " << this->getSpaceType() << std::endl;
	burgerIn.push_back(new Onion());
	return burgerIn;
}
