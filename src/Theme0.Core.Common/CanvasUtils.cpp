// Copyright 2025 Andreas Åkerberg

#include "CanvasUtils.hpp"

#include "Theme0.Core.Devices/SDLDevice.hpp"

namespace ForradiaWorld
{

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

    float ConvertWidthToHeight(float width)
    {
        return width * GetAspectRatio();
    }

    float ConvertHeightToWidth(float height)
    {
        return height / GetAspectRatio();
    }

}
