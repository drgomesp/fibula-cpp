#include "SDLEventListener.h"

using namespace Fibula::Bridge::EventDispatcher;

void SDLEventListener::handleEvent(Event *event)
{
    SDLEvent *sdlEvent = dynamic_cast<SDLEvent *>(event);

    if (sdlEvent) {
        if (sdlEvent->getType() == SDL_QUIT) {
            this->kernel->terminate();
        }
    }
}
