// Program name: Stack.hpp
// Date: 11/20/19
// Author: Max Veregge
// Description: Stack.hpp contains a specification for the ADT stack. Stack
// contains a list of StackNodes that each point to the next node in the stack,
// and typical functions to push, pop, and peek elements on the stack.

#ifndef STACK_HPP
#define STACK_HPP

#include "Character.hpp"

struct StackNode {
	StackNode* next;
	Character* ch;
	StackNode(StackNode* next1, Character* ch1) {
		next = next1;
		ch = ch1;
	}
};

class Stack {
private:
	StackNode* head;
public:
	Stack();
	~Stack();
	void push(Character*);
	void printStack() const;
	bool isEmpty() const;
	StackNode* pop();
	Character* peek() const;

};

#endif
