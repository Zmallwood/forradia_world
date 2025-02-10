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
    * @enum SceneNames
    * @brief Defines the different scene types in the game.
    *
    * This enum contains the names of the scenes used within the game. Each value represents
    * a unique scene that can be used in scene management and transition.
    */
    enum class SceneNames
    {
        /**
        * @brief The introductory scene.
        */
        Intro,

        /**
        * @brief The main menu scene where the player can start the game, view settings, etc.
        */
        MainMenu,

        /**
        * @brief The scene used for world generation, where the game world is prepared or loaded.
        */
        WorldGeneration,

        /**
        * @brief The main gameplay scene where the core interaction occurs.
        */
        Main
    };
}
