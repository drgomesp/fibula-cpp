#include "SDLEventListener.h"

using namespace Fibula::Bridge::EventDispatcher;

void SDLEventListener::handleEvent(boost::shared_ptr<Event> event)
{
    SDLEvent *sdlEvent = dynamic_cast<SDLEvent *>(event.get());

    if (sdlEvent->getType() == SDL_QUIT) {
        this->kernel->terminate();
    }
}
