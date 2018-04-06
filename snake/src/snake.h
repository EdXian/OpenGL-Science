#ifndef _SNAKE_H__
#define _SNAKE_H__
#include "vector"
#include "GLFW/glfw3.h"
#include "math.h"

#define piece_radius 0.02




class snake
{
    struct piece{
        double x;
        double y;
        double last_x;
        double last_y;
    };
typedef std::vector<piece> snake_body;
public:
   snake();
   ~snake();

   snake_body body;
   void set_move_dir(int speedx,int speedy);
   void set_snake_color();
   void set_head_position();

   void get_head_position();

   int get_body_length();


   void growup();
   void reset();
   void update();
   void plot();
private:
    unsigned int  body_length;
    int  dirx,diry;



};



#endif
