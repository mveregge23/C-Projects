output: main.o Menu.o Board.o Ant.o Location.o
	g++ -std=c++11  main.o Menu.o Board.o Ant.o Location.o -o output

main.o: main.cpp
	g++ -c -std=c++11  main.cpp

Menu.o: Menu.cpp
	g++ -c -std=c++11  Menu.cpp

Board.o: Board.cpp
	g++ -c -std=c++11 Board.cpp

Ant.o: Ant.cpp
	g++ -c -std=c++11 Ant.cpp

Location.o: Location.cpp
	g++ -c -std=c++11 Location.cpp

clean:
	rm *.o output
