//Program name: Animal.cpp
//Date: 10/24/19
//Author: Max Veregge
//Description: Animal.cpp contains an implementation for the Animal class. The Animal class
//contains member variables for the age.It has member functions to increment the age of the animal and 
//determine whether or not the animal is an adult. The default constructor initializes the age to 0.

#include "Animal.hpp"

Animal::Animal() {
	age = 0;
}

int Animal::incAge() {
	return ++age;
}

bool Animal::isAdult() const {
	return age >= 3;
}