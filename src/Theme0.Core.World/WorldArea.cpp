// Copyright 2025 Andreas Åkerberg

#include "WorldArea.hpp"
#include "Tile.hpp"

namespace ForradiaWorld
{
    WorldArea::WorldArea()
    {
        for (auto x = 0; x < 100; x++)
        {
            m_tiles.push_back(std::vector<std::shared_ptr<Tile>>());
            for (auto y = 0; y < 100; y++)
            {
                m_tiles.at(x).push_back(std::make_shared<Tile>());
            }
        }
    }

    std::shared_ptr<Tile> WorldArea::GetTile(int x, int y) const
    {
        return m_tiles.at(x).at(y);
    }
}
