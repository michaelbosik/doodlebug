/*
 * Simulation.h
 *
 *  Created on: Feb 23, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Simulation {
public:
	Simulation(int);
	virtual ~Simulation();
	int moveDoodleBugs(Organism***, int);
	int starveDoodles(Organism***, int);
	void moveAnts(Organism***, int);
	void setFalse(Organism***, int);
	int breedDoodles(Organism***, int);
	int breedAnts(Organism***, int);
	void print(Organism***, int);
	int* getAdjSpaces(Organism***, int, int, int);
	int* getAdjPrey(Organism***, int, int, int);
	bool allAnts(Organism***, int);
	bool allDoodlebugs(Organism***, int);
	bool allDead(Organism***, int);
	Organism*** grid; // the 2d array of Organisms to simulate
};

#endif /* SIMULATION_H_ */
