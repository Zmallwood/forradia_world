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
    /*
2D point with coordinates of ints. */

    class Point
    {
      public:
        bool operator==(const Point& other) const
        {
            return x == other.x && y == other.y;
        }

        int x { 0 };
        int y { 0 };
    };

    /*
2D point with coordinates of floats. */

    class PointF
    {
      public:
        float x { 0.0f };
        float y { 0.0f };
    };

    /*
2D rectangle with coordinates and size of floats. */

    class RectF
    {
      public:
        float x { 0.0f };
        float y { 0.0f };
        float w { 0.0f };
        float h { 0.0f };
    };

    /*
2D size with size of ints. */

    class Size
    {
      public:
        int w { 0 };
        int h { 0 };
    };

    /*
2D size with size of floats. */

    class SizeF
    {
      public:
        float w { 0.0f };
        float h { 0.0f };
    };
}
