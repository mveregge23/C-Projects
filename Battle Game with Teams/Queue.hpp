// Program name: Queue.hpp
// Date: 11/14/19
// Author: Max Veregge
// Description: Queue.hpp contains a specification for the Queue class, which is a circular
// linked list implementation of the queue ADT. Queue contains QueueNode structs, which are
// implemented in the header file for Queue. Queue has standard queue functions isEmpty, addBack,
// getFront, removeFront, and printQueue.

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "Character.hpp"

struct QueueNode {
	QueueNode* next;
	QueueNode* prev;
	Character* ch;
	QueueNode(QueueNode* nextIn, QueueNode* prevIn, Character* ch1) {
		next = nextIn;
		prev = prevIn;
		ch = ch1;
	}
};

class Queue {
private:
	QueueNode* head;
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void addBack(Character*), 
		printQueue();
	Character* getFront() const;
	QueueNode* removeFront();
};

#endif
