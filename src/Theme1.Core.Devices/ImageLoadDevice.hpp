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
    * @class ImageLoadDevice
    * @brief Handles loading and managing images in the application.
    */
    class ImageLoadDevice
    {
      public:
        /**
        * @brief Constructs the ImageLoadDevice and loads all images.
        */
        ImageLoadDevice();

        /**
        * @brief Retrieves a loaded image texture.
        * @param imageNameHash The hashed name of the image.
        * @return A shared pointer to the SDL_Texture if found, otherwise nullptr.
        */
        std::shared_ptr<SDL_Texture> GetImage(int imageNameHash) const;

        /**
        * @brief Gets the size of a loaded image.
        * @param imageNameHash The hashed name of the image.
        * @return The dimensions of the image as a Size structure.
        */
        Size GetImageSize(int imageNameHash) const;

      private:
        /**
        * @brief Loads all images from the specified resource directory.
        */
        void LoadImages();

        /**
        * @brief Loads a single image from the given file path.
        * @param path The file path of the image.
        * @return A shared pointer to the loaded SDL_Texture.
        */
        std::shared_ptr<SDL_Texture> LoadSingleImage(std::string_view path) const;

        /// The relative path to the images directory.
        inline static const std::string k_relativeImagesPath { "../resources/Images/" };

        /// A map storing loaded images, keyed by their hashed names.
        std::map<int, std::shared_ptr<SDL_Texture>> m_images;
    };
}
