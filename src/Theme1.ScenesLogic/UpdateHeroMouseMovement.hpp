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
    * @brief Updates the hero's movement based on mouse input.
    *
    * This function handles the movement of the hero when the left mouse button is clicked.
    * It checks if the left mouse button has been clicked and updates the hero's destination
    * to the hovered tile. It then moves the hero towards the destination if needed,
    * ensuring the hero moves at the correct speed based on the time interval.
    *
    * It handles both horizontal and vertical movement to reach the destination.
    * The movement is processed only after the specified movement time interval has passed.
    */
    void UpdateHeroMouseMovement();
}
