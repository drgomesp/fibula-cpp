#include <Fibula/Bridge/EventDispatcher/SDLEventListener.hpp>

using namespace Fibula::EventDispatcher;
using namespace Fibula::Bridge::EventDispatcher;

LISTENER_RESPONSE SDLEventListener::handleEvent(SDLEvent *event) const {
    switch (event->getPayload().getOriginalEvent().type) {
        case SDL_QUIT:
            this->kernel->terminate();
            return LISTENER_RESPONSE::SUCCESS;
        case SDL_KEYUP:
            if (event->getPayload().getOriginalEvent().key.keysym.sym == SDLK_ESCAPE) {
                this->kernel->terminate();
                return LISTENER_RESPONSE::SUCCESS;
            }
        default:
            return LISTENER_RESPONSE::FAILURE;
    }
}


