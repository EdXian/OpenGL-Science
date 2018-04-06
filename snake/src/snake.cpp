#include "snake.h"


snake::snake() :
dirx(0),
diry(0)
{
    piece data;
    data.x = 0;
    data.y = piece_radius;
    body.push_back(data);
    data.x = 0;
    data.y += 0-2*piece_radius;
    body.push_back(data);
    data.x = 0;
    data.y += 0-2*piece_radius;
    body.push_back(data);
    data.x = 0;
    data.y += 0-2*piece_radius;
    body.push_back(data);
    data.x = 0;
    data.y += 0-2*piece_radius;
    body.push_back(data);
}

snake::~snake(){

}
void snake::growup(){
    piece data;
    unsigned int index = body.size();
    this->update();
    data.x = body[index-1].last_x;
    data.y = body[index-1].last_y;
    body.push_back(data);
}
void snake::reset(){
    piece data;
    body.clear();
    data.x = 0;
    data.y = piece_radius;
    body.push_back(data);
    data.x = 0;
    data.y += 0-2*piece_radius;
    body.push_back(data);
    data.x = 0;
    data.y += 0-2*piece_radius;
    body.push_back(data);
    data.x = 0;
    data.y += 0-2*piece_radius;
    body.push_back(data);
    data.x = 0;
    data.y += 0-2*piece_radius;
    body.push_back(data);
}


void snake::update(){
    for(unsigned int i=0;i<body.size();i++){
        body[i].last_x = body[i].x;
        body[i].last_y = body[i].y;
    }
  if(this->dirx!=0 || this->diry !=0){

    for(unsigned int i=body.size();i>0;i--){

        if(i==1){
            body[i-1].x += 2*piece_radius*dirx;
            body[i-1].y += 2*piece_radius*diry;

        }else{
            body[i-1].x = body[i-2].x;
            body[i-1].y = body[i-2].y;

        }
    }

  }
}
void snake::set_move_dir(int speedx,int speedy){
    if(speedx == -1*dirx && speedx!=0){
         diry = speedy;
    }else{
        dirx = speedx;
    }
    if(speedy == -1*diry && speedy!=0){
         dirx = speedx;
    }else{
        diry = speedy;
    }
}

void snake::plot(){
    for( unsigned int j=0;j<body.size();j++){
         glBegin(GL_LINE_LOOP);
         for (unsigned int i=0; i < 360; i++)
         {
            float degInRad = 3.14169/180*i;
            if(j==0){
                glColor3f(0.f, 0.f, 1.f);
            }else if(j== body.size()-1){
                glColor3f(1.0f, 1.0f, 0.0f);
            }else{
                glColor3f(1.f, 1.f, 1.f);
            }

            glVertex2f(body[j].x+cos(degInRad)*piece_radius,body[j].y+sin(degInRad)*piece_radius);
         }

         glEnd();
    }
}
