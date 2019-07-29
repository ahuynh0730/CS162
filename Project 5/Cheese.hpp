#ifndef CHEESE_hpp
#define CHEESE_hpp


#include "Ingredient.hpp"
class Cheese :
	public Ingredient
{
public:
	Cheese();
	Cheese(Space*, Space*, Space*, Space*);
	~Cheese();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);
};

#endif // !CHEESE_hpp

