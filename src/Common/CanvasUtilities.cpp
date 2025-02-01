#include "CanvasUtilities.hpp"
#include "Core/SDLDevice/SDLDevice.hpp"

namespace FW {
Size GetCanvasSize()
{
    Size canvasSize;

    SDL_GetWindowSize(_<SDLDevice>().GetWindow().get(), &canvasSize.w, &canvasSize.h);

    return canvasSize;
}

float GetAspectRatio()
{
    auto canvasSize = GetCanvasSize();

    return static_cast<float>(canvasSize.w) / canvasSize.h;
}
}
