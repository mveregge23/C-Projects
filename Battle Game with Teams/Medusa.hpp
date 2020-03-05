// Program name: Medusa.hpp
// Date: 11/7/19
// Author: Max Veregge
// Description: Medusa.hpp contains a specification for the Medusa subclass of Character. Medusa
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. Medusa implements an attack function that includes the Glare ability,
// and a basic defense function.

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character {
public:
	Medusa(int, int, int, std::string);
	virtual int attack();
	virtual int defend();
};

#endif
