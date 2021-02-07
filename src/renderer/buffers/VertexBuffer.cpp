
#include "VertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, RendererID);
    glBufferData(GL_ARRAY_BUFFER, size * 16 * sizeof(float) , data, GL_STATIC_DRAW);
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
void VertexBuffer::AddObject(const void* object , unsigned int index )
{

    int offset = 4 *4 * sizeof(float) * index ;
    fprintf(stdout,"VertexBuffer: %d\n",offset);
    unsigned int size = 4*4*sizeof(float);
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, object);

}