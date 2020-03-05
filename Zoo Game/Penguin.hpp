//Program name: Penguin.hpp
//Date: 10/24/19
//Author: Max Veregge
//Description: Penguin.hpp contains a specification for the Penguin class. Penguin inherits all of 
//its member variables and functions from the parent Animal class. It augments behavior from 
//the Animal class constructor to initialize the member variables to the appropriate values
//for the Tiger derived class.

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal {

public:
	Penguin();
	Penguin(int);
	static int const cost = 1000;
	static int const foodCost = baseFoodCost;
	static int const babies = 5;
	static int const payoff = int(cost * .1);
};

#endif