// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{
    class Tile;

    class WorldArea
    {
      public:
        WorldArea();

        std::shared_ptr<Tile> GetTile(int x, int y) const;

      private:
        std::vector<std::vector<std::shared_ptr<Tile>>> m_tiles;
    };
}
