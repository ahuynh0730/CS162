#include "DeliverOrder.hpp"




DeliverOrder::DeliverOrder()
{
	Space();
	spaceType = "DEL";
	createOrder();
}

DeliverOrder::DeliverOrder(Space* topIn, Space* rightIn, Space* bottomIn, Space* leftIn)
{
	Space(topIn, rightIn, bottomIn, leftIn);
	spaceType = "DEL";
	createOrder();
}

//will delete burgerOrder Deque
DeliverOrder::~DeliverOrder()
{
	while (!burgerOrder.empty())
	{
		delete burgerOrder.front();
		burgerOrder.pop_front();
	}
}

//will make sure character burger deque matches and then create a new order
std::deque<Space*> DeliverOrder::interactWithSpace(std::deque<Space*> burgerIn)
{
	if (burgerIn.size() != burgerOrder.size())
	{
		isCorrectOrder = false;
		return burgerIn;
	}

	for (unsigned int i = 0; i < burgerIn.size(); i++)
	{
		if (burgerIn.at(i)->getSpaceType() != burgerOrder.at(i)->getSpaceType())
		{
			isCorrectOrder = false;
			return burgerIn;
		}
	}
	std::cout << "correct order" << std::endl;
	isCorrectOrder = true;
	while (!burgerIn.empty())
	{
		delete burgerIn.front();
		burgerIn.pop_front();
	}

	while (!burgerOrder.empty())
	{
		delete burgerOrder.front();
		burgerOrder.pop_front();
	}
	createOrder();
	return burgerIn;
}

std::deque<Space*> DeliverOrder::getBurgerOrder()
{
	return burgerOrder;
}

void DeliverOrder::createOrder()
{
	bool hasBread = std::rand() % 2;
	int numberExtraPatties = std::rand() % 2;
	int piecesPickle = std::rand() % 10;
	int slicesCheese = std::rand() % 5;
	int piecesOnion = std::rand() % 4;
	int piecesTomato = std::rand() % 3;
	int piecesLettuce = std::rand() % 3;

	burgerOrder.push_back(new Meat());
	for (int i = 0; i < numberExtraPatties; i++)
	{
		burgerOrder.push_back(new Meat());
	}

	for (int i = 0; i < piecesPickle; i++)
	{
		burgerOrder.push_back(new Pickle());
	}

	for (int i = 0; i < slicesCheese; i++)
	{
		burgerOrder.push_back(new Cheese());
	}

	for (int i = 0; i < piecesOnion; i++)
	{
		burgerOrder.push_back(new Onion());
	}

	for (int i = 0; i < piecesTomato; i++)
	{
		burgerOrder.push_back(new Tomato());
	}

	for (int i = 0; i < piecesLettuce; i++)
	{
		burgerOrder.push_back(new Lettuce());
	}

	std::random_shuffle(burgerOrder.begin(), burgerOrder.end());

	if (hasBread)
	{
		burgerOrder.push_front(new Bun());
		burgerOrder.push_back(new Bun());
	}
	
}

bool DeliverOrder::getValidOrder()
{
	return isCorrectOrder;
}

void DeliverOrder::resetIsCorrectOrder()
{
	isCorrectOrder = false;
}
