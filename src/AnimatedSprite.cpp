//
// Created by douidik on 25/06/2020.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(const char *path,
                               int rows,
                               int columns,
                               Uint32 delay,
                               int x,
                               int y,
                               int w,
                               int h,
                               SDL_Renderer *p_renderer)
    :Sprite(path, x, y, w, h, p_renderer), m_timer(0)
{
    /* initializing the rect sources for the animation */
    for(uint y = 0; y < columns; y++) {
        for(uint x = 0; x < rows; x++) {
            SDL_Rect src;

            src.w = m_texture.width()  / rows;
            src.h = m_texture.height() / columns;

            src.x = src.w * x;
            src.y = src.h * y;

            m_sources.push_back(src);
        }
    }

    // Setting up the default source transform to the first element of the source array
    m_sourceTransform = m_sources.begin();
}

void AnimatedSprite::animatedRender(Uint32 dt, SDL_Renderer* p_renderer) {
    m_timer += dt;

    if(m_timer >= m_delay) {
        m_timer -= m_delay;
        //Swapping to the next frame
        m_sourceTransform++;

        if(m_sourceTransform == m_sources.end()) { //The frame is out of bounds, we restart the animation
            m_sourceTransform = m_sources.begin();
        }
    }

    SDL_RenderCopy(p_renderer, m_texture.get(), &*m_sourceTransform, &m_transform);
}
