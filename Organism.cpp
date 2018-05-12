/*
 * Organism.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#include "Organism.h"

Organism::Organism() {
	hasMoved = false;
}

Organism::~Organism() {}

/*
 * Returns if the organism is prey or not
 * @return NULL
 */
bool Organism::isPrey(){
	return NULL;
}

/*
 * Moves the Organism
 * @param grid A 2d array of Organisms
 * @param gridSize the length and width of grid
 * @param i the x position of the Organism
 * @param j the y position of the Organism
 * @param spaces an array of spaces around the Organism that are empty
 * @param prey an array of spaces around the Organism that are prey
 * @return 0
 */
int Organism::move(Organism*** grid, int gridSize, int i, int j, int* spaces, int* prey){

	int size  = 0; //keeps track of the size of spaces
	int moveTo = 0; //keeps track of where the organism is going to move to
	//Goes through spaces and keeps track of how many elements are in it
	for(unsigned int h = 0; h < sizeof(*spaces); h++)
		//if spaces[h] is greater than 0 then increase size by 1
		if(spaces[h]>0)
			size++;

	//if size is greater then zero then set moveTo to a random element in spaces
	if(size>0)
		moveTo = spaces[rand()%size];

	//if moveTo is 1 then make an Organism to the left
	//else if moveTo is 2 then make an Organism above
	//else if moveTo is 3 then make an Organism the right
	//else if moveTo is 4 then make an Organism below
	if (moveTo == 1)
		grid[i-1][j] = grid[i][j];
	else if (moveTo == 2)
		grid[i][j-1] = grid[i][j];
	else if (moveTo == 3)
		grid[i+1][j] = grid[i][j];
	else if (moveTo == 4)
		grid[i][j+1] = grid[i][j];

	//if moveTo is greater than zero then set the point at i and j to 0
	if (moveTo>0)
		grid[i][j] = 0;

	return 0;
}

/*
 * returns 0
 * @return 0
 */
int Organism::breed(Organism*** grid, int gridSize, int i, int j, int* spaces){
	return 0;
}

/*
 * returns 0
 * @return 0
 */
int Organism::doodleStarve(Organism*** grid, int i, int j){
	return 0;
}

/*
 * returns 0
 * @return 0
 */
int Organism::getRoundsSinceLastEat(){
	return 0;
}
/*
 * returns false
 * @return false
 */
bool Organism::getHasMoved(){
	return false;
}

/*
 * sets hasMoved to false
 * @return void
 */
void Organism::setHasMoved(){
	hasMoved = false;
}
