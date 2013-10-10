#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>


namespace SDLXX {


class Window{
public:
    SDL_Window *win;

    Window(const std::string &title,int x, int y, int w, int h, Uint32 flags){
        win = SDL_CreateWindow(title.c_str(),x,y,w,h,flags);
    }
    ~Window(){
        SDL_DestroyWindow(this->win);
    }
    SDL_Window* get(){
        return this->win;
    }
    void setIcon(const std::string &file){

        auto *icon = IMG_Load(file.c_str());

        SDL_SetWindowIcon(this->win, icon);

        SDL_FreeSurface(icon);
    }

};

}//end namespace






#endif // SDLPP_HEADER_H
