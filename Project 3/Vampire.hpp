/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: header file for vampire class

*****************************************************/


#ifndef VAMPIRE_hpp
#define VAMPIRE_hpp

#include "Character.hpp"

class Vampire : public Character
{
private:
	bool charmActivated = false;

public:
	Vampire();
	virtual void defenseRoll();
	virtual int calcDamageTaken(int);
};

#endif // !VAMPIRE_hpp

