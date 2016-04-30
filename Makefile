CC=g++
CFLAGS=-std=c++11 -Wall -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

all: main
	./main

main: player.o main.cpp # whatever else
	$(CC) player.o main.cpp $(CFLAGS) -o main

player.o: player.cpp
	$(CC) -c player.cpp $(CFLAGS)

clean:
	rm *.o
	rm main
