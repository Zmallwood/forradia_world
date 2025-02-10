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
    /**
    * @enum FontSizes
    * @brief Defines available font sizes.
    */
    enum class FontSizes
    {
        _12 = 12 ///< Font size of 12 pixels.
    };

    /**
    * @class TextDrawDevice
    * @brief Handles text rendering using SDL_ttf.
    */
    class TextDrawDevice
    {
      public:
        /**
        * @brief Constructs the TextDrawDevice and initializes SDL_ttf.
        */
        TextDrawDevice();

        /**
        * @brief Draws a string on the screen at the specified position.
        *
        * @param text The text to be rendered.
        * @param x X-coordinate (normalized from 0.0 to 1.0).
        * @param y Y-coordinate (normalized from 0.0 to 1.0).
        * @param anchorStyle The alignment of the text relative to the given coordinates.
        * @param fontSize The size of the font to use.
        */
        void DrawString(
            std::string_view text,
            float x,
            float y,
            AnchorStyles anchorStyle = AnchorStyles::TopLeft,
            FontSizes fontSize = FontSizes::_12) const;

      private:
        /**
        * @brief Loads a font of the specified size.
        *
        * @param fontSize The font size to load.
        */
        void AddFontSize(FontSizes fontSize);

        const std::string k_defaultFontPath { "../resources/Fonts/PixeloidSans.ttf" }; ///< Default font file path.

        std::map<FontSizes, std::shared_ptr<TTF_Font>> m_fonts; ///< Stores loaded fonts mapped by size.
    };
}
