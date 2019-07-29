#include "Meat.hpp"



Meat::Meat()
{
	Space();
	spaceType = "MEA";
}

Meat::Meat(Space * topIn, Space * rightIn, Space * bottomIn, Space * leftIn)
{
	top = topIn;
	right = rightIn;
	bottom = bottomIn;
	left = leftIn;
	spaceType = "MEA";
}


Meat::~Meat()
{
}


std::deque<Space*> Meat::interactWithSpace(std::deque<Space*> burgerIn)
{
	std::cout << "adding " << this->getSpaceType() << std::endl;
	burgerIn.push_back(new Meat());
	return burgerIn;
}
