#include "IndexBuffer.h"
#include <GL/glew.h>
#include <stdio.h>

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
:Count(count)
{
    //ASSERT(sizeof(unsigned int)== sizeof(GLuint));
    glGenBuffers(1, &RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 7 * sizeof(unsigned int) * Count, data, GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1,&RendererID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RendererID);
}
void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void IndexBuffer::AddObject(unsigned int* object )
{   
    unsigned int size = 7 * sizeof(unsigned int);
    int offset = size * GetCount();
    fprintf(stdout,"\n<IndexBuffer> Objects offset : %d  //[= 7]\n <IndexBuffer> Object no. : %d\n Object Size : %d \n",offset,GetCount(),size);
    Bind();
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, size, object);
}
