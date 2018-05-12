/*
 * Organism.h
 *
 *  Created on: Feb 23, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include <iostream>
#include <stdlib.h>

class Organism {
private:
	bool hasMoved; //keeps track of if the organism has moved
public:
	Organism();
	virtual bool isPrey();
	virtual int move(Organism***, int, int, int, int*, int*);
	virtual int breed(Organism***, int, int, int, int*);
	virtual int doodleStarve(Organism***, int, int);
	virtual bool getHasMoved();
	virtual void setHasMoved();
	virtual int getRoundsSinceLastEat();
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
