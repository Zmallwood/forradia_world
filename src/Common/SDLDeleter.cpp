#include "SDLDeleter.hpp"

namespace FW {
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
