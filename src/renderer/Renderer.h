#ifndef RENDERER_INCLUDED
#define RENDERER_INCLUDED

#include <GL/glew.h>
#include "../res/shaders/shader.h"
#include "buffers/Buffer.h"
#include "layout/VertexArray.h"

class Renderer 
{
    public:
        void Draw(const VertexArray& va, const Buffer& ib, const Shader& shader, unsigned int count) const;
        void Clear() const;
    private:




};

#endif