#ifndef RENDERER_INCLUDED
#define RENDERER_INCLUDED

#include <GL/glew.h>
#include <GL/glut.h>
#include "../res/shaders/shader.h"
#include "buffers/IndexBuffer.h"
#include "buffers/VertexBuffer.h"
#include "layout/VertexArray.h"

class Renderer 
{
    public:
        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, unsigned int count) const;
        void Clear() const;
        void Refresh(int value) const;
    private:




};

#endif