// Program name: Ant.h
// Author: Max Veregge
// Description: The Ant class represents an Ant that moves through a Board in a Langton's ant simulation.
// The ant's orientation is represented by an enumeration, and the Location is represented by a Location
// class. The orientation or location can be changed using setOrientation or setLocation.

#ifndef ANT_H
#define ANT_H

#include "Location.h"

enum Orientation { NORTH, EAST, SOUTH, WEST };

class Ant {
	
	public:
		
		Ant(Location l, Orientation o);
		Location getLocation();
		Orientation getOrientation();
		void setLocation(Location l);
		void setOrientation(Orientation o);
		Ant();
	private:
		Location loc;
		Orientation orient;
};

#endif