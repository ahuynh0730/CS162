/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: implementation file for medusa class

*****************************************************/

#ifndef MEDUSA_hpp
#define MEDUSA_hpp

#include "Character.hpp"

class Medusa : public Character
{
private:

public:
	Medusa();
	virtual void attackRoll();
};

#endif // !MEDUSA_hpp

