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
    * @class EngineDevice
    * @brief Manages the main game loop and event handling.
    *
    * This class is responsible for running the main game loop, polling events,
    * updating scenes, rendering the game, and handling user input. It manages
    * the lifecycle of the game and controls the flow of events within the application.
    */
    class EngineDevice
    {
      public:
        /**
        * @brief Starts and runs the game loop.
        *
        * The game loop repeatedly polls events, updates the game state,
        * renders the current scene, and displays the result. It continues
        * running until the game is no longer in a running state.
        */
        void Run();

      private:
        /**
        * @brief Polls events from the SDL event queue.
        *
        * This function processes all incoming events from the SDL event queue,
        * such as keyboard, mouse, and window events. Based on the event type,
        * appropriate actions are triggered.
        */
        void PollEvents();

        /**
        * @brief A boolean flag indicating whether the game is running.
        *
        * This flag is used to determine whether the game loop should continue running.
        * When set to `false`, the game loop exits and the game stops.
        */
        bool m_running { true };
    };
}
