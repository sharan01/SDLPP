#ifndef RECT_HPP
#define RECT_HPP


//#include <SDL.h>
#include <SDL2/SDL.h>


namespace SDLXX{

struct Rect : SDL_Rect{
    Rect(){
        this->x=0;
        this->y=0;
        this->w=0;
        this->h=0;
    }

    Rect(int x, int y, int w=0, int h=0){
        this->x=x;
        this->y=y;
        this->w=w;
        this->h=h;
    }

    void empty(){
        this->x=0;
        this->y=0;
        this->w=0;
        this->h=0;
    }
};

}//namespace
#endif // RECT_HPP
