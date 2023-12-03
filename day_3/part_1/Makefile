solver: solver.o
	g++ solver.o -o solver
solver.o: main.cc
	g++ -std=c++20 -c main.cc -o solver.o
clean:
	rm solver
	rm *.o
