all: binary_tree

binary_tree: main.o
	g++ -o binary_tree main.o

main.o: main.cpp
	g++ -o main.o main_tests.cpp -c -W -Wall -std=c++11

clean:
	rm -rf *.o *~binary_tree
