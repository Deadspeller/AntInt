# The name of our project is "AntInt". CMakeLists files in this project can 
# refer to the root source directory of the project as ${AntInt_SOURCE_DIR} and 
# to the root binary directory of the project as ${AntInt_BINARY_DIR}. 

cmake_minimum_required (VERSION 2.6) 
project (AntInt) 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


add_subdirectory (include) 
#add_subdirectory (Demo)
