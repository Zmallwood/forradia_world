#pragma once

namespace FW {
class PlayerDevice {
public:
    void MoveUp();
    void MoveRight();
    void MoveDown();
    void MoveLeft();

    auto GetPosition() const
    {
        return m_position;
    }

    auto GetTicksLastMovement() const
    {
        return m_ticksLastMovement;
    }

    void SetTicksLastMovement(int value)
    {
        m_ticksLastMovement = value;
    }

    auto GetMovementSpeed() const
    {
        return m_movementSpeed;
    }

private:
    Point m_position { 50, 50 };
    int m_ticksLastMovement { 0 };
    float m_movementSpeed { 3.0f };
};
}
