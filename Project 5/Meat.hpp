#ifndef MEAT_hpp
#define MEAT_hpp

#include "Ingredient.hpp"

#include <deque>



class Meat :
	public Ingredient
{
public:
	Meat();
	Meat(Space*, Space*, Space*, Space*);
	~Meat();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);

};

#endif // !MEAT_hpp

