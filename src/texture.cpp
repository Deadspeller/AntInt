#include "texture.h"

GLuint tex_grass;
GLuint tex_antfeet;
GLuint tex_wood_horizontal;
GLuint tex_wood_vertical;
GLuint tex_hill;
GLuint tex_antbody;
GLuint tex_antback;
GLuint tex_honeycomb100;
GLuint tex_honeycomb90;
GLuint tex_honeycomb80;
GLuint tex_honeycomb60;
GLuint tex_honeycomb50;
GLuint tex_honeycomb30;
GLuint tex_honeycomb10;
GLuint tex_honeycomb5;

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

    //Ant Feet
    tex_antfeet = SOIL_load_OGL_texture
        (
        "textures/antfeet.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    //Antbody Texture
    tex_antbody = SOIL_load_OGL_texture
        (
        "textures/antbody.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    //Antback Texture
    tex_antback = SOIL_load_OGL_texture
        (
        "textures/antback.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    //Honeycomb Textures
    tex_honeycomb100 = SOIL_load_OGL_texture
        (
        "textures/honeycomb100.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    tex_honeycomb80 = SOIL_load_OGL_texture
        (
        "textures/honeycomb80.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    tex_honeycomb60 = SOIL_load_OGL_texture
        (
        "textures/honeycomb60.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    tex_honeycomb50 = SOIL_load_OGL_texture
        (
        "textures/honeycomb50.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    tex_honeycomb30 = SOIL_load_OGL_texture
        (
        "textures/honeycomb30.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    tex_honeycomb10 = SOIL_load_OGL_texture
        (
        "textures/honeycomb10.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    tex_honeycomb5 = SOIL_load_OGL_texture
        (
        "textures/honeycomb5.png",
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
