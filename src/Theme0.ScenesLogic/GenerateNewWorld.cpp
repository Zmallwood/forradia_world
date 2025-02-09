#include "GenerateNewWorld.hpp"
#include "ClearWithGrass.hpp"
#include "GenerateObjects.hpp"
#include "GenerateWater.hpp"

namespace FW {
void GenerateNewWorld()
{
    ClearWithGrass();
    GenerateWater();
    GenerateObjects();
}
}
