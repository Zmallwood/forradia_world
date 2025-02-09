#include "UpdatePlayerKBMovement.hpp"
#include "Theme0.Core.Devices/PlayerDevice.hpp"
#include "Theme0.Core.Devices/KeyboardInputDevice.hpp"

namespace FW {
void UpdatePlayerKBMovement()
{
    auto upPressed = _<KeyboardInputDevice>().KeyIsPressed(SDLK_UP);
    auto rightPressed = _<KeyboardInputDevice>().KeyIsPressed(SDLK_RIGHT);
    auto downPressed = _<KeyboardInputDevice>().KeyIsPressed(SDLK_DOWN);
    auto leftPressed = _<KeyboardInputDevice>().KeyIsPressed(SDLK_LEFT);

    auto now = SDL_GetTicks();

    if (now > _<PlayerDevice>().GetTicksLastMovement() + 1000 / _<PlayerDevice>().GetMovementSpeed()
        && (upPressed || rightPressed || downPressed || leftPressed)) {

        if (upPressed) {
            _<PlayerDevice>().MoveUp();
        }

        if (rightPressed) {
            _<PlayerDevice>().MoveRight();
        }

        if (downPressed) {
            _<PlayerDevice>().MoveDown();
        }

        if (leftPressed) {
            _<PlayerDevice>().MoveLeft();
        }

        _<PlayerDevice>().SetTicksLastMovement(now);
    }
}
}
