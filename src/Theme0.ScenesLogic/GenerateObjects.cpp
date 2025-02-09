#include "GenerateObjects.hpp"
#include "Theme0.Core.World/Tile.hpp"
#include "Theme0.Core.World/World.hpp"
#include "Theme0.Core.World/WorldArea.hpp"

namespace FW {
void GenerateObjects()
{
    auto worldArea = _<World>().GetCurrentWorldArea();

    auto numTree1s = 200;

    for (auto i = 0; i < numTree1s; i++) {
        auto x = rand() % 100;
        auto y = rand() % 100;

        auto tile = worldArea->GetTile(x, y);
        if (tile->GetGround() != Hash("GroundWater")) {
            tile->SetObject("ObjectTree1");
        }
    }

    auto numTree2s = 200;

    for (auto i = 0; i < numTree2s; i++) {
        auto x = rand() % 100;
        auto y = rand() % 100;

        auto tile = worldArea->GetTile(x, y);
        if (tile->GetGround() != Hash("GroundWater")) {
            tile->SetObject("ObjectTree2");
        }
    }
}
}
