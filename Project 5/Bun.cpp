#include "Bun.hpp"



Bun::Bun()
{
	Space();
	spaceType = "BUN";
}

Bun::Bun(Space* topIn, Space* rightIn, Space* bottomIn, Space* leftIn)
{
	top = topIn;
	right = rightIn;
	bottom = bottomIn;
	left = leftIn;
	spaceType = "BUN";
}

Bun::~Bun()
{
}

std::deque<Space*> Bun::interactWithSpace(std::deque<Space*> burgerIn)
{
	std::cout << "adding " << this->getSpaceType() << std::endl;
	burgerIn.push_back(new Bun());
	return burgerIn;
}
