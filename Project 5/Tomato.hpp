#ifndef TOMATO_hpp
#define TOMATO_hpp



#include "Ingredient.hpp"
class Tomato :
	public Ingredient
{
public:
	Tomato();
	Tomato(Space*, Space*, Space*, Space*);
	~Tomato();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);
};

#endif // !TOMATO_hpp
