#ifndef ONION_hpp
#define ONION_hpp


#include "Ingredient.hpp"
class Onion :
	public Ingredient
{
public:
	Onion();
	Onion(Space*, Space*, Space*, Space*);
	~Onion();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);
};

#endif // !ONION_hpp

