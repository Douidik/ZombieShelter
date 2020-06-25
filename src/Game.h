//
// Created by douidik on 25/06/2020.
//

#ifndef SHELTER_GAME_H
#define SHELTER_GAME_H

#include <SDL2/SDL.h>

struct Args {
    int winHeight, winWidth;
};

class Game {
public:
    Game(Args args);
    ~Game();

    void runLoop();

private:
    SDL_Window* mp_window;
    SDL_Renderer* mp_renderer;
};


#endif //SHELTER_GAME_H
