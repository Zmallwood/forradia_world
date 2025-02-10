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
    * @brief Generates a new world with various elements such as ground types, lakes, trees, flowers, boulders, and creatures.
    *
    * This function is responsible for creating the environment of the world by:
    * - Setting the ground for all tiles (e.g., grass or water).
    * - Generating random lakes, trees, flowers, and boulders.
    * - Spawning creatures like white rabbits and enemies at valid coordinates.
    * - Creating a fenced area with a claim flag at a specified location.
    *
    * The world is generated based on random values for lakes, creatures, and objects, providing a unique world layout each time it's called.
    */
    void GenerateNewWorld();
}
