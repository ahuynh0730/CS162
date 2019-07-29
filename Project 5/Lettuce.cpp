#include "Lettuce.hpp"



Lettuce::Lettuce()
{
	Space();
	spaceType = "LET";

}

Lettuce::Lettuce(Space* topIn, Space* rightIn, Space* bottomIn, Space* leftIn)
{
	top = topIn;
	right = rightIn;
	bottom = bottomIn;
	left = leftIn;
	spaceType = "LET";
}


Lettuce::~Lettuce()
{
}

std::deque<Space*> Lettuce::interactWithSpace(std::deque<Space*> burgerIn)
{
	std::cout << "adding " << this->getSpaceType() << std::endl;
	burgerIn.push_back(new Lettuce());
	return burgerIn;
}
