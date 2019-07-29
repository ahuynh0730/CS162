#include "Pickle.hpp"



Pickle::Pickle()
{
	Space();
	spaceType = "PIC";
}

Pickle::Pickle(Space* topIn, Space* rightIn, Space* bottomIn, Space* leftIn)
{
	top = topIn;
	right = rightIn;
	bottom = bottomIn;
	left = leftIn;
	spaceType = "PIC";
}

Pickle::~Pickle()
{
}

std::deque<Space*> Pickle::interactWithSpace(std::deque<Space*> burgerIn)
{
	std::cout << "adding " << this->getSpaceType() << std::endl;
	burgerIn.push_back(new Pickle());
	return burgerIn;
}
