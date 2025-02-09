// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{
    class SDLDeleter
    {
      public:
        void operator()(SDL_Window* window) const;
        void operator()(SDL_Renderer* renderer) const;
        void operator()(SDL_Surface* surface) const;
        void operator()(SDL_Texture* texture) const;
        void operator()(TTF_Font* font) const;
    };
}
