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
    class ImageLoadDevice
    {
      public:
        ImageLoadDevice();

        std::shared_ptr<SDL_Texture> GetImage(int imageNameHash) const;

        Size GetImageSize(int imageNameHash) const;

      private:
        void LoadImages();

        std::shared_ptr<SDL_Texture> LoadSingleImage(std::string_view path) const;

        inline static const std::string k_relativeImagesPath { "../resources/Images/" };

        std::map<int, std::shared_ptr<SDL_Texture>> m_images;
    };
}
