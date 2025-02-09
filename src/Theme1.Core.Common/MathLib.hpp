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
