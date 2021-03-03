
#include "VertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int count)
:Count(count)
{
    glGenBuffers(1, &RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, RendererID);
    glBufferData(GL_ARRAY_BUFFER, 100 * sizeof(float) , data, GL_STATIC_DRAW);
    fprintf(stdout,"\n<VertexBuffer> Buffer size : %ld [bytes] \n ",100 * sizeof(float));
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
    //SetCount();
    int offset = 16 * sizeof(float);
    unsigned int size =  16 * sizeof(float);
    fprintf(stdout,"\n<VertexBuffer>Objects offset : %d  //[= 16]\n <VertexBuffer> Object no. : %d\n Object Size : %d \n",offset,GetCount(),size);
    Bind();
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, object);
}