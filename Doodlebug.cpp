/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#include "Doodlebug.h"

Doodlebug::Doodlebug() {
	hasMoved = false;
	roundsAlive = 0;
	roundsSinceLastEat = 0;
}

Doodlebug::~Doodlebug() {}

/*
 * Returns if the organism is prey
 * @return false
 */
bool Doodlebug::isPrey(){
	return false;
}

/*
 * moves the organism whilst increasing the amount of rounds its been alive
 * @param grid A 2d array of Organisms
 * @param gridSize the length and width of grid
 * @param i the x position of the doodle bug
 * @param j the y position of the doodle bug
 * @param spaces an array of spaces around the doodle bug that are empty
 * @param prey an array of spaces around the doodle bug that are prey
 * @return antsRemoved
 */
int Doodlebug::move(Organism*** grid, int gridSize, int i, int j, int* spaces, int* prey){
	int antsRemoved = 0; //Keeps track of the number of ants removed
	int numPrey = 0; //Keeps track of the number of prey
	int moveToPrey = 0; //Keeps track of the move to prey

	//Goes through prey and keeps track of how many elements are in it
	for(unsigned int h = 0; h < sizeof(*prey); h++)
		//if prey[h] is greater than 0 then increase numPrey by 1
		if(prey[h]>0)
			numPrey++;

	//if numPrey is 0 then move doodle bug and increase roundsSinceLastEat by 1
	//else eat an ant next to the doodle bug
	if(numPrey == 0){
		Organism::move(grid, gridSize, i, j, spaces, prey);
		roundsSinceLastEat++;
	}

	else{
		moveToPrey = prey[rand()%numPrey];
		roundsSinceLastEat = 0;
		antsRemoved = -1;


		//if moveTo is 1 then make an doodle bug to the left
		//else if moveTo is 2 then make an doodle bug above
		//else if moveTo is 3 then make an ddoodle bug the right
		//else if moveTo is 4 then make an doodle bug below
		if (moveToPrey == 1)
			grid[i-1][j] = grid[i][j];
		else if (moveToPrey == 2)
			grid[i][j-1] = grid[i][j];
		else if (moveToPrey == 3)
			grid[i+1][j] = grid[i][j];
		else if (moveToPrey == 4)
			grid[i][j+1] = grid[i][j];
	}

	roundsAlive++;
	hasMoved = true;

	//if moveTo greater than 0 then the point is set to 0 and return -1
	if (moveToPrey>0)
		grid[i][j] = 0;

	return antsRemoved;
}

/*
 * Creates a new doodle bug if the doodle bug is able to breed
 * @param grid A 2d array of Organisms
 * @param gridSize the length and width of grid
 * @param i the x position of the doodle bug
 * @param j the y position of the doodle bug
 * @param spaces an array of spaces around the doodle bug that are empty
 * @return addedDoodles
 */
int Doodlebug::breed(Organism*** grid, int gridSize, int i, int j, int* spaces){
	int addedDoodles = 0; //Keeps track of the amount of doodle bugs added

	//if roundsAlive is greater than or equal to 8
	if(roundsAlive >= 8){
		int size  = 0; //keeps track of the size of spaces
		int moveTo = 0; //keeps track of where the doodle bug moves to

		//Goes through spaces and keeps track of how many elements are in it
		for(unsigned int h = 0; h < sizeof(*spaces);h++)
			//if spaces[h] is greater than 0 then increase size by 1
			if(spaces[h]>0)
				size++;

		//if size is greater than 0 then moveTo is set to a random number in spaces
		if (size>0){
			moveTo = spaces[rand()%size];
			addedDoodles = 1;
		}

		//if moveTo is 1 then make a doodle bug to the left
		//else if moveTo is 2 then make a doodle bug above
		//else if moveTo is 3 then make a doodle bug the right
		//else if moveTo is 4 then make a doodle bug below
		if (moveTo == 1)
			grid[i-1][j] = new Doodlebug();
		else if (moveTo == 2)
			grid[i][j-1] = new Doodlebug();
		else if (moveTo == 3)
			grid[i+1][j] = new Doodlebug();
		else if (moveTo == 4)
			grid[i][j+1] = new Doodlebug();

		roundsAlive = 0;

		//if moveTo is 0 then set roundsAlive to 8 and addedDoodles to 0
		if(moveTo == 0){
			roundsAlive = 8;
			addedDoodles = 0;
		}
	}
	return addedDoodles;
}

/*
 * Deletes the doodle bug if it is going to starve
 * @param grid A 2d array of Organisms
 * @param i the x position of the doodle bug
 * @param j the y position of the doodle bug
 * @return doodleRemoved
 */
int Doodlebug::doodleStarve(Organism*** grid, int i, int j){
	int doodlesRemoved = 0; //keeps track of the doodle bugs removed
	//if roundsSinceLastEat is greater than or equal to 3 then make the coordinate equal to 0
	if(roundsSinceLastEat >= 3){
		grid[i][j] = 0;
		doodlesRemoved = -1;
	}
	return doodlesRemoved;
}

/*
 * Returns roundsSinceLastEat
 * @return roundsSinceLastEat
 */
int Doodlebug::getRoundsSinceLastEat(){
	return roundsSinceLastEat;
}

/*
 * return hasMoved
 * @return hasMoved
 */
bool Doodlebug::getHasMoved(){
	return hasMoved;
}

/*
 * sets hasMoved to false
 * @return void
 */
void Doodlebug::setHasMoved(){
	hasMoved = false;
}
