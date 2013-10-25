AntInt
=======
+-----------------+
|Before Compiling:|
+-----------------+
You probably need the following Librarys:

use "make setup32" or "make setup64" to install all neccessary librarys and files

- sudo apt-get install g++
- sudo apt-get install libglew-dev //GLEW Library
- sudo apt-get install libsfml-dev //SFML Library
- sudo apt-get install libsoil-dev //SOIL Library
- sudo apt-get install freeglut3-dev //Glut Library

- setup32:
	sudo apt-get install g++
	sudo apt-get install libglew-dev
	sudo apt-get install libsfml-dev 
	sudo cp -r SFML-2.0_32/* /usr/
	sudo apt-get install libsoil-dev
	sudo apt-get install freeglut3-dev

- setup64:
	sudo apt-get install g++
	sudo apt-get install libglew-dev
	sudo apt-get install libsfml-dev 
	sudo cp -r SFML-2.1_64/* /usr/
	sudo apt-get install libsoil-dev
	sudo apt-get install freeglut3-dev

+-----------------+
|Compile the Game:|
+-----------------+

Makefile:
- "$ make" to compile and then start the game	
- "$ make install" to compile the game
- "$ make run" to start the game
- "$ make count" to count all the lines of code


+----------------------+
|Controlls in the Game:|
+----------------------+
- WASD		-	Camera Movement
- Mouse		-	
- "SPACE" 	-	
- "F"		- 	
- "G"		-	
- "ESC"		- 	Exit-Game
- LMouse 	- 	Place Ant
- RMouse	-	


+-----------+
|Known Bugs:|
+-----------+

- 
