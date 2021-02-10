#ifndef VERTEX_BUFFER_INCLUDED
#define VERTEX_BUFFER_INCLUDED

class VertexBuffer
{

private:
    unsigned int RendererID;
    unsigned int Count = 0;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void AddObject(float* object);
    inline void SetCount(){Count += 1;};
    inline unsigned int GetCount(){return Count;};
    void Bind() const;
    void Unbind() const;
};

#endif