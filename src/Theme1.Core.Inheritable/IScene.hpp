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
    * @class IScene
    * @brief Base class for all scenes in the application.
    */
    class IScene
    {
      public:
        /**
        * @brief Updates the scene logic.
        * Calls the derived class's implementation of UpdateDerived().
        */
        void Update();

        /**
        * @brief Renders the scene content.
        * Calls the derived class's implementation of RenderDerived().
        */
        void Render() const;

      protected:
        /**
        * @brief Virtual method for updating the scene logic.
        * Can be overridden by derived classes to implement custom behavior.
        */
        virtual void UpdateDerived() { }

        /**
        * @brief Virtual method for rendering the scene content.
        * Can be overridden by derived classes to implement custom rendering.
        */
        virtual void RenderDerived() const { }
    };

}
