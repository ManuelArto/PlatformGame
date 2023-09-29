ifeq ($(OS),Windows_NT)
	LDFLAGS = -lpdcurses
	OUT = Game.exe
else
	LDFLAGS = -lncursesw
	OUT = Game.out
endif
BIN_DIR = ./bin
SRC_DIR = ./src
MODEL_DIR = ./src/model
TEMPLATE_DIR = ./src/template
UTIL_DIR = ./src/util
CHARS_DIR = ./src/model/characters
CPPFLAGS = -g

# VPATH = src src/util src/model src/model/character

Game: main.o controller.o view.o player.o easyenemy.o mediumenemy.o hardenemy.o character.o platform.o bonus.o generator.o collisions.o
	g++ ${CPPFLAGS} -o ${OUT} ${BIN_DIR}/*.o ${LDFLAGS}

main.o: ${SRC_DIR}/Main.cpp ${SRC_DIR}/Controller.hpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${SRC_DIR}/Main.cpp

controller.o: ${SRC_DIR}/Controller.cpp ${SRC_DIR}/Controller.hpp ${SRC_DIR}/View.hpp ${UTIL_DIR}/Generator.hpp ${CHARS_DIR}/Player.hpp ${CHARS_DIR}/EasyEnemy.hpp ${CHARS_DIR}/MediumEnemy.hpp ${CHARS_DIR}/HardEnemy.hpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${SRC_DIR}/Controller.cpp

view.o: ${SRC_DIR}/View.cpp ${SRC_DIR}/View.hpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${SRC_DIR}/View.cpp

generator.o: ${UTIL_DIR}/Generator.cpp ${UTIL_DIR}/Generator.hpp ${MODEL_DIR}/Platform.hpp ${MODEL_DIR}/Bonus.hpp ${TEMPLATE_DIR}/PlatformsData.cpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${UTIL_DIR}/Generator.cpp

player.o: ${CHARS_DIR}/Player.cpp ${CHARS_DIR}/Player.hpp ${CHARS_DIR}/Character.hpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${CHARS_DIR}/Player.cpp

easyenemy.o: ${CHARS_DIR}/EasyEnemy.cpp ${CHARS_DIR}/EasyEnemy.hpp ${CHARS_DIR}/Character.hpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${CHARS_DIR}/EasyEnemy.cpp

mediumenemy.o: ${CHARS_DIR}/MediumEnemy.cpp ${CHARS_DIR}/MediumEnemy.hpp ${CHARS_DIR}/Character.hpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${CHARS_DIR}/MediumEnemy.cpp

hardenemy.o: ${CHARS_DIR}/HardEnemy.cpp ${CHARS_DIR}/HardEnemy.hpp ${CHARS_DIR}/Character.hpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${CHARS_DIR}/HardEnemy.cpp

character.o: ${CHARS_DIR}/Character.cpp ${CHARS_DIR}/Character.hpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${CHARS_DIR}/Character.cpp

platform.o: ${MODEL_DIR}/Platform.cpp ${MODEL_DIR}/Platform.hpp
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${MODEL_DIR}/Platform.cpp

bonus.o: ${MODEL_DIR}/Bonus.cpp ${MODEL_DIR}/Bonus.hpp 
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${MODEL_DIR}/Bonus.cpp

collisions.o: ${UTIL_DIR}/Collisions.cpp ${UTIL_DIR}/Collisions.hpp 
	g++ ${CPPFLAGS} -o ${BIN_DIR}/$@ -c ${UTIL_DIR}/Collisions.cpp

clean:
	rm ${BIN_DIR}/*.o ${OUT}