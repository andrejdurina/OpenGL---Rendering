#include "Buffer.h"
#include <GL/glew.h>
#include <stdio.h>

Buffer::Buffer(unsigned int type, unsigned int TotalNumOfObjects)
:Type(type)
{
    //ASSERT(sizeof(unsigned int)== sizeof(GLuint));
    AssertSize();
    glGenBuffers(1, &RendererID);
    glBindBuffer(Type, RendererID);
    glBufferData(Type, Size*TotalNumOfObjects*NumOfData, nullptr, GL_STATIC_DRAW);
}
Buffer::~Buffer()
{
    glDeleteBuffers(1,&RendererID);
}

void Buffer::Bind() const
{
    glBindBuffer(Type, RendererID);
}
void Buffer::Unbind() const
{
    glBindBuffer(Type, 0);
}
void Buffer::AddObject(void* object )
{   SetCount();
    int offset = Size * Count;
    fprintf(stdout,"\n<Buffer>Objects offset : %d  //[= 16]\n <VertexBuffer> Object no. : %d\n Object Size : %d \n",offset,Count,Size);
    Bind();
    glBufferSubData(Type, offset, Size, object);
}
void Buffer::AssertSize()
{
    switch(Type)
    {
        case GL_ARRAY_BUFFER : Size = sizeof(float)*4;NumOfData = 4;break;// Size num in a row , NumOfData is num of columns.
        case GL_ELEMENT_ARRAY_BUFFER : Size = sizeof(unsigned int)*7;break;
    }
    
}

