// Program name: Ant.cpp
// Author: Max Veregge
// Description: This is an implementation of the Ant class to be used in a Board class and Langton's ant simulation.

#include "Ant.h"

// setOrientation takes an value for the enumerated data type orientation to set the orientation of the ant
void Ant::setOrientation(Orientation o) {
	orient = o;
}

// setLocation takes a Location object to set the location of the ant
void Ant::setLocation(Location l) {
	loc = l;
}

// getOrienation returns the current orientation of the ant
Orientation Ant::getOrientation() {
	return orient;
}

// getLocation returns the current Location of the ant
Location Ant::getLocation() {
	return loc;
}

// ANt constructor takes a Location and Orientation to initialize the ant's location and orientation
Ant::Ant(Location l, Orientation o) {
	loc = l;
	orient = o;
}

// Default ant constructor
Ant::Ant() {
	;
}