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
    // =============================================
    // Singleton Pattern Utilities
    // =============================================

    /**
    * @brief Returns a singleton instance of a given type.
    * @tparam T The type of the instance.
    * @return A reference to the singleton instance.
    */
    template <class T>
    T& _()
    {
        static T instance;
        return instance;
    }

    // =============================================
    // Hashing Utilities
    // =============================================

    /**
    * @brief Computes a hash value from a given string.
    * @param text The input string to hash.
    * @return The computed hash value.
    */
    int Hash(std::string_view text);

    // =============================================
    // SDL Resource Management
    // =============================================

    /**
    * @class SDLDeleter
    * @brief A functor class for safely deleting SDL resources.
    *
    * This class provides custom deleter functions for various SDL types
    * to be used with smart pointers.
    */
    class SDLDeleter
    {
      public:
        /**
        * @brief Deletes an SDL window.
        * @param window Pointer to the SDL_Window to delete.
        */
        void operator()(SDL_Window* window) const;

        /**
        * @brief Deletes an SDL renderer.
        * @param renderer Pointer to the SDL_Renderer to delete.
        */
        void operator()(SDL_Renderer* renderer) const;

        /**
        * @brief Deletes an SDL surface.
        * @param surface Pointer to the SDL_Surface to delete.
        */
        void operator()(SDL_Surface* surface) const;

        /**
        * @brief Deletes an SDL texture.
        * @param texture Pointer to the SDL_Texture to delete.
        */
        void operator()(SDL_Texture* texture) const;

        /**
        * @brief Deletes an SDL font.
        * @param font Pointer to the TTF_Font to delete.
        */
        void operator()(TTF_Font* font) const;
    };

    // =============================================
    // String Manipulation Utilities
    // =============================================

    /**
    * @brief Replaces all occurrences of a character in a string.
    * @param text The input string.
    * @param replaced The character to be replaced.
    * @param replacedWith The character to replace with.
    * @return A new string with replaced characters.
    */
    std::string Replace(std::string_view text, char replaced, char replacedWith);

    /**
    * @brief Extracts the file extension from a file path.
    * @param path The file path.
    * @return The file extension as a string.
    */
    std::string GetFileExtension(std::string_view path);

    /**
    * @brief Extracts the file name without the extension from a file path.
    * @param path The file path.
    * @return The file name without its extension.
    */
    std::string GetFileNameNoExtension(std::string_view path);

    // =============================================
    // Input and Rendering Utilities
    // =============================================

    /**
    * @brief Gets the current mouse position.
    * @return The mouse position as a PointF.
    */
    PointF GetMousePosition();

    /**
    * @brief Gets the size of the rendering canvas.
    * @return The canvas size as a Size object.
    */
    Size GetCanvasSize();

    /**
    * @brief Calculates the aspect ratio of the canvas.
    * @return The aspect ratio as a float.
    */
    float GetAspectRatio();

    // =============================================
    // Aspect Ratio Conversions
    // =============================================

    /**
    * @brief Converts a width value to a corresponding height based on aspect ratio.
    * @param width The width value to convert.
    * @return The computed height.
    */
    float ConvertWidthToHeight(float width);

    /**
    * @brief Converts a height value to a corresponding width based on aspect ratio.
    * @param height The height value to convert.
    * @return The computed width.
    */
    float ConvertHeightToWidth(float height);
}
