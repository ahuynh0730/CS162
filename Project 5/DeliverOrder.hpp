#ifndef DELIVERORDER_hpp
#define DELIVERORDER_hpp

#include "Space.hpp"
#include "Bun.hpp"
#include "Cheese.hpp"
#include "Lettuce.hpp"
#include "Meat.hpp"
#include "Onion.hpp"
#include "Pickle.hpp"
#include "Tomato.hpp"

#include <stdlib.h>
#include <algorithm>

class DeliverOrder :
	public Space
{
private:
	std::deque<Space*> burgerOrder;
	bool isCorrectOrder;

public:
	DeliverOrder();
	DeliverOrder(Space*, Space*, Space*, Space*);
	~DeliverOrder();
	virtual std::deque<Space*> interactWithSpace(std::deque<Space*>);
	std::deque<Space*> getBurgerOrder();
	void createOrder();
	bool getValidOrder();
	void resetIsCorrectOrder();

};

#endif // !DELIVERORDER_hpp

