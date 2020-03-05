// Program name: SpellStoneSpace.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: SpellStoneSpace.hpp contains a specification for the derived
// SpellStoneSpace class. SpellStoneSpace inherits most data members and functions
// from the Space parent class, but defines its own stone data member, and 
// a constructor and accessor to manage it. 

#ifndef SPELLSTONESPACE_HPP
#define SPELLSTONESPACE_HPP

#include "Space.hpp"
#include "SpellStone.hpp"

class SpellStoneSpace : public Space
{
private:
	SpellStone* stone;
public:
	SpellStoneSpace(SpellStone*);
	~SpellStoneSpace();
	void addStone(SpellStone*);
	virtual void interact();
	SpellStone* getStone();
};

#endif