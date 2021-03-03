#ifndef VERTEX_ARRAY_INCLUDED
#define VERTEX_ARRAY_INCLUDED

#include "VertexBufferLayout.h"
#include "../buffers/VertexBuffer.h"
class VertexArray{

    private:
    unsigned int RendererID;

    public:
    VertexArray();
    ~VertexArray();
    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void Bind () const ;
    void Unbind () const ;
};

#endif