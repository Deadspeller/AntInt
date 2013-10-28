/* Texture-Header File for world.h */


#include "SOIL/SOIL.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

GLuint tex_ground[3]; //Textures
GLuint tex_ant;

int LoadTextures()                 // Load Images And Convert To Textures
{	


	//Texture 1
  	tex_ground[0] = SOIL_load_OGL_texture
        (
        "textures/ground_grass2.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
	//Texture 2
	tex_ground[1] = SOIL_load_OGL_texture
        (
        "textures/wall.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
	//Texture 3
	tex_ground[2] = SOIL_load_OGL_texture
        (
        "textures/roof.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
	//Ant Texture
	tex_ant = SOIL_load_OGL_texture
        (
        "textures/ant3.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT); //repeat image
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT); //repeat image
 
    	return true;                                  
}
