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
	QueueNode* tempPtr;
	//will make sure queue is not empty
	if (!isEmpty())
	{
		//loop to delete all but last node
		while (front->next != front)
		{
			//to set last nodes next pointer as nullptr
			front->previous->next = nullptr;

			tempPtr = front;
			front = front->next;
			delete tempPtr;
		}

		//to delete last node
		delete front;
		
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
void Queue::addToBack(int valueIn)
{
	//if there isn't a queue
	if (isEmpty())
	{
		front = new QueueNode(front, valueIn, front);
	}


	else
	{
		QueueNode* tempPtr;
		tempPtr = front;
		//to loop through while the next part of the node points to another node
		while (tempPtr->next != nullptr && tempPtr->next != front)
		{
			tempPtr = tempPtr->next;
		}

		tempPtr->next = new QueueNode(tempPtr, valueIn, front);
		front->previous = tempPtr->next;
		tempPtr = nullptr;
	}
}

//will return the value of the front node
int Queue::getFront()
{
	if (!isEmpty())
	{
		return front->value;
	}
	else
	{
		std::cout << "Queue is empty." << std::endl;
	}

	return -1;
}

//will remove front value and set front pointer to next node
void Queue::removeFront()
{
	if (!isEmpty())
	{
		//to check if last node points to itself/the front
		if (front->next == front)
		{
			delete front;
			front = nullptr;
		}
	
		else
		{
			//to set the last node's next pointer the the node after the front
			front->previous->next = front->next;

			QueueNode* tempPtr;
			tempPtr = front;
			front = front->next;

			//to set the second node's previous pointer to point to the last node before deleting the first node
			front->previous = tempPtr->previous;
			delete tempPtr;

		}
	}
	else
	{
		std::cout << "Queue is empty." << std::endl;
	}
}

//to display the queue's content
void Queue::displayQueue()
{
	if (!isEmpty())
	{
		QueueNode* tempPtr;
		tempPtr = front;
		//to display all but last one
		while (tempPtr->next != nullptr && tempPtr->next != front)
		{
			std::cout << tempPtr->value << "     ";
			tempPtr = tempPtr->next;
		}

		std::cout << tempPtr->value << "     " << std::endl;
		tempPtr = nullptr;
	}
	else
	{
		std::cout << "Queue is empty." << std::endl;
	}
}
