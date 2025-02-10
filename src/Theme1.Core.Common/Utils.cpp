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
    // =============================================
    // Hashing Utilities
    // =============================================

    int Hash(std::string_view text)
    {
        unsigned long hash { 5381 }; // Initialize hash to a prime value.

        // Iterate through each character of the input string.
        for (size_t i { 0 }; i < text.size(); ++i)
        {
            // Update the hash using a common hash function (djb2).
            hash = 33 * hash + (unsigned char)text[i];
        }

        // Return the computed hash as an integer.
        return static_cast<int>(hash);
    }

    // =============================================
    // SDL Resource Management
    // =============================================

    void SDLDeleter::operator()(SDL_Window* window) const
    {
        SDL_DestroyWindow(window); // Free the SDL_Window object.
    }

    void SDLDeleter::operator()(SDL_Renderer* renderer) const
    {
        SDL_DestroyRenderer(renderer); // Free the SDL_Renderer object.
    }

    void SDLDeleter::operator()(SDL_Surface* surface) const
    {
        SDL_FreeSurface(surface); // Free the SDL_Surface object.
    }

    void SDLDeleter::operator()(SDL_Texture* texture) const
    {
        SDL_DestroyTexture(texture); // Free the SDL_Texture object.
    }

    void SDLDeleter::operator()(TTF_Font* font) const
    {
        TTF_CloseFont(font); // Close the TTF_Font object.
    }

    // =============================================
    // String Manipulation Utilities
    // =============================================

    std::string Replace(std::string_view text, char replaced, char replacedWith)
    {
        std::string textData = text.data(); // Convert input to string.

        // Replace all occurrences of 'replaced' with 'replacedWith' in the string.
        std::replace(textData.begin(), textData.end(), replaced, replacedWith);

        return textData; // Return the modified string.
    }

    std::string GetFileExtension(std::string_view path)
    {
        // Extract the substring starting from the last dot (file extension).
        return path.substr(path.find_last_of('.') + 1).data();
    }

    std::string GetFileNameNoExtension(std::string_view path)
    {
        // Get the substring of the file name (without path).
        auto nameWithExtension = std::string(path.substr(path.find_last_of('/') + 1));

        // Return the file name without its extension by slicing before the last dot.
        return nameWithExtension.substr(0, nameWithExtension.find_last_of('.'));
    }

    // =============================================
    // Input and Rendering Utilities
    // =============================================

    PointF GetMousePosition()
    {
        int xPx, yPx;

        SDL_GetMouseState(&xPx, &yPx); // Get mouse position in pixels.

        auto canvasSize = GetCanvasSize(); // Get the canvas size.

        // Calculate the relative mouse position as a fraction of the canvas size.
        auto x = static_cast<float>(xPx) / canvasSize.w;
        auto y = static_cast<float>(yPx) / canvasSize.h;

        return { x, y }; // Return mouse position as a PointF (relative to canvas).
    }

    Size GetCanvasSize()
    {
        Size canvasSize;

        // Get the size of the window (canvas).
        SDL_GetWindowSize(_<SDLDevice>().GetWindow().get(), &canvasSize.w, &canvasSize.h);

        return canvasSize; // Return the canvas size.
    }

    float GetAspectRatio()
    {
        auto canvasSize = GetCanvasSize(); // Get the canvas size.

        // Calculate and return the aspect ratio (width / height).
        return static_cast<float>(canvasSize.w) / canvasSize.h;
    }

    // =============================================
    // Aspect Ratio Conversions
    // =============================================

    float ConvertWidthToHeight(float width)
    {
        // Convert width to height using the aspect ratio.
        return width * GetAspectRatio();
    }

    float ConvertHeightToWidth(float height)
    {
        // Convert height to width using the aspect ratio.
        return height / GetAspectRatio();
    }
}
