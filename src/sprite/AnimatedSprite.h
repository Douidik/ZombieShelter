//
// Created by douidik on 25/06/2020.
//

#ifndef SHELTER_ANIMATEDSPRITE_H
#define SHELTER_ANIMATEDSPRITE_H

#include "Sprite.h"
#include <vector>

using Vec2 = std::pair<int, int>;

class AnimatedSprite : Sprite {
public:
    AnimatedSprite(const char *path,
                   int rows,
                   int columns,
                   Uint32 delay,
                   int x,
                   int y,
                   int w,
                   int h,
                   SDL_Renderer *p_renderer);

    void animatedRender(Uint32 dt, SDL_Renderer* p_renderer);

private:
    int m_index;
    std::vector<SDL_Rect> m_sources;
    std::vector<SDL_Rect>::iterator m_sourceTransform; // iterator to the current element in the array of sources
    Uint32 m_timer, m_delay;
};


#endif //SHELTER_ANIMATEDSPRITE_H
