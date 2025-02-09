#pragma once

namespace ForradiaWorld
{
    class EngineDevice
    {
      public:
        void Run();

      private:
        void Randomize() const;
        void PollEvents();

        bool m_running { true };
    };
}
