#ifndef RENDERER_INCLUDED
#define RENDERER_INCLUDED

#include <GL/glew.h>
#include "../res/shaders/shader.h"
#include "buffers/IndexBuffer.h"
#include "buffers/VertexBuffer.h"
#include "layout/VertexArray.h"

class Renderer 
{
    public:
        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
        void Clear() const;
    private:




};

#endif