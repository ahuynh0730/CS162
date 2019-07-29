#include "Trash.hpp"



Trash::Trash()
{
	Space();
	spaceType = "TRA";
}

Trash::Trash(Space* topIn, Space* rightIn, Space* bottomIn, Space* leftIn)
{
	top = topIn;
	right = rightIn;
	bottom = bottomIn;
	left = leftIn;
	spaceType = "TRA";
}


Trash::~Trash()
{
}

std::deque<Space*> Trash::interactWithSpace(std::deque<Space*> burgerIn)
{
	while (!burgerIn.empty())
	{
		delete burgerIn.front();
		burgerIn.pop_front();
	}
	return burgerIn;
}
