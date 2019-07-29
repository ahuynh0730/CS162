/********************************************

By: Anthony Huynh
Date: 11/4/2018
Description: implementation file for doubly linked list class

*********************************************/

#include "DoublyLinkedList.hpp"
#include <iostream>

//constructor that sets head and tail to nullptr
DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

//to add a node to the beginning, takes an int in
void DoublyLinkedList::addToHead(int valueIn)
{
	//if there is no list
	if (head == nullptr)
	{
		head = new Node(nullptr, valueIn, nullptr);
		
		tail = head;
	}

	//if a previous node exists will create a temp node pointer with new value, then set 
	//head to the tempNode
	else
	{
		tempNode = new Node(nullptr, valueIn, head);
		head->previous = tempNode;
		head = tempNode;
		tempNode = nullptr;
	}
}

void DoublyLinkedList::addToTail(int valueIn)
{
	//if there is no list
	if (tail == nullptr)
	{
		tail = new Node(nullptr, valueIn, nullptr);

		head = tail;
	}

	//if a previous node exists will set last node's next pointer to new node, and set tail pointer to new node
	else
	{
		tail->next = new Node(tail, valueIn, nullptr);
		tail = tail->next;
	}
}

//sets temp node to the next node after head, then deletes head and sets head to temp node
//sets temp node to nullptr at the end
void DoublyLinkedList::deleteFromHead()
{
	//to check if list is empty
	//will only ontinue if head does not point to nullptr
	if (head != nullptr)
	{
		tempNode = head->next;
		delete head;
		head = tempNode;
		head->previous = 0;
		tempNode = nullptr;
	}
}

void DoublyLinkedList::deleteFromTail()
{
	//to check if list is empty
	//will only ontinue if head does not point to nullptr
	if (tail != nullptr)
	{
		tempNode = tail->previous;
		delete tail;
		tail = tempNode;
		tail->next = nullptr;
		tempNode = nullptr;
	}
}


void DoublyLinkedList::displayHeadValue()
{
	if (head == nullptr)
	{
		std::cout << "There is no node to display. " << std::endl;
	}
	else
	{
		std::cout << head->value << std::endl;
	}
}

void DoublyLinkedList::displayTailValue()
{
	if (tail == nullptr)
	{
		std::cout << "There is no node to display. " << std::endl;
	}
	else
	{
		std::cout << tail->value << std::endl;
	}
}

//to delete entire linked list, will set temp node to head and head to the next node
//then will delete temp node and call function again
//if the next ptr is nullptr, then will delete head rather than calling function again
void DoublyLinkedList::deleteList()
{
	if (head != nullptr)
	{
		//while there is a node after the current node
		if (head->next != nullptr)
		{
			tempNode = head;
			head = head->next;
			delete tempNode;
			deleteList();
		}

		//for when there is only one node left
		else
		{
			delete head;
		}
	}

}

void DoublyLinkedList::displayListForward()
{
	tempNode = nullptr;
	//to check and make sure there is a list
	if (head == nullptr)
	{
		std::cout << "There are no nodes to display." << std::endl;
	}

	//sets temp node to the head, and will run a loop as long as temp node does not point to nullptr
	//temp node will point to nullptr on the last node
	else
	{
		tempNode = head;
		while (tempNode)
		{
			std::cout << tempNode->value << "     ";
			tempNode = tempNode->next;
		}
		std::cout << std::endl;
	}
}

void DoublyLinkedList::displayListBackward()
{
	tempNode = nullptr;

	//to check and make sure there is a list
	if (tail == nullptr)
	{
		std::cout << "There are no nodes to display." << std::endl;
	}

	//sets temp node to the head, and will run a loop as long as temp node does not point to nullptr
	//temp node will point to nullptr on the last node
	else
	{
		tempNode = tail;
		while (tempNode)
		{
			std::cout << tempNode->value << "     ";
			tempNode = tempNode->previous;
		}
		std::cout << std::endl;
	}

}