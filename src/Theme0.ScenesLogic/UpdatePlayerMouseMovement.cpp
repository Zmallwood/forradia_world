#include "UpdatePlayerMouseMovement.hpp"
#include "Theme0.Core.Assist/MouseButton.hpp"
#include "Theme0.Core.Devices/MouseInputDevice.hpp"
#include "Theme0.Core.Devices/PlayerDevice.hpp"
#include "TileHovering.hpp"

namespace FW {
void UpdatePlayerMouseMovement()
{
    auto now = SDL_GetTicks();

    auto leftMouseFired = _<MouseInputDevice>().GetLeftButton()->GetBeenFiredPickResult();
    auto hoveredTile = _<TileHovering>().GetHoveredTile();

    if (leftMouseFired) {
        _<PlayerDevice>().SetDestination(hoveredTile);
    }

    auto destination = _<PlayerDevice>().GetDestination();
    auto playerPos = _<PlayerDevice>().GetPosition();

    if (destination.x == playerPos.x && destination.y == playerPos.y) {
        _<PlayerDevice>().SetDestination({ -1, -1 });
        return;
    }

    if (now > _<PlayerDevice>().GetTicksLastMovement() + 1000 / _<PlayerDevice>().GetMovementSpeed()
        && destination.x != -1 && destination.y != -1) {

        auto dx = destination.x - playerPos.x;
        auto dy = destination.y - playerPos.y;

        if (dx < 0) {
            _<PlayerDevice>().MoveLeft();
        } else if (dx > 0) {
            _<PlayerDevice>().MoveRight();
        }

        if (dy < 0) {
            _<PlayerDevice>().MoveUp();
        } else if (dy > 0) {
            _<PlayerDevice>().MoveDown();
        }

        _<PlayerDevice>().SetTicksLastMovement(now);
    }
}
}
