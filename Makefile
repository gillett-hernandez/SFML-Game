CC=g++
CFLAGS=-Wall -lsfml-system -lsfml-window -lsfml-graphics

all: main
	./main

main: main.o component.o# whatever else
	$(CC) main.o component.o $(CFLAGS) -o main

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

component.o: component.cpp
	$(CC) -c component.cpp $(CFLAGS)

clean:
	rm *.o
