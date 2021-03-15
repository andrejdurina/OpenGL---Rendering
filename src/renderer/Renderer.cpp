#include "Renderer.h"


void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    shader.Bind();
    ib.Bind();
    va.Bind();
    glDrawElements(GL_TRIANGLES, 6  , GL_UNSIGNED_INT, nullptr);
    
}
void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Refresh(int value) const 
{
    glutPostRedisplay();
}