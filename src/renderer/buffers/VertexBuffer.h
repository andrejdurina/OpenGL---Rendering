#ifndef VERTEX_BUFFER_INCLUDED
#define VERTEX_BUFFER_INCLUDED

class VertexBuffer
{

private:
    unsigned int RendererID;

public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void AddObject(const void* object, unsigned int index);
    void Bind() const;
    void Unbind() const;
};

#endif