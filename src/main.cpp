#include "Game.h"

int main(int argc, char* argv[]) {
    Args args;

    if(argc == 2) {
        args.winWidth  = std::atoi(argv[0]);
        args.winHeight = std::atoi(argv[1]);
    } else { //Default parameters
        args.winWidth  = 1280;
        args.winHeight = 720;
    }

    Game* game = new Game(args);
    game->runLoop();
    delete game;

    return 0;
}
