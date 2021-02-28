#include "main.h"

using namespace glm;

void init()
{
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char **argv)
{
    glfwSetMonitorCallback(monitor_callback); //Mnitor connected/dsconnected callback.

    Display *d = XOpenDisplay(NULL);
    Screen *s = DefaultScreenOfDisplay(d);
    ///////////////////////////////////////////GLFW INIT/////////////////////////////////////////////
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW \n"); //Chyba nacitania GLFW <Graphic Library Framework>.
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, GLFW_DONT_CARE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Open window and create its OpenGL context///////////WINDOW/////////////////////////////
    GLFWwindow *window;

    window = glfwCreateWindow(s->width, s->height, "Test", glfwGetPrimaryMonitor(), NULL);
    if (window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.Version of OpenGL in this code should be set to version 2.1");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    // ////////////////////////////////////// GLEW INIT////////////////////////////////////////////////
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        fprintf(stderr, "GLEW Error: %s \n", glewGetErrorString(err));
        return -1;
    }
    else
    {
        fprintf(stdout, "GLEW Version: %s \n", glewGetString(GLEW_VERSION));
    }
    //##################################VIEWPORT#######################################################//
    //glViewport(0,0,3840,1080) - Custom viewport for 2 monitors;

    glViewport(0, 0, s->width, s->height);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    mousePointer(window);
    init();

    //Compile shaders
    Shader shader("res/shaders/objectShaders/SimpleVertexShader.vs", "res/shaders/objectShaders/Obj1_FragmentShader.fs");
    Shader shader2("res/shaders/objectShaders/SimpleVertexShader.vs", "res/shaders/objectShaders/Obj1_FragmentShader.fs");

    Geometry shape;
    float *object = shape.createObject(50.0, 50.0, 350.0, 350.0);


    fprintf(stdout, "%d\n ", shape.GetCount());

    VertexArray va;

    Buffer VertexBuffer(GL_ARRAY_BUFFER, shape.GetCount());
    Buffer IndexBuffer(GL_ELEMENT_ARRAY_BUFFER, shape.GetCount());

    VertexBuffer.AddObject(object);
    IndexBuffer.AddObject(shape.GetIndices());

    VertexBufferLayout layout;
    layout.Push(2);
    layout.Push(2);
    va.AddBuffer(VertexBuffer, layout);

    Texture texturePICK("renderer/texture/samples/PICK_1.png", GL_RGBA);

    texturePICK.Bind(0);
    shader.setInt("u_Texture", 0);

/*  Texture textureDROP("renderer/texture/samples/PLACE_1.png",GL_RGBA);

    textureDROP.Bind(1);
    shader2.setInt("u_Texture",0);   */

    Renderer render;
    vec4 active_color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
    do
    {
        render.Clear();
        render.Draw(va, IndexBuffer, shader, shape.GetCount());
        // Draw rectangle !
        glfwSwapBuffers(window);
        glfwPollEvents();
    } //Check if the ESC key was pressed or the widow was closed.
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    glDeleteProgram(shader.ID);
    glDeleteProgram(shader2.ID);
    glfwTerminate();
}