#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



namespace SDLXX {


class Texture{
public:
    SDL_Texture *tex = nullptr;
    SDL_Surface *surface;

    ~Texture(){
        SDL_DestroyTexture(tex);
    }

    void operator=(SDL_Texture *t){
        tex = t;
    }

    SDL_Texture* get(){
        return tex;
    }

    void queryTexture(int *w, int *h){
        if(tex!=nullptr)
            SDL_QueryTexture(this->tex,NULL,NULL,w,h);
        else{
            std::cout << "texture query fail texture is nullptr" << std::endl;
           *w = 0;
           *h = 0;
        }
    }



};

}//end namespace






#endif // SDLPP_HEADER_H
