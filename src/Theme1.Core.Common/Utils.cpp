/*
 * Copyright (c) 2025 Andreas Åkerberg.
 * All rights reserved.
 *
 * This file is part of Forradia World.
 *
 * Licensed under the MIT License (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://opensource.org/licenses/MIT
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Theme1.Core.Devices/SDLDevice.hpp"

namespace ForradiaWorld
{
    /*
============= GENERAL UTILITIES ============= */

    int Hash(std::string_view text)
    {
        /* Alghorithm from forgotten source on the net. */

        unsigned long hash { 5381 };

        for (size_t i { 0 }; i < text.size(); ++i)
        {
            hash = 33 * hash + (unsigned char)text[i];
        }

        return static_cast<int>(hash);
    }

    /*
CLASS: SDLDeleter */

    void SDLDeleter::operator()(SDL_Window* window) const
    {
        /* Proper destruction of SDL_Window object. */

        SDL_DestroyWindow(window);
    }

    void SDLDeleter::operator()(SDL_Renderer* renderer) const
    {
        /* Proper destruction of SDL_Renderer object. */

        SDL_DestroyRenderer(renderer);
    }

    void SDLDeleter::operator()(SDL_Surface* surface) const
    {
        /* Proper destruction of SDL_Surface object. */

        SDL_FreeSurface(surface);
    }

    void SDLDeleter::operator()(SDL_Texture* texture) const
    {
        /* Proper destruction of SDL_Texture object. */

        SDL_DestroyTexture(texture);
    }

    void SDLDeleter::operator()(TTF_Font* font) const
    {
        /* Proper destruction of TTF_Font object. */

        TTF_CloseFont(font);
    }

    /*
============= STRING UTILITIES ============= */

    std::string Replace(std::string_view text, char replaced, char replacedWith)
    {
        std::string textData = text.data();

        /* Replace all occurences of replaced with replacedWith. */

        std::replace(textData.begin(), textData.end(), replaced, replacedWith);

        return textData;
    }

    /*
============= FILE UTILITIES ============= */

    std::string GetFileExtension(std::string_view path)
    {
        /* Find index of last dot in path, and return everything following that index. */

        return path.substr(path.find_last_of('.') + 1).data();
    }

    std::string GetFileNameNoExtension(std::string_view path)
    {
        /* Find index of last slash and get the filename following that slash. */

        auto nameWithExtension = std::string(path.substr(path.find_last_of('/') + 1));

        /* Find the index of the last dot in the above string, and return everything preceeding that dot. */

        return nameWithExtension.substr(0, nameWithExtension.find_last_of('.'));
    }

    /*
============= MOUSE UTILITIES ============= */

    PointF GetMousePosition()
    {
        /* To hold the mouse position coordinates in pixels. */

        int xPx;
        int yPx;

        /* Get mouse position in pixels from SDL. */

        SDL_GetMouseState(&xPx, &yPx);

        auto canvasSize = GetCanvasSize();

        /* Divide the pixel values with the canvas size to get the "fractional" values as floats. */

        auto x = static_cast<float>(xPx) / canvasSize.w;
        auto y = static_cast<float>(yPx) / canvasSize.h;

        return { x, y };
    }

    /*
============= CANVAS UTILITIES ============= */

    Size GetCanvasSize()
    {
        /* To hold the canvas size in pixels. */

        Size canvasSize;

        /* Get the dimensions from SDL. */

        SDL_GetWindowSize(_<SDLDevice>().GetWindow().get(), &canvasSize.w, &canvasSize.h);

        return canvasSize;
    }

    float GetAspectRatio()
    {
        auto canvasSize = GetCanvasSize();

        /* Aspect ratio is obtained as: width / height. */

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
