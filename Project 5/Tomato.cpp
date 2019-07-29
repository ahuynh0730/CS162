#include "Tomato.hpp"



Tomato::Tomato()
{
	Space();
	spaceType = "TOM";
}

Tomato::Tomato(Space* topIn, Space* rightIn, Space* bottomIn, Space* leftIn)
{
	top = topIn;
	right = rightIn;
	bottom = bottomIn;
	left = leftIn;
	spaceType = "TOM";
}


Tomato::~Tomato()
{
}

std::deque<Space*> Tomato::interactWithSpace(std::deque<Space*> burgerIn)
{
	std::cout << "adding " << this->getSpaceType() << std::endl;
	burgerIn.push_back(new Tomato());
	return burgerIn;
}
