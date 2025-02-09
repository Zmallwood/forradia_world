// Copyright 2025 Andreas Åkerberg

#include "MouseUtils.hpp"

namespace ForradiaWorld
{

    PointF GetMousePosition()
    {
        int xPx;
        int yPx;

        SDL_GetMouseState(&xPx, &yPx);

        auto canvasSize = GetCanvasSize();

        auto x = static_cast<float>(xPx) / canvasSize.w;
        auto y = static_cast<float>(yPx) / canvasSize.h;

        return { x, y };
    }

}
