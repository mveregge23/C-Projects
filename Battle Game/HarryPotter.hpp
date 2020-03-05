// Program name: HarryPotter.hpp
// Date: 11/7/19
// Author: Max Veregge
// Description: HarryPotter.hpp contains a specification for the HarryPotter subclass of Character. HarryPotter
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. HarryPotter implements a basic attack function and a setStrength function that
// captures the Hogwarts ability.

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character {
public:
	HarryPotter(int, int, int);
	int hogwarts = 1;
	virtual int attack();
	virtual int defend();
	virtual void setStrength(int);
	void updateDefense();
};

#endif
