# The name of our project is "AntInt". CMakeLists files in this project can 
# refer to the root source directory of the project as ${AntInt_SOURCE_DIR} and 
# to the root binary directory of the project as ${AntInt_BINARY_DIR}. 

cmake_minimum_required (VERSION 2.6) 
project (AntInt) 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()

set(AntInt_SOURCES 
	src/main.cpp

	src/ant.cpp
	src/antki.cpp
        src/anthill.cpp
	src/square.cpp
        src/inputmanager.cpp
	src/hud.cpp
	src/leveldrawer.cpp
        #src/menu.cpp
	src/objectcreator.cpp
        src/texture.cpp
	src/timer.cpp
	src/world.cpp
        src/pathfind.cpp
        src/node.cpp
	src/levelmanager.cpp)

set(AntInt_HEADERS 
	src/ant.h
	src/anthill.h
	src/square.h
        src/inputmanager.h
	src/hud.h
	src/leveldrawer.h
        #src/menu.h
	src/objectcreator.h
	src/texture.h
	src/timer.h
        src/node.h
        src/pathfind.h
	src/world.h)

add_executable(AntInt ${AntInt_SOURCES}
	${AntInt_HEADERS})

find_package (SFML 2.0 REQUIRED system window graphics audio)
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
