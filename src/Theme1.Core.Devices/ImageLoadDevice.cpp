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
    ImageLoadDevice::ImageLoadDevice()
    {
        LoadImages(); // Load all images upon initialization
    }

    void ImageLoadDevice::LoadImages()
    {
        // Construct the full path to the images directory
        auto imagesPath = std::string(SDL_GetBasePath()) + k_relativeImagesPath.data();

        // Check if the directory exists before proceeding
        if (!std::filesystem::exists(imagesPath))
        {
            return;
        }

        // Iterate through all files in the directory recursively
        for (auto it : std::filesystem::recursive_directory_iterator { imagesPath })
        {
            auto filePath { Replace(it.path().string(), '\\', '/') }; // Normalize file path

            // Only process PNG files
            if (GetFileExtension(filePath) == "png")
            {
                auto fileName = GetFileNameNoExtension(filePath);
                auto hash { Hash(fileName) }; // Generate a hash for the filename
                auto image { LoadSingleImage(filePath) }; // Load the image

                // Store the loaded image in the map with its hash as the key
                m_images.insert({ hash, image });
            }
        }
    }

    std::shared_ptr<SDL_Texture> ImageLoadDevice::LoadSingleImage(std::string_view path) const
    {
        // Load image into an SDL_Surface
        auto surface { std::shared_ptr<SDL_Surface>(
            IMG_Load(path.data()),
            SDLDeleter()) };

        if (surface)
        {
            // Convert SDL_Surface to SDL_Texture
            auto texture {
                std::shared_ptr<SDL_Texture>(
                    SDL_CreateTextureFromSurface(_<SDLDevice>().GetRenderer().get(), surface.get()),
                    SDLDeleter())
            };

            return texture; // Return the loaded texture
        }

        return nullptr; // Return nullptr if loading failed
    }

    std::shared_ptr<SDL_Texture> ImageLoadDevice::GetImage(int imageNameHash) const
    {
        // Check if the requested image exists in the map
        if (m_images.contains(imageNameHash))
        {
            return m_images.at(imageNameHash);
        }

        return nullptr; // Return nullptr if image is not found
    }

    Size ImageLoadDevice::GetImageSize(int imageNameHash) const
    {
        auto width { 0 };
        auto height { 0 };

        // Retrieve image dimensions if the texture exists
        if (m_images.contains(imageNameHash))
        {
            SDL_QueryTexture(m_images.at(imageNameHash).get(), nullptr, nullptr, &width, &height);
        }

        return { width, height }; // Return the width and height of the image
    }

}
