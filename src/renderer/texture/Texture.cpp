#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

Texture::Texture(const std::string& path, GLenum mode )
   : RendererID(0), FilePath(path) , LocalBuffer(nullptr), Width(0), Height(0), BPP(0)
{
    //stbi_set_flip_vertically_on_load(1);
    
    LocalBuffer = stbi_load(path.c_str() ,&Width, &Height, &BPP, 4);;

    glGenTextures(1, &RendererID);
    glBindTexture(GL_TEXTURE_2D, RendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if(LocalBuffer)
    {
        glTexImage2D(GL_TEXTURE_2D, 0 ,mode, Width, Height, 0, mode, GL_UNSIGNED_BYTE, LocalBuffer);
        glGenerateMipmap(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, RendererID);
        fprintf(stdout,"\n Loaded some texture \n");
        stbi_image_free(LocalBuffer);
    }
    else 
    {
        fprintf(stdout,"\n Couldnt load texture \n");
        stbi_image_free(LocalBuffer);
    }

}

Texture::~Texture()
{
    glDeleteTextures(1,&RendererID);
}
void Texture::Bind(unsigned int slot) const
{
     glBindTextureUnit(slot, RendererID);
}

void Texture::Unbind()
{

};