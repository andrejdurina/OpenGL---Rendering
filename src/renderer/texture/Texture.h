#ifndef TEXTURE_INCLUDED
#define TEXTURE_INCLUDED
#include <GL/glew.h>
#include <string>

class Texture {

    private:
        unsigned int RendererID;
        std::string FilePath;
        unsigned char* LocalBuffer;
        int Width, Height, BPP;

    public:
        Texture(const std::string& path, GLenum mode);
         ~Texture();
      void Bind(unsigned int slot = 0) const;
      void Unbind();

      inline int GetWidth(){return Width;}
      inline int GetHeight(){return Height;}
};

#endif 