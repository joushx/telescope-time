telescope-time: main.o
	g++ -o telescope-time main.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -Wall -std=c++11
