
#include "VertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, RendererID);
    glBufferData(GL_ARRAY_BUFFER, 32 * sizeof(float) , data, GL_STATIC_DRAW);
    fprintf(stdout,"\n<VertexBuffer> Buffer size : %ld [bytes] \n ",32 * sizeof(float) );
}
VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1,&RendererID);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, RendererID);
}
void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void VertexBuffer::AddObject(float* object )
{   
    SetCount();
    unsigned int * data;
    int offset = 4 * sizeof(float) * GetCount();
    unsigned int size =  4 * sizeof(float);
    fprintf(stdout,"\n<VertexBuffer>Objects offset : %d  //[= 16]\n <VertexBuffer> Object no. : %d\n Object Size : %d \n",offset,GetCount() + 1,size);
    Bind();
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, object);
}