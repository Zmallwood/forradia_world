#pragma once

namespace FW {
class Player {
public:
    auto GetPosition() const
    {
        return m_position;
    }

private:
    Point m_position { 50, 50 };
};
}
