#include "Stack.hpp"

//constructor initializes head to nullptr
Stack::Stack() {
	head = nullptr;
}

//destructor deallocates memory for all stackNodes
Stack::~Stack(){
	StackNode* del = head;

	while (del != nullptr) {

		//get next node
		StackNode* next = del->next;

		//deallocate memory and move to next node
		delete del->ch;
		delete del;
		del = next;

	}
}

//push adds a new stack node to the top of the stack
void Stack::push(Character* ch) {

	//create new top node and point it to old top node
	StackNode* newTop = new StackNode(head, ch);
	
	//set head to point to new top node
	head = newTop;

}

//isEmpty checks to see if the stack is empty and returns true if so
bool Stack::isEmpty() const {
	return head == nullptr;
}

//printStack prints all of the characters currently in the stack
void Stack::printStack() const {

	StackNode* next = head;

	//if stack is not empty, print characters until the bottom of the stack is reached
	if (!isEmpty()) {

		do {
			std::cout << *next->ch << std::endl;
			next = next->next;
		} while (next != nullptr);

		std::cout << std::endl;

	}

	//otherwise, notify the user that the stack is empty
	else {
		std::cout << "The stack is empty!\n";
	}

}

//pop removes a stackNode from the top of the stack and returns it to the caller. it is the caller's
//responsibility to deallocate the memory for the popped node once they are done using it
StackNode* Stack::pop() {

	StackNode* oldFront = head;
	StackNode* newFront = head->next;

	oldFront->next = nullptr;
	head = newFront;
	return oldFront;
}

//peek returns the character in the node at the top of the stack, or nullptr if the stack is empty
Character* Stack::peek() const {
	
	if (!isEmpty()) {
		return head->ch;
	}
	else {
		std::cout << "The stack is empty!\n";
		return nullptr;
	}
}