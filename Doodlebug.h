/*
 * Doodlebug.h
 *
 *  Created on: Feb 23, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_
#include "Organism.h"
#include <stdlib.h>

class Doodlebug: public Organism{
private:
	int roundsAlive; //Keeps track of how many rounds the doodle bug has been alive
	int roundsSinceLastEat; //Keeps track of how many rounds its been since the doodle bug has eaten
	bool hasMoved; //Keeps track if the doodle bug has moved or not
public:
	Doodlebug();
	virtual ~Doodlebug();
	virtual bool isPrey();
	virtual int move(Organism***, int, int, int, int*, int*);
	virtual int breed(Organism***, int, int, int, int*);
	virtual int doodleStarve(Organism***, int, int);
	virtual bool getHasMoved();
	virtual void setHasMoved();
	virtual int getRoundsSinceLastEat();
};

#endif /* DOODLEBUG_H_ */
