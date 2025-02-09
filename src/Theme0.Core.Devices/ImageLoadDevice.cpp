// Copyright 2025 Andreas Åkerberg

#include "ImageLoadDevice.hpp"
#include "Theme0.Core.Devices/SDLDevice.hpp"

namespace ForradiaWorld
{
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
