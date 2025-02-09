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
        TTF_Init();

        AddFontSize(FontSizes::_12);
    }

    void TextDrawDevice::AddFontSize(FontSizes fontSize)
    {
        auto fontSizeN = static_cast<int>(fontSize);

        auto fontPath = std::string(SDL_GetBasePath()) + k_defaultFontPath;

        auto fontPathUnixStyle = Replace(fontPath, '\\', '/');

        std::cout << fontPathUnixStyle << std::endl;

        auto newFont = std::shared_ptr<TTF_Font>(TTF_OpenFont(fontPathUnixStyle.c_str(), fontSizeN), SDLDeleter());

        if (!newFont)
        {
            std::cout << "Error loading font.\n";
        }

        m_fonts.insert({ fontSize, newFont });
    }

    void TextDrawDevice::DrawString(
        std::string_view text,
        float x,
        float y,
        AnchorStyles anchorStyle,
        FontSizes fontSize) const
    {
        auto font = m_fonts.at(fontSize).get();
        auto renderer = _<SDLDevice>().GetRenderer().get();

        SDL_Color white = { 255, 255, 255 };

        SDL_Surface* surface = TTF_RenderText_Solid(font, text.data(), white);

        int textWidth;
        int textHeight;

        auto textSize = TTF_SizeText(font, text.data(), &textWidth, &textHeight);

        SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surface);

        auto canvasSize = GetCanvasSize();

        SDL_Rect rect;

        rect.x = static_cast<int>(x * canvasSize.w);
        rect.y = static_cast<int>(y * canvasSize.h);

        rect.w = textWidth;
        rect.h = textHeight;

        switch (anchorStyle)
        {
        case AnchorStyles::TopLeft:

            break;

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

        SDL_RenderCopy(renderer, message, nullptr, &rect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(message);
    }
}
