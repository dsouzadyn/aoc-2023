solver: solver.o
	g++ -std=c++23 solver.o -o solver
solver.o: main.cc
	g++ -std=c++23 -c main.cc -o solver.o
clean:
	rm solver
	rm *.o
