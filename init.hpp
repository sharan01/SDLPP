#ifndef INIT_HPP
#define INIT_HPP

//#include "SDL.h"
#include <SDL2/SDL.h>

namespace SDLXX
{


class Init{
public:
    Init(Uint32 flags){
        SDL_Init(flags);
    }

    ~Init(){
        SDL_Quit();
    }
};





}//SDLPP

#endif // INIT_HPP
