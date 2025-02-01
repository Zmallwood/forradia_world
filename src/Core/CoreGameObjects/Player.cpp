#include "Player.hpp"

namespace FW {
void Player::MoveUp()
{
    m_position.y--;
}

void Player::MoveRight()
{
    m_position.x++;
}

void Player::MoveLeft()
{
    m_position.x--;
}

void Player::MoveDown()
{
    m_position.y++;
}
}
