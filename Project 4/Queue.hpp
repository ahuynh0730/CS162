/************************************************

	By: Anthony Huynh
	Date: 11/11/2018
	Description: header file for queue class

************************************************/

#ifndef QUEUE_hpp
#define QUEUE_hpp

#include "Character.hpp"
class Queue
{
private:
	struct CharacterNode
	{
		CharacterNode* next;
		Character* char1;
		CharacterNode(Character* characterIn, CharacterNode* nextIn)
		{
			char1 = characterIn;
			next = nextIn;
		}
	};
	CharacterNode* front;

public:
	Queue();
	~Queue();
	bool isEmpty();
	void addToBack(Character*);
	void addToFront(Queue*);
	void removeFront();
	void displayCharacterNames(int);
	void moveFrontToBack();
	Character* getFrontCharacter();
};

#endif // !QUEUE_hpp

