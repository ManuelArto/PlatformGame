ifeq ($(OS),Windows_NT)
	LDFLAGS = -lpdcurses
	OUT = Game.exe
else
	LDFLAGS = -lncursesw
	OUT = Game.out
endif
CPPFLAGS = -g

Game: main.o controller.o view.o player.o easyenemy.o mediumenemy.o hardenemy.o character.o platform.o bonus.o generator.o
	g++ ${CPPFLAGS} -o ${OUT} Main.o Controller.o View.o Generator.o Player.o EasyEnemy.o MediumEnemy.o HardEnemy.o Character.o Platform.o Bonus.o ${LDFLAGS}

main.o: Main.cpp Controller.hpp
	g++ ${CPPFLAGS} -c Main.cpp

controller.o: Controller.cpp Controller.hpp View.hpp Generator.hpp Player.hpp EasyEnemy.hpp MediumEnemy.hpp HardEnemy.hpp
	g++ ${CPPFLAGS} -c Controller.cpp

view.o: View.cpp View.hpp
	g++ ${CPPFLAGS} -c View.cpp

generator.o: Generator.cpp Generator.hpp Platform.hpp Bonus.hpp
	g++ ${CPPFLAGS} -c Generator.cpp

player.o: Player.cpp Player.hpp Character.hpp
	g++ ${CPPFLAGS} -c Player.cpp

easyenemy.o: EasyEnemy.cpp EasyEnemy.hpp Character.hpp
	g++ ${CPPFLAGS} -c EasyEnemy.cpp

mediumenemy.o: MediumEnemy.cpp MediumEnemy.hpp Character.hpp
	g++ ${CPPFLAGS} -c MediumEnemy.cpp

hardenemy.o: HardEnemy.cpp HardEnemy.hpp Character.hpp
	g++ ${CPPFLAGS} -c HardEnemy.cpp

character.o: Character.cpp Character.hpp
	g++ ${CPPFLAGS} -c Character.cpp

platform.o: Platform.cpp Platform.hpp
	g++ ${CPPFLAGS} -c Platform.cpp

bonus.o: Bonus.cpp Bonus.hpp 
	g++ ${CPPFLAGS} -c Bonus.cpp

clean:
	rm *.o ${OUT}