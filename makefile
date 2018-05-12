# Set CFLAGS to activate all warnings and enable debugger
CFLAGS = -Wall -g

# Default rule is to build the executable called PA5
all: PA5

# Rule for building the executable.
PA5: PA5.o Ant.o Doodlebug.o Organism.o Simulation.o
	g++ $(CFLAGS) PA5.o Ant.o Doodlebug.o Organism.o Simulation.o -o PA5

# Rules for building each object file.
PA5.o: PA5.cpp 
	g++ $(CFLAGS) -c PA5.cpp
	
Ant.o: Ant.cpp Ant.h
	g++ $(CFLAGS) -c Ant.cpp
	
Doodlebug.o: Doodlebug.cpp Doodlebug.h 
	g++ $(CFLAGS) -c Doodlebug.cpp
	
Organism.o: Organism.cpp Organism.h
	g++ $(CFLAGS) -c Organism.cpp
	
Simulation.o: Simulation.cpp Simulation.h
	g++ $(CFLAGS) -c Simulation.cpp
	
# Give command "make clean" to remove object files,
#  executable, and documentation.
clean:
	rm -f *.o PA5
	rm -f -r html latex

# Give command "make docs" to create documentation.
docs:
	doxygen
