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
    * @class Point
    * @brief Represents a 2D point with integer coordinates.
    */
    class Point
    {
      public:
        /**
        * @brief Compares two points for equality.
        * @param other The other point to compare against.
        * @return True if both points have the same coordinates, false otherwise.
        */
        bool operator==(const Point& other) const
        {
            return x == other.x && y == other.y;
        }

        /** @brief The x-coordinate of the point. */
        int x { 0 };

        /** @brief The y-coordinate of the point. */
        int y { 0 };
    };

    /**
    * @class PointF
    * @brief Represents a 2D point with floating-point coordinates.
    */
    class PointF
    {
      public:
        /** @brief The x-coordinate of the point. */
        float x { 0.0f };

        /** @brief The y-coordinate of the point. */
        float y { 0.0f };
    };

    /**
    * @class RectF
    * @brief Represents a rectangle with floating-point dimensions.
    */
    class RectF
    {
      public:
        /** @brief The x-coordinate of the rectangle's top-left corner. */
        float x { 0.0f };

        /** @brief The y-coordinate of the rectangle's top-left corner. */
        float y { 0.0f };

        /** @brief The width of the rectangle. */
        float w { 0.0f };

        /** @brief The height of the rectangle. */
        float h { 0.0f };
    };

    /**
    * @class Size
    * @brief Represents a size with integer dimensions.
    */
    class Size
    {
      public:
        /** @brief The width of the size. */
        int w { 0 };

        /** @brief The height of the size. */
        int h { 0 };
    };

    /**
    * @class SizeF
    * @brief Represents a size with floating-point dimensions.
    */
    class SizeF
    {
      public:
        /** @brief The width of the size. */
        float w { 0.0f };

        /** @brief The height of the size. */
        float h { 0.0f };
    };
}
