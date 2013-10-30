# Add executable called "AntIntDemo" that is built from the source files 
# "main.cxx" and "main_b.cxx". The extensions are automatically found. 

add_executable (AntIntDemo main.cpp)

find_package (SFML)
if (SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIRS})
  target_link_libraries (AntIntDemo ${SFML_LIBRARIES})
endif (SFML_FOUND)

find_package(GLUT)
if (GLUT_FOUND)
  include_directories(${GLUT_INCLUDE_DIRS})
  target_link_libraries (AntIntDemo ${GLUT_LIBRARIES})
endif (GLUT_FOUND)

find_package(OpenGL)
if (OpenGL_FOUND)
  include_directories(${OpenGL_INCLUDE_DIRS})
  target_link_libraries (AntIntDemo ${OpenGL_LIBRARIES})
endif (OpenGL_FOUND)



find_package (SOIL)
if (SOIL_FOUND)
  include_directories(${SOIL_INCLUDE_DIRS})
  target_link_libraries (AntIntDemo ${SOIL_LIBRARIES})
endif (SOIL_FOUND)

find_package (GLEW)
if (GLEW_FOUND)
  include_directories(${GLEW_INCLUDE_DIRS})
  target_link_libraries (AntIntDemo ${GLEW_LIBRARIES})
endif (GLEW_FOUND)
