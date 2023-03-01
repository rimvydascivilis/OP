main: main.cpp funtions.o
	g++ -O3 -std=c++2a main.cpp funtions.o -o main.app

funtions.o: funtions.cpp funtions.h
	g++ -O3 -std=c++2a -c funtions.cpp

run: main
	./main.app

clean:
	rm -rf *.app *.o