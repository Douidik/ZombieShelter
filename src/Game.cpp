//
// Created by douidik on 25/06/2020.
//

#include "Game.h"
#include <iostream>
#include "AnimatedSprite.h"

Game::Game(Args args) {
    /* Initializing SDL */

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Failed to initialize SDL2" << std::endl;
        exit(1);
    }

    /* Initializing SDL window and renderer */

    mp_window = SDL_CreateWindow("Zombie Shelter",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 args.winWidth,
                                 args.winHeight,
                                 NULL);

    if(!mp_window) {
        std::cerr << "Failed to create the window" << std::endl;
        exit(1);
    }

    mp_renderer = SDL_CreateRenderer(mp_window, -1, NULL);

    if(!mp_renderer) {
        std::cerr << "Failed to create the renderer" << std::endl;
        exit(1);
    }

    //Disable window resize
    SDL_SetWindowResizable(mp_window, SDL_FALSE);
}

Game::~Game() {
    SDL_DestroyRenderer(mp_renderer);
    SDL_DestroyWindow(mp_window);

    SDL_Quit();
}

void Game::runLoop() {
    bool isRunning = true;
    SDL_Event event;
    AnimatedSprite s("test.bmp", 8, 1, 400, 400, 150, 500, 500, mp_renderer);

    Uint32 dt = 0, lt = 0;

    while(isRunning) {
        Uint32 time = SDL_GetTicks();
        dt = time - lt;
        lt = time;

        /* Querying events */
        while(SDL_PollEvent(&event)) { // Checking each events for this frame
            switch(event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
        }

        /* Updating */

        /* Rendering */
        //-clearing
        SDL_RenderClear(mp_renderer);

        //-drawing
        s.animatedRender(dt, mp_renderer);

        //-swapping buffers
        SDL_RenderPresent(mp_renderer);
    }
}
