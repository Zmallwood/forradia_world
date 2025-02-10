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
 * @enum AnchorStyles
 * @brief Defines various anchor positions for UI elements.
 *
 * This enumeration specifies different anchor points that
 * can be used to align or position elements relative to
 * a container or reference point.
 */
    enum class AnchorStyles
    {
        /**
        * @brief Anchors to the top-left corner.
        */
        TopLeft,

        /**
        * @brief Anchors to the top-center position.
        */
        TopCenter,

        /**
        * @brief Anchors to the top-right corner.
        */
        TopRight,

        /**
        * @brief Anchors to the center-right position.
        */
        RightCenter,

        /**
        * @brief Anchors to the bottom-right corner.
        */
        BottomRight,

        /**
        * @brief Anchors to the bottom-center position.
        */
        BottomCenter,

        /**
        * @brief Anchors to the bottom-left corner.
        */
        BottomLeft,

        /**
        * @brief Anchors to the center-left position.
        */
        LeftCenter,

        /**
        * @brief Anchors to the absolute center.
        */
        Center
    };
}
