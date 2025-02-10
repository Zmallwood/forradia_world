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

#include "ImageDrawDevice.hpp"

#include "ImageLoadDevice.hpp"

#include "SDLDevice.hpp"

namespace ForradiaWorld
{
    /*
CLASS: ImageDrawDevice */

    void ImageDrawDevice::DrawImage(int imageNameHash, RectF destination) const
    {
        auto image = _<ImageLoadDevice>().GetImage(imageNameHash);

        auto canvasSize = GetCanvasSize();

        auto xPx = static_cast<int>(destination.x * canvasSize.w);
        auto yPx = static_cast<int>(destination.y * canvasSize.h);

        auto widthPx = static_cast<int>(destination.w * canvasSize.w);
        auto heightPx = static_cast<int>(destination.h * canvasSize.h);

        SDL_Rect sdlRectangle { xPx, yPx, widthPx, heightPx };

        SDL_RenderCopy(_<SDLDevice>().GetRenderer().get(), image.get(), nullptr, &sdlRectangle);
    }

    void ImageDrawDevice::DrawImage(std::string_view imageName, RectF destination) const
    {
        DrawImage(Hash(imageName), destination);
    }
}
