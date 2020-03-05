//Program name: Turtle.cpp
//Date: 10/24/19
//Author: Max Veregge
//Description: Turtle.cpp contains an implementation of the Turtle class. Turtle inherits all of 
//its member variables and functions from the parent Animal class. It augments behavior from 
//the Animal class constructor to initialize the member variables to the appropriate values
//for the Tiger derived class.

#include "Turtle.hpp"

Turtle::Turtle() : Animal() {
	;
}

Turtle::Turtle(int age) : Animal() {
	this->age = age;
}