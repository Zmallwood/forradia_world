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

#include "TextDrawDevice.hpp"
#include "SDLDevice.hpp"

namespace ForradiaWorld
{
    TextDrawDevice::TextDrawDevice()
    {
        TTF_Init(); // Initialize SDL_ttf for font rendering.

        AddFontSize(FontSizes::_12); // Load the default font size.
    }

    void TextDrawDevice::AddFontSize(FontSizes fontSize)
    {
        auto fontSizeN = static_cast<int>(fontSize);

        auto fontPath = std::string(SDL_GetBasePath()) + k_defaultFontPath; // Construct the font file path.

        auto fontPathUnixStyle = Replace(fontPath, '\\', '/'); // Ensure the path is in Unix format.

        // Load the font with the specified size.
        auto newFont = std::shared_ptr<TTF_Font>(TTF_OpenFont(fontPathUnixStyle.c_str(), fontSizeN), SDLDeleter());

        if (!newFont)
        {
            std::cout << "Error loading font.\n"; // Log an error if the font fails to load.

            return;
        }

        m_fonts.insert({ fontSize, newFont }); // Store the font in the map.
    }

    void TextDrawDevice::DrawString(
        std::string_view text,
        float x,
        float y,
        AnchorStyles anchorStyle,
        FontSizes fontSize) const
    {
        auto font = m_fonts.at(fontSize).get(); // Retrieve the font.
        auto renderer = _<SDLDevice>().GetRenderer().get(); // Get the SDL renderer.

        SDL_Color white = { 255, 255, 255 }; // Define white color for the text.

        SDL_Surface* surface = TTF_RenderText_Solid(font, text.data(), white); // Render text to a surface.

        int textWidth;
        int textHeight;

        TTF_SizeText(font, text.data(), &textWidth, &textHeight); // Get text dimensions.

        SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surface); // Convert surface to texture.

        auto canvasSize = GetCanvasSize(); // Get the canvas size for positioning.

        SDL_Rect rect;

        rect.x = static_cast<int>(x * canvasSize.w); // Convert normalized coordinates to pixels.
        rect.y = static_cast<int>(y * canvasSize.h);

        rect.w = textWidth; // Set the width of the text.
        rect.h = textHeight; // Set the height of the text.

        // Adjust text position based on the specified anchor style.
        switch (anchorStyle)
        {
        case AnchorStyles::TopLeft:
            break; // No adjustment needed.

        case AnchorStyles::TopCenter:
            rect.x -= rect.w / 2;
            break;

        case AnchorStyles::TopRight:
            rect.x -= rect.w;
            break;

        case AnchorStyles::RightCenter:
            rect.x -= rect.w;
            rect.y -= rect.h / 2;
            break;

        case AnchorStyles::BottomRight:
            rect.x -= rect.w;
            rect.y -= rect.h;
            break;

        case AnchorStyles::BottomCenter:
            rect.x -= rect.w / 2;
            rect.y -= rect.h;
            break;

        case AnchorStyles::BottomLeft:
            rect.y -= rect.h;
            break;

        case AnchorStyles::LeftCenter:
            rect.y -= rect.h / 2;
            break;

        case AnchorStyles::Center:
            rect.x -= rect.w / 2;
            rect.y -= rect.h / 2;
            break;
        }

        SDL_RenderCopy(renderer, message, nullptr, &rect); // Render the text texture to the screen.

        SDL_FreeSurface(surface); // Free the surface after use.
        SDL_DestroyTexture(message); // Destroy the texture to free memory.
    }
}
