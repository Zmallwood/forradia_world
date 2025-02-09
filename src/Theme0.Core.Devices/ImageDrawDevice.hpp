// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{
    class ImageDrawDevice
    {
      public:
        void DrawImage(int imageNameHash, RectF destination) const;
        void DrawImage(std::string_view imageName, RectF destination) const;
    };
}
