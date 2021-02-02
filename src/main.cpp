#include "main.h"
using namespace glm;

void init()
{   glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable (GL_BLEND);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glLineWidth(3.5);
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
        fprintf(stderr, "Error: %s \n", glewGetErrorString(err));
        return -1;
    }
    else
    {
        fprintf(stdout, "Version: %s \n", glewGetString(GLEW_VERSION));
    }

    //##################################VIEWPORT#######################################################//
    //glViewport(0,0,3840,1080) - Custom viewport for 2 monitors;
    glViewport(0,0,s->width,s->height);

    int viewportData[4];
    glGetIntegerv(GL_VIEWPORT,viewportData);

    Pixels object1(50,50,250,250);
    
    float* obj1;
    obj1 = new float [7];
    
    mousePointer(window);

    obj1 = transformCoord(viewportData,&object1);
    
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    init(); 
    
    //Compile shaders
    Shader shader("res/shaders/objectShaders/SimpleVertexShader.vs", "res/shaders/objectShaders/Obj1_FragmentShader.fs");

    unsigned int VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    unsigned int VB1;
    glGenBuffers(1, &VB1);
    glBindBuffer(GL_ARRAY_BUFFER, VB1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*4*2, obj1, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);   
    glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 0,0);

    unsigned int indices[] = {
        0,1,2,2,3,0
    };
     
    unsigned int ibo;
    glGenBuffers(1,&ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 7*sizeof(unsigned int),&indices[0],GL_STATIC_DRAW);
    
    
    vec4 active_color = vec4(1.0f,0.0f,0.0f,1.0f);

    unsigned int texture1 , texture2;
    Texture texture;
    texture1 = texture.loadTexture("res/texture/TextureDROP.jpg",GL_RGB);
    texture2 = texture.loadTexture("res/texture/TexturePICK.png",GL_RGBA);

    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader.use();
        active_color = randomNum(); // THis line ,,more frequently or oscilating between two colors.
        // Sets color of rectangle !
        shader.setVec4("u_Color",active_color);
        glBindVertexArray(VertexArrayID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        // Draw rectangle !
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr); // 4 indices starting at 0 -> 1 rectangle      
        glfwSwapBuffers(window);
        glfwPollEvents();
    } //Check if the ESC key was pressed or the widow was closed.
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    delete obj1;
    //delete active_color;
    glDeleteProgram(shader.ID);
    glfwTerminate();
}