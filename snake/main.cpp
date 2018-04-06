#include "iostream"
#include "GLFW/glfw3.h"
#include "math.h"
#include "src/snake.h"

snake snake1;
void error_callback(int error, const char* description){
   std::cout<< std::endl;
    std::cout << error << description<<std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    switch (key) {
    case GLFW_KEY_W:
        snake1.set_move_dir(0,1);
        break;
    case GLFW_KEY_X:
        snake1.set_move_dir(0,-1);
        break;
    case GLFW_KEY_A:
        snake1.set_move_dir(-1,0);
        break;
    case GLFW_KEY_D:
        snake1.set_move_dir(1,0);
        break;
    default:
        break;
    }
}
int main(void){

    GLFWwindow* window;
    if (!glfwInit()) exit(EXIT_FAILURE);

    glfwSetErrorCallback(error_callback);
    window = glfwCreateWindow(600, 600, "Snake", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    double now = glfwGetTime() ,lastTime=0;
    double delta ;
    int count = 0;
    while (!glfwWindowShouldClose(window))
    {
        now = glfwGetTime();
        delta = now - lastTime;
        glClear(GL_COLOR_BUFFER_BIT);
        if(delta >1){
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

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

}



