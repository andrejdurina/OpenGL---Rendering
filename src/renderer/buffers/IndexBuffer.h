#ifndef INDEX_BUFFER_INCLUDED
#define INDEX_BUFFER_INCLUDED

class IndexBuffer
{

private:
    unsigned int RendererID;

public:
    IndexBuffer(const unsigned int* data);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;
};

#endif