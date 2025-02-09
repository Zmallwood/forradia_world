#pragma once

namespace ForradiaWorld
{
    class TileHovering
    {
      public:
        void Update();

        auto GetHoveredTile() const
        {
            return m_hoveredTile;
        }

      private:
        Point m_hoveredTile { -1, -1 };
    };
}
