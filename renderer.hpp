#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL2/SDL.h>
#include "window.hpp"
#include "texture.hpp"

namespace SDLXX {


class Renderer{
public:
    SDL_Renderer *ren = nullptr;

    Renderer(SDLXX::Window &window,int index, Uint32 flags){
        ren = SDL_CreateRenderer(window.get(),index,flags);
        if(ren==nullptr){
            std::cout << "render null" << std::endl;
        }
    }
    ~Renderer(){
        SDL_DestroyRenderer(ren);
    }
    SDL_Renderer* get(){
        return  this->ren;
    }

    void clear(){
        SDL_RenderClear(this->ren);
    }
    void copy(SDLXX::Texture &tex,SDL_Rect *src,SDL_Rect *dst){
        SDL_RenderCopy(this->ren,tex.get(),src,dst);

    }
    SDLXX::Texture createTexture(const std::string &file){

        SDL_Surface *surface = IMG_Load(file.c_str());

        SDLXX::Texture tex;
        tex = SDL_CreateTextureFromSurface(this->ren, surface);
        SDL_FreeSurface(surface);

        return tex;
    }

    void present(){
        SDL_RenderPresent(this->ren);
    }

//    SDLXX::Texture loadTexture(const std::string &file){

//    }
};

}//namepsace
#endif // RENDERER_HPP
