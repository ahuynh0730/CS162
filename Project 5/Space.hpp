#ifndef SPACE_hpp
#define SPACE_hpp

#include <string>
#include <deque>
#include <iostream>



class Space
{

private:

protected:
	Space * top;
	Space* right;
	Space* bottom;
	Space* left;
	std::string spaceType = "   ";
	bool hasPlayer = false;
	bool correctOrder = false;

	

public:
	Space();
	Space(Space*, Space*, Space*, Space*);
	~Space();
	Space* getTopPointer();
	void setTopPointer(Space*);
	Space* getRightPointer();
	void setRightPointer(Space*);
	Space* getBottomPointer();
	void setBottomPointer(Space*);
	Space* getLeftPointer();
	void setLeftPointer(Space*);
	std::string getSpaceType();
	bool holdsPlayer();
	void placePlayer();
	void removePlayer();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);
	
};


#endif



