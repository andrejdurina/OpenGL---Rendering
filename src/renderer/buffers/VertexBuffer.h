#ifndef VERTEX_BUFFER_INCLUDED
#define VERTEX_BUFFER_INCLUDED

class VertexBuffer
{

private:
    unsigned int RendererID;

public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;
};

#endif