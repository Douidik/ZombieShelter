//
// Created by douidik on 25/06/2020.
//

#ifndef SHELTER_SPRITE_H
#define SHELTER_SPRITE_H

#include <SDL2/SDL.h>
#include "Texture.h"

class Sprite {
public:
    Sprite(const char *path, int x, int y, int w, int h, SDL_Renderer *p_renderer);
    ~Sprite() = default;

    inline void setPosition(int x, int y) {
        m_transform.x = x;
        m_transform.y = y;
    }

    inline void setScale(int w, int h) {
        m_transform.w = w;
        m_transform.h = h;
    }

    void render(SDL_Renderer *p_renderer);

private:
    Texture m_texture;
    SDL_Rect m_transform;
};

#endif //SHELTER_SPRITE_H
