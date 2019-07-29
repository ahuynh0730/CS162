/*****************************************************

By: Anthony Huynh
Date: 11/04/2018
Description: header file for blue men class

*****************************************************/

#ifndef BLUEMEN_hpp
#define BLUEMEN_hpp

#include "Character.hpp"

class BlueMen : public Character
{
private:

public:
	BlueMen();
	BlueMen(std::string);
	virtual void defenseRoll();
	~BlueMen();

};


#endif // !1

