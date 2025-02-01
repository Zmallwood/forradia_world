#include "PollEvents.hpp"
#include "Core/Input/Keyboard/KeyboardInput.hpp"
#include "Engine.hpp"

namespace FW {
void PollEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            _<Engine>().SetRunning(false);
            break;
        case SDL_KEYDOWN:
            _<KeyboardInput>().RegisterKeyPress(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            _<KeyboardInput>().RegisterKeyRelease(event.key.keysym.sym);
            break;
        case SDL_MOUSEBUTTONDOWN:
            //    _<MouseInput>().RegisterMouseDown(event.button.button);
            break;
        case SDL_MOUSEBUTTONUP:
            //    _<MouseInput>().RegisterMouseUp(event.button.button);
            break;
        }
    }
}
}
