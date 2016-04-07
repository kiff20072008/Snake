all: snake

snake: main.o snake.o 
	g++ main.o snake.o  -o snake

main.o: main.cpp
	g++ -c main.cpp

snake.o: snake.cpp
	g++ -c snake.cpp


clean:
	rm -rf *.o snake