#include "GenerateObjects.hpp"
#include "Theme0.Core.World/Tile.hpp"
#include "Theme0.Core.World/World.hpp"
#include "Theme0.Core.World/WorldArea.hpp"

namespace FW {
void GenerateObjects()
{
    auto worldArea = _<World>().GetCurrentWorldArea();

    auto numTree1s = 100 + rand() % 20;

    for (auto i = 0; i < numTree1s; i++) {
        auto x = rand() % 100;
        auto y = rand() % 100;

        auto tile = worldArea->GetTile(x, y);
        tile->SetObject("ObjectTree1");
    }
}
}
