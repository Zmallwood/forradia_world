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
    * @class ImageDrawDevice
    * @brief Handles rendering images onto the screen.
    */
    class ImageDrawDevice
    {
      public:
        /**
        * @brief Draws an image using its hashed name.
        * @param imageNameHash The hash of the image name.
        * @param destination The destination rectangle in normalized coordinates (0.0 - 1.0).
        */
        void DrawImage(int imageNameHash, RectF destination) const;

        /**
        * @brief Draws an image using its string name.
        * @param imageName The name of the image.
        * @param destination The destination rectangle in normalized coordinates (0.0 - 1.0).
        */
        void DrawImage(std::string_view imageName, RectF destination) const;
    };
}
