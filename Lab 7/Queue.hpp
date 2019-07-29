/************************************************

	By: Anthony Huynh
	Date: 11/11/2018
	Description: header file for queue class

************************************************/

#ifndef QUEUE_hpp
#define QUEUE_hpp

class Queue
{
private:
	struct QueueNode
	{
		QueueNode* previous;
		QueueNode* next;
		int value;
		QueueNode(QueueNode* previousIn, int valueIn, QueueNode* nextIn)
		{
			previous = previousIn;
			value = valueIn;
			next = nextIn;
		}
	};
	QueueNode* front;

public:
	Queue();
	~Queue();
	bool isEmpty();
	void addToBack(int);
	int getFront();
	void removeFront();
	void displayQueue();
};

#endif // !QUEUE_hpp

