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
     * @class WorldViewService
     * @brief A service class responsible for rendering the view of the game world.
     *
     * The WorldViewService handles the rendering of the world, including tiles, objects, creatures, and the hero.
     * It calculates the appropriate positions based on the hero's current position and ensures the world is displayed
     * from the player's perspective. The class uses grid and tile sizes to draw the world in a dynamic and interactive way.
     *
     * Additionally, it manages special rendering effects like visibility (line of sight), hovered tiles, and water tile animations.
     */
    class WorldViewService
    {
      public:
        /**
         * @brief Renders the world view based on the current game state.
         *
         * This function draws the world, including the terrain, objects, creatures, and the hero's position. It calculates
         * the rendering positions relative to the hero's position and the grid layout. The function also checks the line
         * of sight for tiles and ensures that objects, creatures, and the hero are rendered correctly in the game world.
         */
        void Render() const;
    };

}
