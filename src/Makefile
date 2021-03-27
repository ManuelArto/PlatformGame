Game: Main.o controller.o screen.o player.o character.o
	g++ -g -o Game.out Main.o Controller.o Screen.o Player.o Character.o -lcurses

main.o: Main.cpp Controller.hpp
	g++ -g -c Main.cpp

controller.o: Controller.cpp Controller.hpp Screen.hpp Player.hpp
	g++ -g -c Controller.cpp

screen.o: Screen.cpp Screen.hpp
	g++ -g -c Screen.cpp

player.o: Player.cpp Player.hpp Character.hpp
	g++ -g -c Player.cpp

character.o: Character.cpp Character.hpp
	g++ -g -c Character.cpp

clean:
	rm -f *.o Game.out