#ifndef BUFFER_INCLUDED
#define BUFFER_INCLUDED

class Buffer
{

private:
    unsigned int RendererID;
    unsigned int Count = 0;
    unsigned int Type;
    unsigned int Size;
    unsigned int NumOfData = 1;

public:
    Buffer(unsigned int type , unsigned int count);
    ~Buffer();
   
    void Bind() const;
    void Unbind() const;
    void AssertSize();
    void AddObject(void* object);
    inline void SetCount(){Count = Count + 1;};
    };

#endif