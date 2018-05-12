/*
 * Ant.h
 *
 *  Created on: Feb 23, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#ifndef ANT_H_
#define ANT_H_
#include "Organism.h"
#include <stdlib.h>

class Ant: public Organism {
private:
	int roundsAlive; //Keeps track of how many rounds the ant has been alive
	bool hasMoved; //Keeps track if the ant has moved or not
public:
	Ant();
	virtual ~Ant();
	virtual bool isPrey();
	virtual int move(Organism***, int, int, int, int*, int*);
	virtual int breed(Organism***, int, int, int, int*);
	virtual int getRoundsSinceLastEat();
	virtual int doodleStarve(Organism***, int, int);
	virtual bool getHasMoved();
	virtual void setHasMoved();
};

#endif /* ANT_H_ */
