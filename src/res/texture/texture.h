#define STB_IMAGE_IMPLEMENTATION
#include <stdio.h>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"

class Texture 
{
    public :
    unsigned int loadTexture(std::string filepath, GLenum mode){


    unsigned int texture;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    
    int width=512,height=512,channels,dchannel;

    stbi_set_flip_vertically_on_load(true);
    unsigned char* imageData=stbi_load(filepath.c_str() ,&width, &height, &channels, 0);
        if(imageData)
    {
        glTexImage2D(GL_TEXTURE_2D, 0 ,mode, width, height, 0, mode, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);
        fprintf(stdout,"Loaded some texture \n");
    }
    else 
    {
        fprintf(stdout,"Couldnt load texture \n");
    }
    stbi_image_free(imageData);

    return texture;
 };
};