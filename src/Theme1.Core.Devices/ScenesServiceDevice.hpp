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

#include "Theme1.Scenes/SceneNames.hpp"

namespace ForradiaWorld
{
    class IScene;

    /**
    * @class ScenesServiceDevice
    * @brief Manages scene transitions and updates in the application.
    *
    * This class is responsible for handling the different scenes within the application.
    * It allows switching between scenes, updating the current scene, and rendering it.
    */
    class ScenesServiceDevice
    {
      public:
        /**
        * @brief Constructs the ScenesServiceDevice and initializes scenes.
        */
        ScenesServiceDevice();

        /**
        * @brief Updates the currently active scene.
        *
        * This function calls the `Update` method of the currently active scene.
        */
        void UpdateCurrentScene();

        /**
        * @brief Renders the currently active scene.
        *
        * This function calls the `Render` method of the currently active scene.
        */
        void RenderCurrentScene() const;

        /**
        * @brief Switches to a different scene.
        * @param sceneName The name of the scene to switch to.
        *
        * This function changes the active scene to the one specified by `sceneName`.
        */
        void GoToScene(SceneNames sceneName);

      private:
        /**
        * @brief Adds a scene to the scene manager.
        * @param sceneName The name of the scene.
        * @param scene Reference to the scene instance.
        *
        * This function registers a new scene in the scene manager.
        */
        void AddScene(SceneNames sceneName, IScene& scene);

        /// Stores the scenes mapped by their names.
        std::map<SceneNames, IScene&> m_scenes;

        /// Stores the currently active scene.
        SceneNames m_currentScene { 0 };
    };
}
