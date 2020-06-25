//
// Created by douidik on 25/06/2020.
//

#include "Sprite.h"

Sprite::Sprite(const char *path, int x, int y, int w, int h, SDL_Renderer *p_renderer)
    : m_texture(path, p_renderer)
{
    setPosition(x, y);
    setScale(w, h);
}

void Sprite::render(SDL_Renderer *p_renderer) {
    SDL_RenderCopy(p_renderer, m_texture.get(), NULL, &m_transform);
}
