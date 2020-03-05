// Program name: Queue.cpp
// Date: 11/14/19
// Author: Max Veregge
// Description: Queue.cpp contains a specification for the Queue class, which is a circular
// linked list implementation of the queue ADT. Queue contains QueueNode structs, which are
// implemented in the header file for Queue. Queue has standard queue functions isEmpty, addBack,
// getFront, removeFront, and printQueue.

#include "Queue.hpp"

Queue::Queue() {
	head = nullptr;
}

//destructor frees memory used by each node in the list
Queue::~Queue() {

	QueueNode* del = head;

	while (del != nullptr) {

		//get next node
		QueueNode* next = del->next;

		//deallocate memory and move to next node
		delete del->ch;
		delete del;
		del = next;

		//if the last node has been reached, delete and exit loop
		if (del != nullptr && del->next == head) {
			delete del->ch;
			delete del;
			del = nullptr;
		}
	}
}

//isEmpty returns a boolean value based on whether or not the list is empty
bool Queue::isEmpty() const {
	return head == nullptr;
}

//addBack takes an integer value from the user, and adds it to the back of the queue
void Queue::addBack(Character* ch) {

	//if list is empty, follow special logic
	if (head == nullptr) {

		//create new node with no pointers to other nodes since it is the only node
		head = new QueueNode(nullptr, nullptr, ch);
	}

	//if list only contains one node, follow special logic
	else if (head->next == nullptr) {
		
		//create new node and set pointers
		QueueNode* newNode = new QueueNode(head, head, ch);
		head->next = newNode;
		head->prev = newNode;
	}

	//if list has two or more nodes, follow default logic
	else {

		//create new new node and set pointers
		QueueNode* newNode = new QueueNode(head, head->prev, ch);
		head->prev->next = newNode;
		head->prev = newNode;
	}
}

//removeFront takes a node off the front of the queue and returns it to the caller. it is the caller's
//responsibility to deallocate the memory for the popped node once they are done using it
QueueNode* Queue::removeFront() {

	//if list is empty, follow special logic
	if (this->isEmpty()) {
		std::cout << "The queue is empty!\n";
		return nullptr;
	}

	//if list contains one node, follow special logic
	else if (head->next == nullptr) {
		
		//delete node and set head to nullptr
		QueueNode* oldFront = head;
		head = nullptr;
		return oldFront;
	}

	//if list contains two nodes, follow special logic
	else if (head->next->next == head) {

		//save next node before delinking and deleting front node
		QueueNode* oldFront = head;
		QueueNode* newFront = head->next;

		//set pointers of last remainining node to nullptr
		newFront->next = nullptr;
		newFront->prev = nullptr;

		//set head to point to the last remaining node and return front
		head = newFront;
		return oldFront;
	}

	//if list contains three or more nodes, follow default logic
	else {

		//save next node before delinking and deleting front node
		QueueNode* oldFront = head;
		QueueNode* newFront = head->next;

		//set pointers of newFront and last node
		newFront->prev = head->prev;
		head->prev->next = newFront;

		//delete the first node and set head to point to the new first node
		head = newFront;
		return oldFront;
	}
}

//printQueue prints the queue front to back
void Queue::printQueue() {

	//initialize next for use in printing
	QueueNode* next = head;

	//check if queue is empty
	if (!isEmpty()) {

		//if not, print the current node and continue to the next, until next == nullptr
		do {
			std::cout << next->ch << " ";
			next = next->next;
		} while (next != head && next != nullptr);

		std::cout << std::endl;
	}

	//otherwise, notify the use that the queue is empty
	else {
		std::cout << "The queue is empty!\n";
	}
}

//getFront returns the character of the front node in the queue
Character* Queue::getFront() const {

	//check if queue is empty
	if (!isEmpty()) {

		//if not, return the value of the front node
		return head->ch;
	}

	//otherwise, notify the user that the queue is empty and return 0
	else {

		std::cout << "The queue is empty!\n";
		return nullptr;
	}
}