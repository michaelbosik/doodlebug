Michael Bosik, Brian Earl

FILES INCLUDED:
 - makefile
 - Doxyfile
 - README.txt
 - Test1.txt
 - Test2.txt
 - PA5.cpp
 - Simulation.cpp
 - Simulation.h
 - Organism.cpp
 - Organism.h
 - Ant.cpp
 - Ant.h
 - Doodlebug.cpp
 - Doodlebug.h
 
SUMMARY

This program is a simulation of ants and doodle bugs which are both children of an organism class. For each step in the program,
the organims both move to an adjacent empty space and breed, creating another organism of the same type to an adjacent space.
Doodle bugs move towards ants in order to eat them and if they cant get to an ant in 3 turns, they starve and die.

HOW TO COMPILE

 - Eclipse
   - Load the project into eclipse
   - Build the project
   - Run the project with the arguments <gridSize> <#doodlebugs> <#ants> <#time_steps> <seed> <pause>
     - If no arguments or not enough arguments are provided, default values will be assigned.
     
 - Terminal
   - Navigate to the project folder
   - Run the command "make clean && make"
   - Run the command "./PA5 <gridSize> <#doodlebugs> <#ants> <#time_steps> <seed> <pause>"
   
DIFFICULTIES

The biggest difficulty in this project was commenting the methods, loops and if statements to our best and most specific ability.

