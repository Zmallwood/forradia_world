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
    * @class SettingsDevice
    * @brief Stores global settings and configuration values for the application.
    */
    class SettingsDevice
    {
      public:
        /**
        * @brief The number of grid rows used in the game world.
        */
        const int k_numGridRows { 15 };

        /**
        * @brief The size of the world area, defined in grid units.
        */
        const Size k_worldAreaSize { 100, 100 };
    };
}
