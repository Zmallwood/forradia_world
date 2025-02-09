// Copyright 2025 Andreas Åkerberg

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

        auto& GetCreaturesMirrorRef()
        {
            return m_creaturesMirror;
        }

      private:
        std::vector<std::vector<std::shared_ptr<Tile>>> m_tiles;
        std::map<std::shared_ptr<Creature>, Point> m_creaturesMirror;
    };
}
