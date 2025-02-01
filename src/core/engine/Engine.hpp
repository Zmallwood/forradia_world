#pragma once

namespace FW {
class Engine {
public:
    void Run();

    void SetRunning(bool value)
    {
        m_running = value;
    }

private:
    bool m_running { true };
};
}
