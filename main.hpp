#ifndef MAIN_H
#define MAIN_H





#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.hpp"
#include "window.hpp"


namespace SDLPP {



class Main{

private:

public:
    SDL_Window *win;
    SDL_Renderer *ren;

    Main(){

    }
    ~Main(){
        SDL_DestroyWindow (win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }
    //error code
    void logSDLError (std::ostream &os, const std::string &msg){
        os << msg << " error: " << SDL_GetError() << std::endl;
    }

    // initalize
    int init(Uint32 flags){
        if (SDL_Init(flags) != 0){
            return 0;
        }else{
            return 1;
        }
    }
    // window

    int createWindow(const std::string &title,
                            int x, int y, int w,
                            int h, Uint32 flags){
        win = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

        if(win == nullptr){
            return 0;
        }
        return 1;
    }

    // renderer
    int createRenderer(int index,Uint32 flags){
        ren = SDL_CreateRenderer(this->win,index,flags);
        if(ren == nullptr){
            return 0;
        }
        return 1;
    }
     //image load
    SDL_Surface* loadIMG(std::string &file){
        SDL_Surface *img = IMG_Load(file.c_str());
        return img;
    }

    SDL_Texture* loadTexture(const std::string &file){
        SDL_Texture *texture = IMG_LoadTexture(this->ren,file.c_str());

        if (texture == nullptr)
                logSDLError(std::cout, "LoadTexture");

        return texture;
    }

    void renderTexture(SDL_Texture *tex, int x, int y,int w=0,int h=0){
        //Setup the destination rectangle to be at the position we want
        SDL_Rect dst;
        dst.x = x;
        dst.y = y;
        dst.w = w;
        dst.h = h;
        //Query the texture to get its width and height to use if not specified
        if(w==0 && h==0){
            SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
        }

        SDL_RenderCopy(this->ren, tex, NULL, &dst);
    }

    // helper
    void renderClear(){
        SDL_RenderClear(this->ren);
    }
    void renderPresent(){
        SDL_RenderPresent(this->ren);
    }



};

}// namepace
#endif // SDLPP
