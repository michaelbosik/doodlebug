/*
 * Simulation.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#include "Simulation.h"

Simulation::Simulation(int gridSize) {
	grid = new Organism**[gridSize];
	//Goes through the gridSize and makes an empty 2d array
	for(int i = 0; i < gridSize; i++){
		grid[i] = new Organism*[gridSize];
	}

	//goes through the x values of grid
	for(int i = 0; i < gridSize; i++){
		//goes through the y value of grid
		for(int j = 0; j < gridSize; j++)
			grid[i][j] = NULL;
	}
}

Simulation::~Simulation() {}

/*
 * returns true if a point is inside the grid
 * @param x the x point you want to check
 * @param y the y point you want to check
 * @param gridSize the length and width of the grid you are testing
 * @return false if the point is outside the grid and true if it is inside the grid
 */
bool isInGrid(int x, int y, int gridSize){
	//if x or y is less than 0 or greater than gridSize then return false
	if(x >= gridSize || x < 0 || y >= gridSize || y < 0 )
		return false;
	return true;
}

/*
 * Prints out a grid
 * @param grid The 2d array of Organisms you want to print out
 * @param gridSize the length and width of  grid
 */
void Simulation::print(Organism*** grid, int gridSize){
	//goes through the x values of grid
	for(int i = 0; i < gridSize; i++)
	{
		//goes through the x values of grid
		for(int j = 0; j < gridSize; j++)
		{
			//if this point in grid is equal to zero then print a space
			//else if this point in grid is prey then print an "o"
			//else if this point in grid isnt prey then print an "x"
			//else print out a space
			if(grid[i][j] == 0)
				std::cout << " ";
			else if(grid[i][j]->isPrey())
				std::cout << "o";
			else if(grid[i][j]->isPrey() == false)
				std::cout << "x";
			else
				std::cout << " " << std::endl;
		}
		std::cout << std::endl;
	}
}

/*
 * Returns an array of numbers based on if the spaces around a point are empty or not
 * @param grid The 2d array of Organisms you want to test in
 * @param gridSize the length and width of  grid
 * @param x the x point you are testing
 * @param y the y point you are testing
 * @return an array of int
 */
int* Simulation::getAdjSpaces(Organism*** grid, int gridSize, int x, int y){
	int* spaces = new int[4]; //An array to keep track of numbers that represent coordinates
	int place = 0; //keeps track of the amount of elements in spaces

	//if the place to the left of x and y is in the grid and equal to zero
	//add 1 to spaces and increase place by 1
	if(isInGrid(x-1,y,gridSize) && grid[x-1][y]==0){
		spaces[place] = 1;
		place++;
	}
	//if the place above of x and y is in the grid and equal to zero
	//add 2 to spaces and increase place by 1
	if(isInGrid(x,y-1,gridSize) && grid[x][y-1]==0){
		spaces[place] = 2;
		place++;
	}
	//if the place to the right of x and y is in the grid and equal to zero
	//add 3 to spaces and increase place by 1
	if(isInGrid(x+1,y,gridSize) && grid[x+1][y]==0){
		spaces[place] = 3;
		place++;
	}
	//if the place below x and y is in the grid and equal to zero
	//add 4 to spaces and increase place by 1
	if(isInGrid(x,y+1,gridSize) && grid[x][y+1]==0){
		spaces[place] = 4;
		place++;
	}
	return spaces;
}

/*
 * Returns an array of numbers based on if the spaces around a point are prey or not
 * @param grid The 2d array of Organisms you want to test in
 * @param gridSize the length and width of  grid
 * @param x the x point you are testing
 * @param y the y point you are testing
 * @return an array of int
 */
int* Simulation::getAdjPrey(Organism*** grid, int gridSize, int x, int y){
	int* prey = new int[4];//An array to keep track of numbers that represent coordinates
	int place = 0; //keeps track of the amount of elements in spaces

	//if the spot to the left of x and y is in grid and not equal to zero, go to next if
	if(isInGrid(x-1,y,gridSize) && !grid[x-1][y]==0)
		//if the spot to the left of x and y is prey then put 1 in prey and increase place by 1
		if(grid[x-1][y]->isPrey()){
			prey[place] = 1;
			place++;
		}
	//if the spot above x and y is in grid and not equal to zero, go to next if
	if(isInGrid(x,y-1,gridSize) && !grid[x][y-1]==0)
		//if the spot above x and y is prey then put 2 in prey and increase place by 1
		if(grid[x][y-1]->isPrey()){
			prey[place] = 2;
			place++;
		}
	//if the spot to the right of x and y is in grid and not equal to zero, go to next if
	if(isInGrid(x+1,y,gridSize) && !grid[x+1][y]==0)
		//if the spot to the right of x and y is prey then put 3 in prey and increase place by 1
		if(grid[x+1][y]->isPrey()){
			prey[place] = 3;
			place++;
		}
	//if the spot below x and y is in grid and not equal to zero, go to next if
	if(isInGrid(x,y+1,gridSize) && !grid[x][y+1]==0)
		//if the spot below x and y is prey then put 4 in prey and increase place by 1
		if(grid[x][y+1]->isPrey()){
			prey[place] = 4;
			place++;
		}

	return prey;
}

/* Moves all the doodle bugs in a 2d array of Organisms
* @param grid The 2d array of Organisms you want to test in
* @param gridSize the length and width of  grid
* @return removeAnts
*/
int Simulation::moveDoodleBugs(Organism*** grid, int gridSize){
	int removeAnts = 0; //keeps track of the removed ants
	//goes though the x values for grid
	for(int i=0; i<gridSize; i++)
		//goes through the y values for grid
		for(int j=0; j<gridSize; j++)
			//if the point in grid doesnt equal 0 then go to next if
			if(grid[i][j] != 0)
				//if the point isnt pray and hasMoved is false the move the doodle bug at that point
				if(!grid[i][j]->isPrey() && !grid[i][j]->getHasMoved()){
					int* spaces = getAdjSpaces(grid, gridSize, i, j);
					int* prey = getAdjPrey(grid, gridSize, i, j);
					removeAnts += grid[i][j]->move(grid, gridSize, i, j, spaces, prey);
				}
	return removeAnts;
}

/*
 * Starves all of the doodle bugs that are going to starve
 * @param grid The 2d array of Organisms you want to test in
 * @param gridSize the length and width of  grid
 * @return remDoodles
 */
int Simulation::starveDoodles(Organism*** grid, int gridSize){
	int remDoodles = 0; //keeps track of the removed doodle bugs
	//goes though the x values for grid
	for(int i=0; i<gridSize; i++)
		//goes though the y values for grid
		for(int j=0; j<gridSize; j++)
			//if the point in grid doesnt equal 0 then go to next if
			if(grid[i][j] != 0)
				//if the point isnt prey and hasMoved is true then starve the doodle bug
				if(!grid[i][j]->isPrey() && grid[i][j]->getHasMoved())
					remDoodles += grid[i][j]->doodleStarve(grid, i, j);
	setFalse(grid, gridSize);

	return remDoodles;
}

/*
 * Breed all of the doodle bugs that are going to breed
 * @param grid The 2d array of Organisms you want to test in
 * @param gridSize the length and width of  grid
 * @return addedDoodles
 */
int Simulation::breedDoodles(Organism*** grid, int gridSize){
	int addedDoodles=0; //keeps track of the added doodle bugs
	//goes though the x values for grid
	for(int i=0; i<gridSize; i++)
		//goes though the y values for grid
		for(int j=0; j<gridSize; j++){
			int* spaces = getAdjSpaces(grid, gridSize, i, j);
			//if the point doesnt equal 0 and isnt prey then breed the doodle bug
			if(grid[i][j]!=0 && !grid[i][j]->isPrey())
				addedDoodles += grid[i][j]->breed(grid, gridSize, i, j, spaces);
		}
	return addedDoodles;
}

/*
 * Breed all of the ants that are going to breed
 * @param grid The 2d array of Organisms you want to test in
 * @param gridSize the length and width of  grid
 * @return addedAnts
 */
int Simulation::breedAnts(Organism*** grid, int gridSize){
	int addedAnts = 0;//keeps track of the added ants
	//goes though the x values for grid
	for(int i=0; i<gridSize; i++)
		//goes though the y values for grid
		for(int j=0; j<gridSize; j++){
			int* spaces = getAdjSpaces(grid, gridSize, i, j);
			//if the point doesnt equal 0 and is prey then breed the ant
			if(grid[i][j]!=0 && grid[i][j]->isPrey())
				addedAnts += grid[i][j]->breed(grid, gridSize, i, j, spaces);
		}
	return addedAnts;
}

/* Moves all the ants in a 2d array of Organisms
* @param grid The 2d array of Organisms you want to test in
* @param gridSize the length and width of  grid
* @return void
*/
void Simulation::moveAnts(Organism*** grid, int gridSize){
	//goes though the x values for grid
	for(int i=0; i<gridSize; i++)
		//goes though the y values for grid
		for(int j=0; j<gridSize; j++)
			//if the point doesnt equal 0 then go to next if
			if(grid[i][j] != 0)
				//if the point is pray and hasMoved is false then move the ant
				if(grid[i][j]->isPrey() && !grid[i][j]->getHasMoved()){
					int* spaces = getAdjSpaces(grid, gridSize, i, j);
					int* prey = getAdjPrey(grid, gridSize, i, j);
					grid[i][j]->move(grid, gridSize, i, j, spaces, prey);
				}
	setFalse(grid, gridSize);
}

/*
 * sets all hasMoved variables to false in a 2d array of Organisms
 * @param grid The 2d array of Organisms you want to test in
 * @param gridSize the length and width of  grid
 * @return void
 */
void Simulation::setFalse(Organism*** grid, int gridSize){
	//goes though the x values for grid
	for(int i=0; i<gridSize; i++)
		//goes though the y values for grid
		for(int j=0; j<gridSize; j++)
			//if the point doesnt equal 0 then set hasMoved to false
			if(grid[i][j] != 0)
				grid[i][j]->setHasMoved();
}

/*
 * Checks if a 2d array of Organisms is all ants
 * @param grid The 2d array of Organisms you want to test in
 * @param gridSize the length and width of  grid
 * @return false if it isnt all ants and true if it is
 */
bool Simulation::allAnts(Organism*** grid, int gridSize){
	//goes though the x values for grid
	for(int i=0; i<gridSize; i++)
		//goes though the y values for grid
		for(int j=0; j<gridSize; j++)
			//if the point doesnt equal 0 then go to next if
			if(grid[i][j] != 0)
				//if isPrey() is true then return false
				if(grid[i][j]->isPrey())
					return false;
	return true;
}

/*
 * Checks if a 2d array of Organisms is all doodle bugs
 * @param grid The 2d array of Organisms you want to test in
 * @param gridSize the length and width of grid
 * @return false if it isnt all doodle bugs and true if it is
 */
bool Simulation::allDoodlebugs(Organism*** grid, int gridSize){
	//goes though the x values for grid
	for(int i=0; i<gridSize; i++)
		//goes though the y values for grid
		for(int j=0; j<gridSize; j++)
			//if the point doesnt equal 0 then go to next if
			if(grid[i][j] != 0)
				//if isPrey() is false then return false
				if(!grid[i][j]->isPrey())
					return false;
	return true;
}

/*
 * Checks if a 2d array of Organisms is all 0
 * @param grid The 2d array of Organisms you want to test in
 * @param gridSize the length and width of  grid
 * @return false if all points arent 0 and true if they are
 */
bool Simulation::allDead(Organism*** grid, int gridSize){
	//goes though the x values for grid
	for(int i=0; i<gridSize; i++)
		//goes though the y values for grid
		for(int j=0; j<gridSize; j++)
			//if the point doest equal 0 the return false
			if(grid[i][j] != 0)
				return false;
	return true;
}
