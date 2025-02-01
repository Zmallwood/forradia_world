#include "UpdatePlayerMovement.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Core/Input/Keyboard/KeyboardInput.hpp"

namespace FW {
void UpdatePlayerMovement()
{
    auto upPressed = _<KeyboardInput>().KeyIsPressed(SDLK_UP);
    auto rightPressed = _<KeyboardInput>().KeyIsPressed(SDLK_RIGHT);
    auto downPressed = _<KeyboardInput>().KeyIsPressed(SDLK_DOWN);
    auto leftPressed = _<KeyboardInput>().KeyIsPressed(SDLK_LEFT);

    auto now = SDL_GetTicks();

    if (now > _<Player>().GetTicksLastMovement() + 1000 / _<Player>().GetMovementSpeed()
        && (upPressed || rightPressed || downPressed || leftPressed)) {
        if (upPressed) {
            _<Player>().MoveUp();
        }

        if (rightPressed) {
            _<Player>().MoveRight();
        }

        if (downPressed) {
            _<Player>().MoveDown();
        }

        if (leftPressed) {
            _<Player>().MoveLeft();
        }

        _<Player>().SetTicksLastMovement(now);
    }
}
}
