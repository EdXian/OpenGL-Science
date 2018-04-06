#include "playground.h"


playground::playground(unsigned int width ,unsigned int length):
GRID_ON(true)
{

    board_length = length * box_size;
    board_width  = width * box_size;
}
void playground::set_ground_grid(bool grid_state){
    GRID_ON = grid_state;
}
bool playground::get_ground_isgrid(){
    return GRID_ON;
}

void playground::set_ground_nxn(unsigned int x, unsigned int y){
  width = x;
  length =y;
  board_width = x * box_size;
  board_length = y * box_size;
}




void playground::plot(){

if(GRID_ON){
    for(unsigned int i=0;i<length+1;i++){
        glBegin(GL_LINES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.5*board_width, -0.5*board_length+i*box_size, 0.f);
        glVertex3f(0.5*board_width,  -0.5*board_length+i*box_size, 0.f);
        glEnd();

    }
    for(unsigned int i=0;i<width+1;i++){
        glBegin(GL_LINES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.5*board_width+i*box_size, -0.5*board_length, 0.f);
        glVertex3f(-0.5*board_width+i*box_size,  0.5*board_length, 0.f);
        glEnd();

    }
}else{
    glBegin(GL_LINES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.5*board_width, -0.5*board_length, 0.f);
    glVertex3f(0.5*board_width,  -0.5*board_length, 0.f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.5*board_width, -0.5*board_length+length*box_size, 0.f);
    glVertex3f(0.5*board_width,  -0.5*board_length+length*box_size, 0.f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.5*board_width, -0.5*board_length, 0.f);
    glVertex3f(-0.5*board_width,  0.5*board_length, 0.f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.5*board_width+width*box_size, -0.5*board_length, 0.f);
    glVertex3f(-0.5*board_width+width*box_size,  0.5*board_length, 0.f);
    glEnd();
}
}
