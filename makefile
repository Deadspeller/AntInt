OUTPUTFILE:= AntInt-0.1
INPUTFILE:= main
LIBSHEADER:= -I/usr/include/SFML/ -lsfml-graphics -lsfml-window -lsfml-system -lGLU -lGLEW -lGL -lSOIL
LIBSSO:= -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lGLU -lGLEW -lGL -lSOIL

all: install run

install: main.cpp include/SOIL/SOIL.h include/Timer.h include/world.h include/texture.h include/shoot.h include/menu.h
	echo "Create Object Files ..."
	g++ -c $(INPUTFILE).cpp $(LIBSHEADER)
	echo "Create Executable ..."
	g++ $(INPUTFILE).o -o $(OUTPUTFILE) $(LIBSSO)
	echo "Success. Launching Game ..."

#	g++ -m32 -o $(FILE)_64bit main.cpp include/SOIL/libSOIL.a -lsfml-window -lsfml-system -lGLU -lGLEW -lGL -lSOIL

setup:
	sudo apt-get install g++
	sudo apt-get install libglew-dev
	sudo apt-get install libsfml-dev 
	sudo apt-get install libsoil-dev
	sudo apt-get install freeglut3-dev

run: 	$(OUTPUTFILE)
	./$(OUTPUTFILE)

count:
	wc -l main.cpp include/*.h

.PHONY: all install clean
