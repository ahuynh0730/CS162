#ifndef TRASH_hpp
#define TRASH_hpp


#include "Space.hpp"
class Trash :
	public Space
{
public:
	Trash();
	Trash(Space*, Space*, Space*, Space*);
	~Trash();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);
};

#endif // !TRASH_hpp
