output: main.o Animal.o Menu.o Penguin.o Tiger.o Zoo.o Turtle.o
	g++ -std=c++11 main.o Animal.o Penguin.o Tiger.o Zoo.o Turtle.o Menu.o -o output

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

Animal.o: Animal.cpp Animal.hpp
	g++ -c -std=c++11 Animal.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c -std=c++11 Menu.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -c -std=c++11 Penguin.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -c -std=c++11 Tiger.cpp

Zoo.o: Zoo.cpp Zoo.hpp
	g++ -c -std=c++11 Zoo.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -c -std=c++11 Turtle.cpp

clean:
	rm *.o
