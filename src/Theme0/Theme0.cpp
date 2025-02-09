// Copyright 2025 Andreas Åkerberg

#include "Theme0.hpp"
#include "Theme0.Core.Devices/EngineDevice.hpp"

namespace ForradiaWorld
{
    void Theme0::Run()
    {
        /*\
Run engine instance.
*/
        _<EngineDevice>().Run();
    }
}
