#ifndef PICKLE_hpp
#define PICKLE_hpp


#include "Ingredient.hpp"
class Pickle :
	public Ingredient
{
public:
	Pickle();
	Pickle(Space*, Space*, Space*, Space*);
	~Pickle();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);
};

#endif // !PICKLE_hpp

