ifeq ($(OS),Windows_NT)
	LDFLAGS = -lpdcurses
	OUT = Game.exe
else
	LDFLAGS = -lncursesw
	OUT = Game.out
endif
SRC_DIR = ./src
CPPFLAGS = -g

Game: main.o controller.o view.o player.o easyenemy.o mediumenemy.o hardenemy.o character.o platform.o bonus.o generator.o collisions.o
	g++ ${CPPFLAGS} -o ${OUT} Main.o Controller.o View.o Generator.o Player.o EasyEnemy.o MediumEnemy.o HardEnemy.o Character.o Platform.o Bonus.o Collisions.o ${LDFLAGS}

main.o: ${SRC_DIR}/Main.cpp ${SRC_DIR}/Controller.hpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/Main.cpp

controller.o: ${SRC_DIR}/Controller.cpp ${SRC_DIR}/Controller.hpp ${SRC_DIR}/View.hpp ${SRC_DIR}/Generator.hpp ${SRC_DIR}/Player.hpp ${SRC_DIR}/EasyEnemy.hpp ${SRC_DIR}/MediumEnemy.hpp ${SRC_DIR}/HardEnemy.hpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/Controller.cpp

view.o: ${SRC_DIR}/View.cpp ${SRC_DIR}/View.hpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/View.cpp

generator.o: ${SRC_DIR}/Generator.cpp ${SRC_DIR}/Generator.hpp ${SRC_DIR}/Platform.hpp ${SRC_DIR}/Bonus.hpp ${SRC_DIR}/PlatformsData.cpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/Generator.cpp

player.o: ${SRC_DIR}/Player.cpp ${SRC_DIR}/Player.hpp ${SRC_DIR}/Character.hpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/Player.cpp

easyenemy.o: ${SRC_DIR}/EasyEnemy.cpp ${SRC_DIR}/EasyEnemy.hpp ${SRC_DIR}/Character.hpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/EasyEnemy.cpp

mediumenemy.o: ${SRC_DIR}/MediumEnemy.cpp ${SRC_DIR}/MediumEnemy.hpp ${SRC_DIR}/Character.hpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/MediumEnemy.cpp

hardenemy.o: ${SRC_DIR}/HardEnemy.cpp ${SRC_DIR}/HardEnemy.hpp ${SRC_DIR}/Character.hpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/HardEnemy.cpp

character.o: ${SRC_DIR}/Character.cpp ${SRC_DIR}/Character.hpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/Character.cpp

platform.o: ${SRC_DIR}/Platform.cpp ${SRC_DIR}/Platform.hpp
	g++ ${CPPFLAGS} -c ${SRC_DIR}/Platform.cpp

bonus.o: ${SRC_DIR}/Bonus.cpp ${SRC_DIR}/Bonus.hpp 
	g++ ${CPPFLAGS} -c ${SRC_DIR}/Bonus.cpp

collisions.o: ${SRC_DIR}/Collisions.cpp ${SRC_DIR}/Collisions.hpp 
	g++ ${CPPFLAGS} -c ${SRC_DIR}/Collisions.cpp

clean:
	rm *.o ${OUT}