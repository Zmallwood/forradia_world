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
    void ImageDrawDevice::DrawImage(int imageNameHash, RectF destination) const
    {
        // Retrieve the image using its hashed name
        auto image = _<ImageLoadDevice>().GetImage(imageNameHash);

        // Get the size of the rendering canvas
        auto canvasSize = GetCanvasSize();

        // Convert normalized coordinates (0.0 - 1.0) to pixel values
        auto xPx = static_cast<int>(destination.x * canvasSize.w);
        auto yPx = static_cast<int>(destination.y * canvasSize.h);

        auto widthPx = static_cast<int>(destination.w * canvasSize.w);
        auto heightPx = static_cast<int>(destination.h * canvasSize.h);

        // Create an SDL rectangle with the computed pixel dimensions
        SDL_Rect sdlRectangle { xPx, yPx, widthPx, heightPx };

        // Render the image onto the canvas
        SDL_RenderCopy(_<SDLDevice>().GetRenderer().get(), image.get(), nullptr, &sdlRectangle);
    }

    void ImageDrawDevice::DrawImage(std::string_view imageName, RectF destination) const
    {
        // Hash the image name and delegate to the hashed version of DrawImage
        DrawImage(Hash(imageName), destination);
    }

}
