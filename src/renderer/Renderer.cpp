#include "Renderer.h"

void Renderer::Draw(const VertexArray& va, const Buffer& ib, const Shader& shader, unsigned int count) const
{
    shader.Bind();
    ib.Bind();
    va.Bind();
    glDrawElements(GL_TRIANGLES, 6 * count  , GL_UNSIGNED_INT, nullptr);
    
}
void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}