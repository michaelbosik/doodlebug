/*
 * PA5.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Simulation.h"

int main(int argc, char **argv){

	if (argc > 7){
			std::cout << "Error, incorrect number of arguments. Please enter arguments less than 7" << std::endl;
			return EXIT_FAILURE;
	}

	int gridSize = 20;//The size of the grid to be simulated
	int doodleBugs = 5;//The amound of ants to be simulated
	int ants = 100; //The amount of doodle bugs to be simulated
	int timeSteps = 1000;//The amount of steps to be simulated
	unsigned long seed = 1; //The seed used for the simulation
	unsigned int pause = 0; //keeps track of if the simulation should pause and for how many generations

	//if argc is greater than 1 then set gridSize to the first argument
	if (argc > 1)
		gridSize = atoi(argv[1]);
	//if argc is greater than 2 then set doodleBugs to the second argument
	if (argc > 2)
		doodleBugs = atoi(argv[2]);
	//if argc is greater than 3 then set ants to the third argument
	if (argc > 3)
		ants = atoi(argv[3]);
	//if argc is greater than 4 then set timeSteps to the fourth argument
	if (argc > 4)
		timeSteps = atoi(argv[4]);
	//if argc is greater than 5 then set seed to the fifth argument
	if (argc > 5)
		seed = atoi(argv[5]);

	if(seed==0)
		seed = time(0);

	srand(seed);

	//if argc is greater than 6 then set pause to the sixth argument
	if (argc > 6)
		pause = atoi(argv[6]);

	int origAnts = ants; //Keeps track of the original amount of ants
	int antCount = ants; //Keeps track of the amount of ants
	int origDoodles = doodleBugs; //Keeps track of the original amount of doodle bugs
	int doodleBugCount = doodleBugs; //Keeps track of the amount of doodle bugs

	Simulation sim = Simulation(gridSize);

	//Goes through sim.grid and adds the ants in randomly
	for(int a=0; a<ants; a++){
		int col = rand()%gridSize; //The x value to place the ant
		int row = rand()%gridSize; //the y value to place the ant
		//if sim.grid[row][col] == 0 then make an ant at that point
		//else decrease a by 1
		if(sim.grid[row][col] == 0)
			sim.grid[row][col] = new Ant();
		else
			a--;
	}

	//Goes through sim.grid and adds the doodle bugs in randomly
	for(int b=0; b<doodleBugs; b++){
		int col = rand()%gridSize;
		int row = rand()%gridSize;
		//if sim.grid[row][col] == 0 then make a doodle bug at that point
		//else decrease b by 1
		if(sim.grid[row][col] == 0)
			sim.grid[row][col] = new Doodlebug();
		else
			b--;
	}

	int gens = 0; //Keeps track of the generation
	int doodleDiff = 0; //Keeps track of the doodle bug differance
	int antDiff = 0; //keeps track of the ant difference
	//Goes through the amount of desired generations and simulates it
	for(int i=1; i<=timeSteps; i++){

		sim.print(sim.grid, gridSize);
		std::cout << std::endl;

		antDiff += sim.moveDoodleBugs(sim.grid, gridSize);
		doodleDiff += sim.starveDoodles(sim.grid, gridSize);

		doodleBugCount += sim.breedDoodles(sim.grid, gridSize);

		sim.moveAnts(sim.grid, gridSize);

		antCount += sim.breedAnts(sim.grid, gridSize);

		gens = i;
		//if sim.grid has either all ants, doodle bugs or 0's then stop the simulation
		if(sim.allAnts(sim.grid, gridSize) || sim.allDoodlebugs(sim.grid, gridSize) || sim.allDead(sim.grid, gridSize)){
			gens = i;
			i = timeSteps+1;
		}
		//if pause is greater than 0 and i is less than or equal to timeSteps then go to next if
		if(pause>0 && i<=timeSteps)
			//if i%pause==0 then pause until user presses key
			if(i%pause==0){
				std::cout << "Press Enter to continue. " << i << std::endl;
				std::cin.ignore();
			}
	}
	ants = antCount+antDiff;
	doodleBugs = doodleBugCount+doodleDiff;

	//Prints
	std::cout << "The original input arguments were: " << gridSize << " " << origDoodles << " " << origAnts << " " << timeSteps << " " << seed << " " << pause << std::endl;
	std::cout << "The number of steps taken were: " << gens << std::endl;
	std::cout << "The total number of ants created was: " << antCount << ". The total number of ants left on the grid are: " << ants << "." << std::endl;
	std::cout << "The total number of doodle bugs created was: " << doodleBugCount << ". The total number of doodle bugs left on the grid are: " << doodleBugs << "." << std::endl;
	std::cout << "The final grid is: " << std::endl;
	sim.print(sim.grid, gridSize);

	return 0;
}
