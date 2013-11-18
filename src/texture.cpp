#include "texture.h"

GLuint tex_grass;
GLuint tex_ant;
GLuint tex_wood_horizontal;
GLuint tex_wood_vertical;
GLuint tex_hill;

int LoadTextures()                 // Load Images And Convert To Textures
{

    //Grass
    tex_grass = SOIL_load_OGL_texture
        (
        "textures/ground_grass.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    //wood horizontal
    tex_wood_horizontal = SOIL_load_OGL_texture
        (
        "textures/wood_horizontal.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    //wood horizontal
    tex_wood_vertical = SOIL_load_OGL_texture
        (
        "textures/wood_vertical.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    //hill
    tex_hill = SOIL_load_OGL_texture
        (
        "textures/hill.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    //Ant Texture
    tex_ant = SOIL_load_OGL_texture
        (
        "textures/ant.png",
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
