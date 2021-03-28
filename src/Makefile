LDFLAGS = -lcurses
CPPFLAGS = -g

Game: Main.o controller.o view.o player.o character.o
	g++ ${CPPFLAGS} -o Game.out Main.o Controller.o View.o Player.o Character.o ${LDFLAGS}

main.o: Main.cpp Controller.hpp
	g++ ${CPPFLAGS} -c Main.cpp

controller.o: Controller.cpp Controller.hpp View.hpp Player.hpp
	g++ ${CPPFLAGS} -c Controller.cpp

view.o: View.cpp View.hpp
	g++ ${CPPFLAGS} -c View.cpp

player.o: Player.cpp Player.hpp Character.hpp
	g++ ${CPPFLAGS} -c Player.cpp

character.o: Character.cpp Character.hpp
	g++ ${CPPFLAGS} -c Character.cpp

clean:
	rm -f *.o Game.out