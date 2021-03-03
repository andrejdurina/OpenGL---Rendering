#ifndef VERTEX_BUFFER_INCLUDED
#define VERTEX_BUFFER_INCLUDED

class VertexBuffer
{

private:
    unsigned int RendererID;
    unsigned int Count;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void AddObject(float* object);
    inline unsigned int GetCount(){return Count;};
    inline void SetCount(){Count++;};
    void Bind() const;
    void Unbind() const;
};

#endif