/*
 * Ant.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#include "Ant.h"

Ant::Ant(){
	hasMoved = false;
	roundsAlive = 0;
}

Ant::~Ant() {}

/*
 * returns if the organism is pray
 * @return false
 */
bool Ant::isPrey(){
	return true;
}

/*
 * moves the organism whilst increasing the amount of rounds its been alive
 * @param grid A 2d array of Organisms
 * @param gridSize the length and width of grid
 * @param i the x position of the ant
 * @param j the y position of the ant
 * @param spaces an array of spaces around the ant that are empty
 * @param prey an array of spaces around the ant that are prey
 * @return 0
 */
int Ant::move(Organism*** grid, int gridSize, int i, int j, int* spaces, int* prey){
	Organism::move(grid, gridSize, i, j, spaces, prey);
	roundsAlive++;
	hasMoved = true;
	return 0;
}

/*
 * Creates a new ant if the ant is able to breed
 * @param grid A 2d array of Organisms
 * @param gridSize the length and width of grid
 * @param i the x position of the ant
 * @param j the y position of the ant
 * @param spaces an array of spaces around the ant that are empty
 * @return addedAnts
 */
int Ant::breed(Organism*** grid, int gridSize, int i, int j, int* spaces){
	int addedAnts = 0; // Keeps track of the addded ants

	//if roundsAlive is greater than or equal to 3 then the ant breeds
	if(roundsAlive >= 3){
		int size  = 0; // keeps track of the amount of empty spaces
		int moveTo = 0; // keeps track of the spot the ants child will go

		//Goes through spaces and keeps track of how many elements are in it
		for(unsigned int h = 0; h < sizeof(*spaces);h++)
			//if spaces[h] is greater than 0 then increase size by 1
			if(spaces[h]>0)
				size++;

		//if size is greater than 0 then moveTo is set to a random number in spaces
		if(size>0){
			moveTo = spaces[rand()%size];
			addedAnts = 1;
		}

		//if moveTo is 1 then make an ant to the left
		//else if moveTo is 2 then make an ant above
		//else if moveTo is 3 then make an ant the right
		//else if moveTo is 4 then make an ant below
		if (moveTo == 1)
			grid[i-1][j] = new Ant();
		else if (moveTo == 2)
			grid[i][j-1] = new Ant();
		else if (moveTo == 3)
			grid[i+1][j] = new Ant();
		else if (moveTo == 4)
			grid[i][j+1] = new Ant();

		roundsAlive = 0;

		//if moveTo is 0 then roundsAlive is set to 3 and return  0
		if(moveTo == 0){
			roundsAlive = 3;
			addedAnts = 0;
		}
	}
	return addedAnts;
}

/*
 * Returns 0
 * @param grid A 2d array of Organisms
 * @param i the x position of the ant
 * @param j the y position of the ant
 * @return 0
 */
int Ant::doodleStarve(Organism*** grid, int i, int j){
	return 0;
}

/*
 * Returns 0
 * @return 0
 */
int Ant::getRoundsSinceLastEat(){
	return 0;
}

/*
 * returns hasMoved
 * @return hasMoved
 */
bool Ant::getHasMoved(){
	return hasMoved;
}

/*
 * sets hasMoved to false
 * @return void
 */
void Ant::setHasMoved(){
	hasMoved = false;
}
