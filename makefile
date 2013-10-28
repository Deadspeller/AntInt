OUTPUTFILE:= AntInt-0.1
INPUTFILE:= include/levelmanager.cpp main
LIBSHEADER:= -lsfml-graphics -lsfml-window -lsfml-system -lGLU -lGLEW -lGL -lSOIL
LIBSSO:= -lsfml-graphics -lsfml-window -lsfml-system -lGLU -lGLEW -lGL -lSOIL

all: install run

install: main.cpp include/levelmanager.cpp
	echo "Create Object Files ..."
	g++ -c $(INPUTFILE).cpp $(LIBSHEADER)
	echo "Create Executable ..."
	g++ $(INPUTFILE).o -o $(OUTPUTFILE) $(LIBSSO)
	echo "Success. Launching Game ..."

setup:
	sudo apt-get install g++
	sudo apt-get install libglew-dev
	sudo apt-get install libsfml-dev 
	sudo apt-get install libsoil-dev
	sudo apt-get install freeglut3-dev

setup32:
	sudo apt-get install g++
	sudo apt-get install libglew-dev
	sudo apt-get install libsfml-dev 
	sudo cp -r SFML-2.0_32/* /usr/
	sudo apt-get install libsoil-dev
	sudo apt-get install freeglut3-dev

setup64:
	sudo apt-get install g++
	sudo apt-get install libglew-dev
	sudo apt-get install libsfml-dev 
	sudo cp -r SFML-2.1_64/* /usr/
	sudo apt-get install libsoil-dev
	sudo apt-get install freeglut3-dev

run: 	$(OUTPUTFILE)
	./$(OUTPUTFILE)

count:
	wc -l main.cpp include/*.h

.PHONY: all install clean
