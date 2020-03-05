//Program name: Animal.hpp
//Date: 10/24/19
//Author: Max Veregge
//Description: Animal.hpp contains a specification for the Animal class. The Animal class
//contains member variables for the age. It also contains a static member variable for the
//base cost of an animal. It has member functions to increment the age of the animal and 
//determine whether or not the animal is an adult. 

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {

protected:
	int age;
	static int const baseFoodCost = 100;

public:
	Animal();
	int incAge();
	bool isAdult() const;

};

#endif