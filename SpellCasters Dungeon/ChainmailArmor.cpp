// Program name: ChainmailArmor.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: ChainmailArmor.cpp contains an implementation of the derived
// ChainmailArmor class. ChainmailArmor inherits all of its data members and
// functions from the Armor parent class, but defines its own constructor
// to uniquely initialize the data members.

#include "ChainmailArmor.hpp"

ChainmailArmor::ChainmailArmor()
{
	this->damageRatio = 3;
	this->integrity = 20;
	this->name = "chainmail armor";
}
