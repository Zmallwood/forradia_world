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

#pragma once

namespace ForradiaWorld
{
    /*
============= GENERAL UTILS ============= */

    template <class T>
    T& _()
    {
        static T instance;

        return instance;
    }

    int Hash(std::string_view text);

    class SDLDeleter
    {
      public:
        void operator()(SDL_Window* window) const;

        void operator()(SDL_Renderer* renderer) const;

        void operator()(SDL_Surface* surface) const;

        void operator()(SDL_Texture* texture) const;

        void operator()(TTF_Font* font) const;
    };

    /*
============= STRING UTILS ============= */

    std::string Replace(std::string_view text, char replaced, char replacedWith);

    /*
============= FILE UTILS ============= */

    std::string GetFileExtension(std::string_view path);

    std::string GetFileNameNoExtension(std::string_view path);

    /*
============= MOUSE UTILS ============= */

    PointF GetMousePosition();

    /*
============= CANVAS UTILS ============= */

    Size GetCanvasSize();

    float GetAspectRatio();

    float ConvertWidthToHeight(float width);

    float ConvertHeightToWidth(float height);
}
