#ifndef VERTEX_BUFFER_LAYOUT_INCLUDE
#define VERTEX_BUFFER_LAYOUT_INCLUDE

#include <vector>
#include <GL/glew.h>

struct VertexBufferElement 
{
    unsigned int count;
    unsigned int type;
    unsigned char normalized;
    static unsigned int GetSizoeOfType(unsigned int type)
    {
        switch (type)
        {
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1;
        }
        return 0;
    }
};

class VertexBufferLayout
{
    private:
    std::vector<VertexBufferElement> Elements;
    unsigned int Stride;

    public:
    VertexBufferLayout()
    : Stride(0){}

/*     template<typename T>
    void Push(int count)
    {
        static_assert(false);
    }

    template <T> */
    void Push (unsigned int count)
    {
        Elements.push_back({count,GL_FLOAT, GL_FALSE});
        Stride += VertexBufferElement::GetSizoeOfType(GL_FLOAT) * count;
    }

  /*   template <typename T>
    void Push <unsigned int>(int count,bool normalized, int type)
    {
        Elements.push_back({GL_UNSIGNED_INT,count, GL_FALSE});
        Stride += VertexBufferElement::GetSizoeOfType(GL_UNSIGNED_INT);
    } */

    inline const std::vector<VertexBufferElement> GetElements() const {return Elements;}
    inline unsigned int GetStride() const {return Stride;}
};

#endif