/********************************************

By: Anthony Huynh
Date: 11/4/2018
Description: header file for doubly linked list class

*********************************************/

#ifndef DOUBLYLINKEDLIST_hpp
#define DOUBLYLINKEDLIST_hpp

#include "Node.hpp"

class DoublyLinkedList
{
private:
	class Node * head;
	class Node * tail;
	class Node * tempNode;

public:
	DoublyLinkedList();
	void addToHead(int);
	void addToTail(int);
	void deleteFromHead();
	void deleteFromTail();
	void displayHeadValue();
	void displayTailValue();
	void deleteList();
	void displayListForward();
	void displayListBackward();


};

#endif // !DOUBLYLINKEDLIST_hpp
