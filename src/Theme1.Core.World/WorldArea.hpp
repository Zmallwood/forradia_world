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
    class Tile;
    class Creature;

    class WorldArea
    {
      public:
        WorldArea();

        std::shared_ptr<Tile> GetTile(int x, int y) const;

        Size GetSize() const;

        bool IsValidCoordinate(int x, int y) const;

        auto& GetCreaturesMirrorRef()
        {
            return m_creaturesMirror;
        }

      private:
        std::vector<std::vector<std::shared_ptr<Tile>>> m_tiles;
        std::map<std::shared_ptr<Creature>, Point> m_creaturesMirror;
    };
}
