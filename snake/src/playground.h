#ifndef _PLAYGROUND_H_
#define _PLAYGROUND_H_
#include "GLFW/glfw3.h"
#define box_size 0.04



class playground {
public:
    playground(unsigned int width ,unsigned int length);
    void set_ground_nxn(unsigned int x,unsigned int y);
    void set_ground_text();
    void set_ground_grid(bool grid);

    bool get_ground_isgrid();


    void plot();
private:
    double board_length , board_width;
    unsigned int width ,length;
    bool GRID_ON;


};



#endif
