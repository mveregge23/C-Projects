// Program name: ChainmailArmor.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: ChainmailArmor.hpp contains a specification for the derived
// ChainmailArmor class. ChainmailArmor inherits all of its data members and
// functions from the Armor parent class, but defines its own constructor
// to uniquely initialize the data members.

#ifndef CHAINMAILARMOR_HPP
#define CHAINMAILARMOR_HPP

#include "Armor.hpp"

class ChainmailArmor : public Armor
{
public:
	ChainmailArmor();
};

#endif
