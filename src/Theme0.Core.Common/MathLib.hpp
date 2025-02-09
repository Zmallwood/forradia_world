// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{

    class Point
    {
      public:
        int x { 0 };
        int y { 0 };
    };

    class PointF
    {
      public:
        float x { 0.0f };
        float y { 0.0f };
    };

    class RectF
    {
      public:
        float x { 0.0f };
        float y { 0.0f };
        float w { 0.0f };
        float h { 0.0f };
    };

    class Size
    {
      public:
        int w { 0 };
        int h { 0 };
    };

    class SizeF
    {
      public:
        float w { 0.0f };
        float h { 0.0f };
    };

}
