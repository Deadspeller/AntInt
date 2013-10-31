# The name of our project is "AntInt". CMakeLists files in this project can 
# refer to the root source directory of the project as ${AntInt_SOURCE_DIR} and 
# to the root binary directory of the project as ${AntInt_BINARY_DIR}. 

cmake_minimum_required (VERSION 2.6) 
project (AntInt) 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(AntInt_SOURCES 
	src/main.cpp
	src/levelmanager.cpp)

set(AntInt_HEADERS 
	src/ant.h
	src/anthill.h
	src/anthandler.h
	src/block.h
	src/blockhandler.h
	src/cameracalc.h
	src/hud.h
	src/leveldrawer.h
	src/menu.h
	src/objectcreator.h
	src/texture.h
	src/timer.h
	src/world.h)

add_executable(AntInt ${AntInt_SOURCES}
	${AntInt_HEADERS})

find_package (SFML 2.0 REQUIRED system window graphics)
if (SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIRS})
  target_link_libraries (AntInt ${SFML_LIBRARIES})
endif (SFML_FOUND)

find_package(GLUT)
if (GLUT_FOUND)
  include_directories(${GLUT_INCLUDE_DIRS})
  target_link_libraries (AntInt ${GLUT_LIBRARIES})
endif (GLUT_FOUND)

find_package(OpenGL)
if (OpenGL_FOUND)
  include_directories(${OpenGL_INCLUDE_DIRS})
  target_link_libraries (AntInt ${OpenGL_LIBRARIES})
endif (OpenGL_FOUND)

find_package (SOIL)
if (SOIL_FOUND)
  include_directories(${SOIL_INCLUDE_DIRS})
  target_link_libraries (AntInt ${SOIL_LIBRARIES})
endif (SOIL_FOUND)
