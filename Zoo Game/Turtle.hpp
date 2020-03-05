//Program name: Turtle.hpp
//Date: 10/24/19
//Author: Max Veregge
//Description: Turtle.hpp contains a specification for the Turtle class. Turtle inherits all of 
//its member variables and functions from the parent Animal class. It augments behavior from 
//the Animal class constructor to initialize the member variables to the appropriate values
//for the Tiger derived class.

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal {

public:
	Turtle();
	Turtle(int);
	static int const cost = 100;
	static int const foodCost = int(baseFoodCost * .5);
	static int const babies = 10;
	static int const payoff = int(cost * .05);
};

#endif