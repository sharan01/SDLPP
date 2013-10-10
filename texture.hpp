#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Rect.hpp"



namespace SDLXX {


class Texture{
public:
    SDL_Texture *tex = nullptr;

    ~Texture(){
        SDL_DestroyTexture(tex);
    }

    void operator=(SDL_Texture *t){
        tex = t;
    }

    SDL_Texture* get(){
        return tex;
    }

    void queryTexture(SDLXX::Rect &rect){
        if(tex!=nullptr)
            SDL_QueryTexture(this->tex,NULL,NULL,&rect.w,&rect.h);
        else{
            std::cout << "texture query fail texture is nullptr" << std::endl;
           rect.w = 0;
           rect.h = 0;
        }
    }



};

}//end namespace






#endif // SDLPP_HEADER_H
