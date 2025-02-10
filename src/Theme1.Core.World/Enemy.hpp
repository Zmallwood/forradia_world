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

#include "Creature.hpp"

namespace ForradiaWorld
{
    /**
    * @class Enemy
    * @brief Represents an enemy in the game.
    *
    * The Enemy class is derived from the Creature class and inherits its attributes and methods.
    * It can be further extended to include specific behaviors or properties unique to enemies.
    */
    class Enemy : public Creature
    {
      public:
        /**
        * @brief Constructs an Enemy object using the Creature constructor.
        * @param creatureName The name of the enemy creature.
        */
        using Creature::Creature;
    };

}
