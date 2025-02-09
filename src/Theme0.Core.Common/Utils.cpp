// Copyright 2025 Andreas Åkerberg

namespace ForradiaWorld
{
    int Hash(std::string_view text)
    {
        unsigned long hash { 5381 };

        for (size_t i { 0 }; i < text.size(); ++i)
        {
            hash = 33 * hash + (unsigned char)text[i];
        }

        return static_cast<int>(hash);
    }

    void SDLDeleter::operator()(SDL_Window* window) const
    {
        SDL_DestroyWindow(window);
    }

    void SDLDeleter::operator()(SDL_Renderer* renderer) const
    {
        SDL_DestroyRenderer(renderer);
    }

    void SDLDeleter::operator()(SDL_Surface* surface) const
    {
        SDL_FreeSurface(surface);
    }

    void SDLDeleter::operator()(SDL_Texture* texture) const
    {
        SDL_DestroyTexture(texture);
    }

    void SDLDeleter::operator()(TTF_Font* font) const
    {
        TTF_CloseFont(font);
    }
}
