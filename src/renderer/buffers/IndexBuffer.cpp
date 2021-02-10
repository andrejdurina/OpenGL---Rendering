#include "IndexBuffer.h"
#include <GL/glew.h>

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
:Count(count)
{
    //ASSERT(sizeof(unsigned int)== sizeof(GLuint));
    glGenBuffers(1, &RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 7 * sizeof(unsigned int), data, GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1,&RendererID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, RendererID);
}
void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
