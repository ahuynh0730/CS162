/********************************************

By: Anthony Huynh
Date: 11/4/2018
Description: header file for a doubly linked node class

*********************************************/

#ifndef NODE_hpp
#define NODE_hpp

#include "DoublyLinkedList.hpp"

class Node
{
private:
	int value;
	Node* previous;
	Node* next;

	friend class DoublyLinkedList;

public:
	Node();
	Node(Node*, int, Node*);
};

#endif // !NODE_hpp

