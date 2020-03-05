//Program name: Penguin.cpp
//Date: 10/24/19
//Author: Max Veregge
//Description: Penguin.cpp contains an implementation of the Penguin class. Penguin inherits all of 
//its member variables and functions from the parent Animal class. It augments behavior from 
//the Animal class constructor to initialize the member variables to the appropriate values
//for the Tiger derived class.

#include "Penguin.hpp"

Penguin::Penguin() : Animal() {
	;
}

Penguin::Penguin(int age) : Animal() {
	this->age = age;
}