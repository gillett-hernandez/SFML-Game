CC=g++
CFLAGS=-Wall -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

all: main
	./main

main: player.o main.cpp# whatever else
	$(CC) player.o main.cpp $(CFLAGS) -o main

player.o:
	$(CC) -c player.cpp $(CFLAGS)

clean:
	rm *.o
	rm main
