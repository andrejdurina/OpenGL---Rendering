#include "main.h"

using namespace glm;

void init()
{   glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable (GL_BLEND);
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

    glViewport(0,0,s->width,s->height);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    mousePointer(window);
    init(); 
    
   
    //Compile shaders
    Shader shader("res/shaders/objectShaders/SimpleVertexShader.vs", "res/shaders/objectShaders/Obj1_FragmentShader.fs");

    Geometry shape;
    float * object = shape.createRectangle(1.0,50.0,250.0,250.0);


    VertexArray va;
    VertexBuffer vb (object, 4*2*sizeof(float));


    VertexBufferLayout layout;
    layout.Push(2);
    va.AddBuffer(vb,layout);


    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    IndexBuffer ib(shape.GetRectangleIndices(),6);

    unsigned int texture1 , texture2;
    Texture texture;
    texture1 = texture.loadTexture("res/texture/TextureDROP.jpg",GL_RGB);
    texture2 = texture.loadTexture("res/texture/TexturePICK.png",GL_RGBA);

    vec4 active_color = vec4(1.0f,0.0f,0.0f,1.0f);
    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader.use();
        //active_color = randomNum(); // THis line ,,more frequently or oscilating between two colors.
        shader.setVec4("u_Color",active_color);
        va.Bind();
        ib.Bind();
        // Draw rectangle !
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr); // 4 indices starting at 0 -> 1 rectangle      
        glfwSwapBuffers(window);
        glfwPollEvents();
    } //Check if the ESC key was pressed or the widow was closed.
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    glDeleteProgram(shader.ID);
    glfwTerminate();
}