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
    enum class FontSizes
    {
        _12 = 12
    };

    class TextDrawDevice
    {
      public:
        TextDrawDevice();

        void DrawString(
            std::string_view text,
            float x,
            float y,
            AnchorStyles anchorStyle = AnchorStyles::TopLeft,
            FontSizes fontSize = FontSizes::_12) const;

      private:
        void AddFontSize(FontSizes fontSize);

        const std::string k_defaultFontPath { "../resources/Fonts/PixeloidSans.ttf" };

        std::map<FontSizes, std::shared_ptr<TTF_Font>> m_fonts;
    };
}
