/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: header file for Harry Potter class

*****************************************************/


#ifndef HARRYPOTTER_hpp
#define HARRYPOTTER_hpp

#include "Character.hpp"

class HarryPotter : public Character
{
private:
	bool Hogwarts = false;
public:
	HarryPotter();
	virtual void updateStrength(int);
};


#endif // !HARRYPOTTER_hpp

