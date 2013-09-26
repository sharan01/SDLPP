#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


namespace SDLPP {


class Texture{
public:
    SDL_Texture *tex;
    Texture(SDL_Texture *t){
        tex = t;
    }
    ~Texture(){
        SDL_DestroyTexture(tex);
    }

    void operator=(SDL_Texture *t){
        tex = t;
    }

    SDL_Texture* get(){
        return tex;
    }

};

}//end namespace






#endif // SDLPP_HEADER_H
