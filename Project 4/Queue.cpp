/************************************************

By: Anthony Huynh
Date: 11/11/2018
Description: implementation file for queue class

************************************************/

#include "Queue.hpp"
#include <iostream>

//constructor that will set the front to nullptr
Queue::Queue()
{
	front = nullptr;
}


//destructor that frees all memory used by nodes
Queue::~Queue()
{
	CharacterNode* tempPtr;
	//will make sure queue is not empty
	if (!isEmpty())
	{
		//loop to delete all but last node
		while (front->next != nullptr)
		{
			tempPtr = front;
			front = front->next;
			delete tempPtr->char1;
			delete tempPtr;
		}

		//to delete last node
		delete front->char1;
		delete front;
		front = nullptr;
	}
}



//function that will return true if the queue is empty
bool Queue::isEmpty()
{
	if (front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//will add to back of queue
void Queue::addToBack(Character* charIn)
{
	//if there isn't a queue
	if (isEmpty())
	{
		front = new CharacterNode(charIn, nullptr);
	}


	else
	{
		CharacterNode* tempPtr;
		tempPtr = front;
		//to loop through while the next part of the node points to another node
		while (tempPtr->next != nullptr)
		{
			tempPtr = tempPtr->next;
		}

		tempPtr->next = new CharacterNode(charIn, nullptr);
		tempPtr = nullptr;
	}
}

//adds character to front of queue for when they are put in loser's pile
void Queue::addToFront(Queue*  queueIn)
{
	if (isEmpty())
	{
		this->front = queueIn->front;
		queueIn->front = queueIn->front->next;
		this->front->next = nullptr;
	}

	else
	{
		CharacterNode* tempPtr = queueIn->front;
		queueIn->front = queueIn->front->next;
		tempPtr->next = this->front;
		this->front = tempPtr;
		tempPtr = nullptr;
	}
	
}


//will remove front character by having front point to next node
void Queue::removeFront()
{
	if (!isEmpty())
	{
		CharacterNode* tempPtr = front;
		delete tempPtr;
		front = front->next;
	}
	else
	{
		std::cout << "Queue is empty." << std::endl;
	}
}

//will display all character names from front to back
void Queue::displayCharacterNames(int numbCharacters)
{
	if (!isEmpty())
	{
		CharacterNode* tempPtr = front;
		for (int i = 0; i < numbCharacters; i++)
		{
			std::cout << "Character " << i + 1 << "'s name is " << tempPtr->char1->getCharacterName() << std::endl;
			tempPtr = tempPtr->next;
		}
	}
	else
	{
		std::cout << "Queue is empty." << std::endl;
	}
}

//when a character wins, will move them to back of array and increase their health
void Queue::moveFrontToBack()
{
	front->char1->recoverStrength();
	CharacterNode* tempPtr = front;
	while (tempPtr->next != nullptr)
	{
		tempPtr = tempPtr->next;
	}
	
	//will only move if not the last node
	if (front->next != nullptr)
	{
		tempPtr->next = front;
		front = front->next;
		tempPtr->next->next = nullptr;
	}

	tempPtr = nullptr;
}

//to get the front character
Character* Queue::getFrontCharacter()
{
	return front->char1;
}