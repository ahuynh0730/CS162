#include "Space.hpp"




Space::Space()
{
	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
}

Space::Space(Space* topIn, Space* rightIn, Space* bottomIn, Space* leftIn)
{
	top = topIn;
	right = rightIn;
	bottom = bottomIn;
	left = leftIn;
}


Space::~Space()
{
}

Space* Space::getTopPointer()
{
	return top;
}

void Space::setTopPointer(Space* topIn)
{
	top = topIn;
}

Space* Space::getRightPointer()
{
	return right;
}

void Space::setRightPointer(Space * rightIn)
{
	right = rightIn;
}

Space* Space::getBottomPointer()
{
	return bottom;
}

void Space::setBottomPointer(Space * bottomIn)
{
	bottom = bottomIn;
}

Space* Space::getLeftPointer()
{
	return left;
}

void Space::setLeftPointer(Space * leftIn)
{
	left = leftIn;
}

std::string Space::getSpaceType()
{
	if (hasPlayer)
	{
		return " * ";
	}
	else
	{
		return spaceType;
	}
}

bool Space::holdsPlayer()
{
	if (hasPlayer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Space::placePlayer()
{
	hasPlayer = true;
}

void Space::removePlayer()
{
	hasPlayer = false;
}

std::deque<Space*> Space::interactWithSpace(std::deque<Space*> dequeIn)
{
	return dequeIn;
}





