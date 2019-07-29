#include "Board.hpp"


//creates grid of spaces and player
Board::Board()
{
	//beginningOfGrid will always point to top left space
	orderLocation = new DeliverOrder(nullptr, nullptr, nullptr, nullptr);
	beginningOfGrid = orderLocation;
	//to set the first row of spaces
	Space* tempPtr = beginningOfGrid;
	tempPtr->setRightPointer(new Space(nullptr, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	p1 = new Player(tempPtr);
	locationOfPlayer = tempPtr;
	tempPtr->placePlayer();
	tempPtr->setRightPointer(new Bun(nullptr, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr->setRightPointer(new Space(nullptr, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr->setRightPointer(new Trash(nullptr, nullptr, nullptr, tempPtr));
	

	//to set the second row of spaces
	Space* tempPtr2 = beginningOfGrid;
	tempPtr = beginningOfGrid;
	tempPtr->setBottomPointer(new Space(tempPtr, nullptr, nullptr, nullptr));
	tempPtr = tempPtr->getBottomPointer();
	for (unsigned int i = 0; i < 4; i++)
	{
		tempPtr2 = tempPtr2->getRightPointer();
		tempPtr->setRightPointer(new Space(tempPtr2, nullptr, nullptr, tempPtr));
		tempPtr = tempPtr->getRightPointer();
		tempPtr2->setBottomPointer(tempPtr);
	}

	//to set the third row of spaces
	tempPtr = beginningOfGrid->getBottomPointer();
	tempPtr2 = beginningOfGrid->getBottomPointer();
	tempPtr->setBottomPointer(new Pickle(tempPtr, nullptr, nullptr, nullptr));
	tempPtr = tempPtr->getBottomPointer();
	tempPtr2 = tempPtr2->getRightPointer();
	tempPtr->setRightPointer(new Space(tempPtr2, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr2->setBottomPointer(tempPtr);

	tempPtr2 = tempPtr2->getRightPointer();
	tempPtr->setRightPointer(new Meat(tempPtr2, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr2->setBottomPointer(tempPtr);

	tempPtr2 = tempPtr2->getRightPointer();
	tempPtr->setRightPointer(new Space(tempPtr2, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr2->setBottomPointer(tempPtr);

	tempPtr2 = tempPtr2->getRightPointer();
	tempPtr->setRightPointer(new Cheese(tempPtr2, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr2->setBottomPointer(tempPtr);

	//to set the fourth row
	tempPtr = beginningOfGrid;
	tempPtr2 = beginningOfGrid;
	while (tempPtr->getBottomPointer() != nullptr)
	{
		tempPtr = tempPtr->getBottomPointer();
		tempPtr2 = tempPtr2->getBottomPointer();
	}
	tempPtr->setBottomPointer(new Space(tempPtr, nullptr, nullptr, nullptr));
	tempPtr = tempPtr->getBottomPointer();
	for (unsigned int i = 0; i < 4; i++)
	{
		tempPtr2 = tempPtr2->getRightPointer();
		tempPtr->setRightPointer(new Space(tempPtr2, nullptr, nullptr, tempPtr));
		tempPtr = tempPtr->getRightPointer();
		tempPtr2->setBottomPointer(tempPtr);
	}

	//to set the fifth row
	tempPtr = beginningOfGrid;
	tempPtr2 = beginningOfGrid;
	while (tempPtr->getBottomPointer() != nullptr)
	{
		tempPtr = tempPtr->getBottomPointer();
		tempPtr2 = tempPtr2->getBottomPointer();
	}
	tempPtr->setBottomPointer(new Onion(tempPtr, nullptr, nullptr, nullptr));
	tempPtr = tempPtr->getBottomPointer();
	tempPtr2 = tempPtr2->getRightPointer();
	tempPtr->setRightPointer(new Space(tempPtr2, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr2->setBottomPointer(tempPtr);

	tempPtr2 = tempPtr2->getRightPointer();
	tempPtr->setRightPointer(new Tomato(tempPtr2, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr2->setBottomPointer(tempPtr);

	tempPtr2 = tempPtr2->getRightPointer();
	tempPtr->setRightPointer(new Space(tempPtr2, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr2->setBottomPointer(tempPtr);

	tempPtr2 = tempPtr2->getRightPointer();
	tempPtr->setRightPointer(new Lettuce(tempPtr2, nullptr, nullptr, tempPtr));
	tempPtr = tempPtr->getRightPointer();
	tempPtr2->setBottomPointer(tempPtr);

}

//deletes all dynamic memory
Board::~Board()
{
	Space* tempPtr;
	Space* tempPtr2;

	//to delete first row
	tempPtr = beginningOfGrid;
	tempPtr2 = beginningOfGrid;
	beginningOfGrid = beginningOfGrid->getBottomPointer();
	tempPtr = tempPtr->getRightPointer();
	tempPtr2 = tempPtr2->getRightPointer();
	delete orderLocation;
	while (tempPtr->getRightPointer() != nullptr)
	{
		tempPtr2 = tempPtr2->getRightPointer();
		delete tempPtr;
		tempPtr = tempPtr2;
	}
	delete tempPtr;

	//loop will delete all but last row
	while (beginningOfGrid->getBottomPointer() != nullptr)
	{
		tempPtr = beginningOfGrid;
		tempPtr2 = beginningOfGrid;
		beginningOfGrid = beginningOfGrid->getBottomPointer();
		while (tempPtr->getRightPointer() != nullptr)
		{
			tempPtr2 = tempPtr2->getRightPointer();
			delete tempPtr;
			tempPtr = tempPtr2;
		}
		delete tempPtr;
		
	}
	//deletes last row
	tempPtr = beginningOfGrid;
	tempPtr2 = beginningOfGrid;
	while (tempPtr->getRightPointer() != nullptr)
	{
		tempPtr2 = tempPtr2->getRightPointer();
		delete tempPtr;
		tempPtr = tempPtr2;
	}
	delete tempPtr2;
	delete p1;
}

void Board::displayGrid()
{
	Space* tempPtr;
	Space* tempPtr2;
	tempPtr = beginningOfGrid;
	tempPtr2 = beginningOfGrid;
	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << " ---  ---  ---  ---  ---" << std::endl;
		for (unsigned int i = 0; i < 5; i++)
		{
			std::cout << "|" << tempPtr->getSpaceType() << "|";
			tempPtr = tempPtr->getRightPointer();
		}
		tempPtr2 = tempPtr2->getBottomPointer();
		tempPtr = tempPtr2;
		std::cout << std::endl;
		std::cout << " ---  ---  ---  ---  ---" << std::endl;
	}
}

//movement functions will either move character up or interact with space if it cannot be walked on
void Board::moveUp()
{
	if ((locationOfPlayer->getTopPointer() != nullptr) && (locationOfPlayer->getTopPointer()->getSpaceType() == "   "))
	{
		p1->moveToSpace(locationOfPlayer->getTopPointer());
		locationOfPlayer = p1->getCurrentSpace();
	}
	else if ((locationOfPlayer->getTopPointer() != nullptr) && (locationOfPlayer->getTopPointer()->getSpaceType() != "   "))
	{
		interactingSpace = locationOfPlayer->getTopPointer();
		p1->setBurgerDeque(interactingSpace->interactWithSpace(p1->getBurgerDeque()));

		scored = orderLocation->getValidOrder();
	
	}

}

void Board::moveRight()
{
	if ((locationOfPlayer->getRightPointer() != nullptr) && (locationOfPlayer->getRightPointer()->getSpaceType() == "   "))
	{
		p1->moveToSpace(locationOfPlayer->getRightPointer());
		locationOfPlayer = p1->getCurrentSpace();
	}
	else if ((locationOfPlayer->getRightPointer() != nullptr) && (locationOfPlayer->getRightPointer()->getSpaceType() != "   "))
	{
		interactingSpace = locationOfPlayer->getRightPointer();
		p1->setBurgerDeque(interactingSpace->interactWithSpace(p1->getBurgerDeque()));

	}
}

void Board::moveDown()
{
	if ((locationOfPlayer->getBottomPointer() != nullptr) && (locationOfPlayer->getBottomPointer()->getSpaceType() == "   "))
	{
		p1->moveToSpace(locationOfPlayer->getBottomPointer());
		locationOfPlayer = p1->getCurrentSpace();
	}
	else if ((locationOfPlayer->getBottomPointer() != nullptr) && (locationOfPlayer->getBottomPointer()->getSpaceType() != "   "))
	{
		interactingSpace = locationOfPlayer->getBottomPointer();
		p1->setBurgerDeque(interactingSpace->interactWithSpace(p1->getBurgerDeque()));

	}
}

void Board::moveLeft()
{
	if ((locationOfPlayer->getLeftPointer() != nullptr) && (locationOfPlayer->getLeftPointer()->getSpaceType() == "   "))
	{
		p1->moveToSpace(locationOfPlayer->getLeftPointer());
		locationOfPlayer = p1->getCurrentSpace();
	}
	else if ((locationOfPlayer->getLeftPointer() != nullptr) && (locationOfPlayer->getLeftPointer()->getSpaceType() != "   "))
	{
		interactingSpace = locationOfPlayer->getLeftPointer();
		p1->setBurgerDeque(interactingSpace->interactWithSpace(p1->getBurgerDeque()));

		scored = orderLocation->getValidOrder();
	}
}

void Board::displayIngredientList()
{
	std::cout << "Ingredients: ";
	for (unsigned int i = 0; i < orderLocation->getBurgerOrder().size(); i++)
	{
		std::cout << orderLocation->getBurgerOrder().at(i)->getSpaceType() << "     ";
	}
	std::cout << std::endl;
}

//will return true if order was correct
bool Board::getScoredResult()
{
	return scored;
}

//will reset bool vars after a correct order
void Board::resetBoolVars()
{
	scored = false;
	orderLocation->resetIsCorrectOrder();
}
