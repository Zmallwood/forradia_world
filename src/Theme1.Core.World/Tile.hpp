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
    class Creature;

    class Tile
    {
      public:
        auto GetGround() const
        {
            return m_ground;
        }
        void SetGround(std::string_view groundName)
        {
            m_ground = Hash(groundName);
        }
        auto GetObject() const
        {
            return m_object;
        }
        void SetObject(std::string_view objectName)
        {
            m_object = Hash(objectName);
        }
        auto GetCreature() const
        {
            return m_creature;
        }
        void SetCreature(std::shared_ptr<Creature> value)
        {
            m_creature = value;
        }

      private:
        int m_ground { 0 };
        int m_object { 0 };
        std::shared_ptr<Creature> m_creature;
    };
}
