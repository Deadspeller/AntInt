AntInt
=======

Before Compiling:
-------
Use `make setup32` or `make setup64` to install all neccessary librarys and files

The following librarys are installed:

- **make setup32:**

	`sudo apt-get install g++`

	`sudo apt-get install libglew-dev`

	`sudo apt-get install libsfml-dev` 

	`sudo cp -r SFML-2.0_32/* /usr/`

	`sudo apt-get install libsoil-dev`

	`sudo apt-get install freeglut3-dev`


- **make setup64:**

	`sudo apt-get install g++`

	`sudo apt-get install libglew-dev`

	`sudo apt-get install libsfml-dev` 

	`sudo cp -r SFML-2.1_64/* /usr/`

	`sudo apt-get install libsoil-dev`

	`sudo apt-get install freeglut3-dev`


Makefile:
-------

- `make` to compile and then start the game	
- `make install` to compile the game
- `make setup32` to install all librarys on 32bit Linux
- `make setup64` to install all librarys on 64bit Linux
- `make run` to start the game
- `make count` to count all the lines of code



Controlls in the Game:
-------
- `WASD`   -  Camera Movement
- `Mouse`  -	
- `SPACE` -	
- `F`  -  faster Simulation
- `G`  -  slower Simulation
- `ESC`  -  Exit-Game
- `1`  -  Ant-Mode
- `2`  -  Block-Mode
- `3`  -  Food-Mode
- `LMouse`  -  Place something (Ant-Mode, Block-Mode, Food-Mode)
- `RMouse`  -	



Known Bugs:
-------

- On 64 Bit all in runtime created blocks/food/ants isnt drawn correctly
