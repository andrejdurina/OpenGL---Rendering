
#include "VertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, RendererID);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float) , data, GL_STATIC_DRAW);
    fprintf(stdout,"\n<VertexBuffer> Buffer size : %ld [bytes] \n ",size * sizeof(float));
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