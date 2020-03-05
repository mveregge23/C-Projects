//Program name: Tiger.cpp
//Date: 10/24/19
//Author: Max Veregge
//Description: Tiger.cpp contains an implementation of the Tiger class. Tiger inherits all of 
//its member variables and functions from the parent Animal class. It augments behavior from 
//the Animal class constructor to initialize the member variables to the appropriate values
//for the Tiger derived class.

#include "Tiger.hpp"

Tiger::Tiger() : Animal() {
	;
}

Tiger::Tiger(int age) : Animal() {
	this->age = age;
}