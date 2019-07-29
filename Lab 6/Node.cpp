/********************************************

By: Anthony Huynh
Date: 11/4/2018
Description: header file for doubly linked node class

*********************************************/

#include "Node.hpp"
#include <iostream>

Node::Node()
{
	previous = nullptr;
	next = nullptr;
}


//constructor that will set the previous node pointer, the value, and the next node pointer
Node::Node(Node* lastNode, int valueIn, Node* nextNode)
{
	previous = lastNode;
	value = valueIn;
	next = nextNode;
}