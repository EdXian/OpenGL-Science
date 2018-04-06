#include "iostream"
#include "GLFW/glfw3.h"
#include "math.h"
#include "src/snake.h"
#include "src/playground.h"


int  dirx=0 , diry=0;
playground myplayground(5,5);
bool restart=false;
bool grid_on=false;
double period=1;

void error_callback(int error, const char* description){
   std::cout<< std::endl;
    std::cout << error << description<<std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    switch (key) {
    case GLFW_KEY_RIGHT_BRACKET:
        if(action == GLFW_RELEASE){
            if(period<0.3){
                period = period*1.05;
            }else{
                period = period+0.1;
            }
        }
        break;
    case GLFW_KEY_LEFT_BRACKET:
        if(action == GLFW_RELEASE){
            if(period>0.3){
                 period -=0.1;
            }else{
                period *=0.95 ;
            }
        }
        break;
    case GLFW_KEY_E:
        if(action == GLFW_RELEASE)grid_on ^= true;

        break;
    case GLFW_KEY_Q:
            restart = true;
    case GLFW_KEY_W:

        dirx = 0;
        diry = 1;
        break;
    case GLFW_KEY_X:

        dirx = 0;
        diry = -1;
        break;
    case GLFW_KEY_A:

        dirx = -1;
        diry = 0;
        break;
    case GLFW_KEY_D:

        dirx = 1;
        diry = 0;
        break;
    default:
        break;
    }
}

int main(void){

    GLFWwindow* window;
    if (!glfwInit()) exit(EXIT_FAILURE);

    glfwSetErrorCallback(error_callback);
    window = glfwCreateWindow(800, 800, "Snake", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

   while(1){
       snake snake1;
       myplayground.set_ground_nxn(45,36);
       double now = glfwGetTime() ,lastTime=0;
       double delta ;
       int count = 0;
       while (!glfwWindowShouldClose(window))
       {
           now = glfwGetTime();
           delta = now - lastTime;
           glClear(GL_COLOR_BUFFER_BIT);
           myplayground.set_ground_grid(grid_on);
           myplayground.plot();
           if(restart){
             dirx = 0;
             diry = 0;
             period = 1.0;
             snake1.reset();
             restart = false;
            }
            snake1.set_move_dir(dirx,diry);
           if(delta >period){
             snake1.update();
             lastTime=now;
             count++;
             if(count > 3)
             {
                 snake1.growup();
                 count =0;
             }
           }
           snake1.plot();
           glfwSwapBuffers(window);
           glfwPollEvents();
       }
       if(glfwWindowShouldClose(window)){
           break;
       }
   }


    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

}



