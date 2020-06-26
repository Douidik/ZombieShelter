//
// Created by douidik on 25/06/2020.
//

#ifndef SHELTER_TEXTURE_H
#define SHELTER_TEXTURE_H

#include <SDL2/SDL.h>

class Texture {
public:
    /* load from file constructor */
    Texture(const char* path, SDL_Renderer* p_renderer);
    ~Texture();

    inline SDL_Texture* get() {
        return mp_texture;
    }

    inline int width() const {
        return m_width;
    }

    inline int height() const {
        return m_height;
    }

private:
    SDL_Texture* mp_texture;
    int m_width, m_height;
};


#endif //SHELTER_TEXTURE_H
