/* Texture-Header File for world.h */


#include "SOIL/SOIL.h"
#include <iostream>

using namespace std;

GLuint tex_ground[3]; //Textures

int LoadTextures()                 // Load Images And Convert To Textures
{	
	//Texture 1
  	tex_ground[0] = SOIL_load_OGL_texture
        (
        "/home/deadspeller/Dokumente/ds-game/textures/ground_grass.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
	//Texture 2
	tex_ground[1] = SOIL_load_OGL_texture
        (
        "/home/deadspeller/Dokumente/ds-game/textures/wall.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
	//Texture 3
	tex_ground[2] = SOIL_load_OGL_texture
        (
        "/home/deadspeller/Dokumente/ds-game/textures/roof.jpg",
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
