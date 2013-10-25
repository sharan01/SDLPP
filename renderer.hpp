#ifndef RENDERER_HPP
#define RENDERER_HPP


//#include <SDL.h>
//#include <SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.hpp"
#include "texture.hpp"

namespace SDLXX {


class Renderer{
public:
    SDL_Renderer *ren = nullptr;

    Renderer(SDLXX::Window &window,int index, Uint32 flags){
        ren = SDL_CreateRenderer(window.get(),index,flags);

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
    void copyRotate(SDLXX::Texture &tex,
                    const SDL_Rect* srcrect,
                    const SDL_Rect* dstrect,
                    const double angle,
                    const SDL_Point *center,
                    const SDL_RendererFlip flip ){

        SDL_RenderCopyEx(this->ren,tex.get(),srcrect,dstrect,angle,center,flip);
    }

    SDLXX::Texture createTexture(const std::string &file){

        //auto *surface =   SDL_LoadBMP(file.c_str());
        auto *surface = IMG_Load(file.c_str());

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
