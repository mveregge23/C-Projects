output: Barbarian.o BlueMen.o Character.o Die.o Game.o HarryPotter.o Medusa.o Menu.o main.o Vampire.o
	g++ main.o Barbarian.o BlueMen.o Character.o Die.o Game.o HarryPotter.o Medusa.o Menu.o Vampire.o -o output

Barbarian.o: Barbarian.hpp Barbarian.cpp
	g++ -c -std=c++11 Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c -std=c++11 BlueMen.cpp

Character.o: Character.cpp Character.hpp
	g++ -c -std=c++11 Character.cpp

Die.o: Die.cpp Die.hpp
	g++ -c -std=c++11 Die.cpp

Game.o: Game.cpp Game.hpp
	g++ -c -std=c++11 Game.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c -std=c++11 HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c -std=c++11 Medusa.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c -std=c++11 Menu.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c -std=c++11 Vampire.cpp

clean:
	rm *.o
