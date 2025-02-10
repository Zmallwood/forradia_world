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
    * @brief Updates the movement of all animals in the world.
    *
    * This function iterates over all the creatures in the world, checks if they are animals,
    * and moves them randomly within the bounds of the world. The movement is performed based
    * on the animal's movement speed and a time threshold to control movement frequency. The
    * animal's position is updated in the creatures mirror reference, and the last movement
    * timestamp is updated.
    */
    void UpdateAnimalsMovement();
}
