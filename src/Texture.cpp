//
// Created by douidik on 25/06/2020.
//

#include "Texture.h"

Texture::Texture(const char *path, SDL_Renderer* p_renderer) {
    SDL_Surface* p_surface = SDL_LoadBMP(path);
    mp_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    SDL_FreeSurface(p_surface);

    /* Retrieving texture infos */
    SDL_QueryTexture(mp_texture, nullptr, nullptr, &m_width, &m_height);

}

Texture::~Texture() {
    SDL_DestroyTexture(mp_texture);
}
