output: proj4.o maze.o
	g++ proj4.o maze.o -o output
proj4.o: proj4.cpp
	g++ -c proj4.cpp
maze.o: maze.cpp
	g++ -c maze.cpp
clean:
	rm *.o output