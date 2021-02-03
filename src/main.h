#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <unistd.h>


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <X11/Xlib.h>
#include <stb_image.h>

#include "callbacks/callBacks.hpp"


#include "res/texture/texture.h"
#include "res/shaders/shader.h"
#include "res/particleSystem/particles.hpp"

#include "renderer/objects/GenerateObject.h"
#include "renderer/buffers/VertexBuffer.h"
#include "renderer/buffers/IndexBuffer.h"
#include "renderer/layout/VertexArray.h"



