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

#include "ImageLoadDevice.hpp"

#include "SDLDevice.hpp"

namespace ForradiaWorld
{
    /*
CLASS: ImageLoadDevice */

    ImageLoadDevice::ImageLoadDevice()
    {
        LoadImages();
    }

    void ImageLoadDevice::LoadImages()
    {
        auto imagesPath = std::string(SDL_GetBasePath()) + k_relativeImagesPath.data();

        if (!std::filesystem::exists(imagesPath))
        {
            return;
        }

        for (auto it : std::filesystem::recursive_directory_iterator { imagesPath })
        {
            auto filePath { Replace(it.path().string(), '\\', '/') };

            if (GetFileExtension(filePath) == "png")
            {
                auto fileName = GetFileNameNoExtension(filePath);
                auto hash { Hash(fileName) };
                auto image { LoadSingleImage(filePath) };

                m_images.insert({ hash, image });
            }
        }
    }

    std::shared_ptr<SDL_Texture> ImageLoadDevice::LoadSingleImage(std::string_view path) const
    {
        auto surface { std::shared_ptr<SDL_Surface>(
            IMG_Load(path.data()),
            SDLDeleter()) };

        if (surface)
        {
            auto texture {
                std::shared_ptr<SDL_Texture>(
                    SDL_CreateTextureFromSurface(_<SDLDevice>().GetRenderer().get(), surface.get()),
                    SDLDeleter())
            };

            return texture;
        }

        return nullptr;
    }

    std::shared_ptr<SDL_Texture> ImageLoadDevice::GetImage(int imageNameHash) const
    {
        if (m_images.contains(imageNameHash))
        {
            return m_images.at(imageNameHash);
        }

        return nullptr;
    }

    Size ImageLoadDevice::GetImageSize(int imageNameHash) const
    {
        auto width { 0 };
        auto height { 0 };

        if (m_images.contains(imageNameHash))
        {
            SDL_QueryTexture(m_images.at(imageNameHash).get(), nullptr, nullptr, &width, &height);
        }

        return { width, height };
    }
}
