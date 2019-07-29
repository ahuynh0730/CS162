#ifndef BUN_hpp
#define BUN_hpp


#include "Ingredient.hpp"

class Bun :
	public Ingredient
{
public:
	Bun();
	Bun(Space*, Space*, Space*, Space*);
	~Bun();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);
};
#endif // !1

