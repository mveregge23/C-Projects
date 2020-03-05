//Program name: Tiger.hpp
//Date: 10/24/19
//Author: Max Veregge
//Description: Tiger.hpp contains a specification for the Tiger class. Tiger inherits all of 
//its member variables and functions from the parent Animal class. It augments behavior from 
//the Animal class constructor to initialize the member variables to the appropriate values
//for the Tiger derived class.

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger: public Animal {

public:
	Tiger();
	Tiger(int);
	static int const cost = 10000;
	static int const foodCost = baseFoodCost * 5;
	static int const babies = 1;
	static int const payoff = int(cost * .2);
};

#endif