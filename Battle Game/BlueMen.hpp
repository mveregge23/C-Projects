// Program name: BlueMen.hpp
// Date: 11/7/19
// Author: Max Veregge
// Description: BlueMen.hpp contains a specification for the BlueMen subclass of Character. BlueMen
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. BlueMen implements a basic attack function and a setStrength functin
// that captures the Mob ability.

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character {
public:
	BlueMen(int, int, int);
	virtual int attack();
	virtual int defend();
	virtual void setStrength(int);
	void updateDefense();
};

#endif
