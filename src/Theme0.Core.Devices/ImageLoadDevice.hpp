// Copyright 2025 Andreas Åkerberg

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
