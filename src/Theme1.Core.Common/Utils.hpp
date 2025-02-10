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

    /*
Singleton helper function. */

    template <class T>
    T& _()
    {
        static T instance;

        return instance;
    }

    /*
Primary used hash function.. */

    int Hash(std::string_view text);

    /*
Helper class to properly cleanup smart pointers of SDL objects. */

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

    /*
Replace all occurrences of a character with another character in a string. */

    std::string Replace(std::string_view text, char replaced, char replacedWith);

    /*
============= FILE UTILS ============= */

    /*
Get file extension from a file path. */

    std::string GetFileExtension(std::string_view path);

    /*
Get filename without extension for a file path. */

    std::string GetFileNameNoExtension(std::string_view path);

    /*
============= MOUSE UTILS ============= */

    /*
Get mouse position, where coordinates range from 0.0 - 1.0. */

    PointF GetMousePosition();

    /*
============= CANVAS UTILS ============= */

    /*
Get canvas size in pixels. */

    Size GetCanvasSize();

    /*
Get current aspect ratio for game window. */

    float GetAspectRatio();

    /*
Convert a float represented width to corresponding height. */

    float ConvertWidthToHeight(float width);

    /*
Convert a float represented height to corresponding width. */

    float ConvertHeightToWidth(float height);
}
