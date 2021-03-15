#include "main.h"

using namespace glm;

void init()
{   
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void Refresh ( int value )
{
    glutPostRedisplay();
    glutTimerFunc(1000/30,Refresh,0);
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
    //TIMER
    double last_time = glfwGetTime(),final_time = 0,FPS;

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
    glutInit(&argc,argv);

    glViewport(0, 0, s->width, s->height);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    Mouse mouse;
    mouse.mousePointer(window);
    init();

    //Compile shaders
    Shader shader("res/shaders/objectShaders/ObjectShader.vs", "res/shaders/objectShaders/ObjectShader.fs");
    Shader shader2("res/shaders/objectShaders/ObjectShader.vs", "res/shaders/objectShaders/ObjectShader.fs");
    Shader shaderParticles("res/shaders/particlesShaders/particleShader.vs","res/shaders/particlesShaders/particleShader.fs");

    Shape shape;
    float *object = shape.AddObject(50.0, 50.0, 350.0, 350.0);
    float *object2 = shape.AddObject(1000.0, 500.0, 1300.0, 800.0);
    float *particle = shape.AddParticle();

    fprintf(stdout, "  Number of currently generated objects %d\n ", shape.GetCount());

    VertexArray va;
    VertexArray va2;
    VertexArray vapar;

    VertexBuffer vb(object, 16); // PICK
    VertexBuffer vb2(object2, 16);//PLACE
    VertexBuffer vbpar(particle,6);// PARTICLES
    
    VertexBufferLayout objlayout;
    objlayout.Push(2);
    objlayout.Push(2);
  
    VertexBufferLayout parlayout;
    parlayout.Push(2);

    va.AddBuffer(vb, objlayout);
    va2.AddBuffer(vb2, objlayout);
    vapar.AddBuffer(vbpar,parlayout);

    IndexBuffer ib(shape.GetIndices());
    IndexBuffer ib2(shape.GetIndices());
    IndexBuffer ibpar(shape.GetIndices());


    Texture texturePICK("renderer/texture/samples/PICK_1.png", GL_RGBA);
    shader.setInt("u_Texture", 0);

    Texture textureDROP("renderer/texture/samples/PLACE_1.png",GL_RGBA);
    shader2.setInt("u_Texture",0);  

    Renderer render;

    ParticleSystem particles;
    ParticleProps particleProps;

    particles.InitializeShader(shaderParticles);
    do
    {
        render.Clear();
        texturePICK.Bind(0);
        render.Draw(va, ib, shader);
        textureDROP.Bind(0);
        render.Draw(va2, ib2, shader2);

        render.Draw(vapar,ibpar,shaderParticles);

        glfwSwapBuffers(window);
        glfwPollEvents();

        glutTimerFunc(1000/30,Refresh,0);

        FPS++;
        final_time = glfwGetTime();
                if(final_time - last_time > 0)
        {
            fprintf(stdout,"FPS : %f \n", (FPS / ( final_time - last_time)));
            FPS = 0;
            last_time = final_time;
        }

    } //Check if the ESC key was pressed or the widow was closed.
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    glDeleteProgram(shader.ID);
    glDeleteProgram(shader2.ID);
    glfwTerminate();
}

