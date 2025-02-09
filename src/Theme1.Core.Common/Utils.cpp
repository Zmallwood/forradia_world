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

    std::string Replace(std::string_view text, char replaced, char replacedWith)
    {
        std::string textData = text.data();
        std::replace(textData.begin(), textData.end(), replaced, replacedWith);

        return textData;
    }

    std::string GetFileExtension(std::string_view path)
    {
        return path.substr(path.find_last_of('.') + 1).data();
    }

    std::string GetFileNameNoExtension(std::string_view path)
    {
        auto nameWithExtension = std::string(path.substr(path.find_last_of('/') + 1));

        return nameWithExtension.substr(0, nameWithExtension.find_last_of('.'));
    }

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
