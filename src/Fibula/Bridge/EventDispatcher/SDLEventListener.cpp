#include "SDLEventListener.h"
#include <iostream>

using namespace Fibula::Bridge::EventDispatcher;

LISTENER_RESPONSE SDLEventListener::handleEvent(Event *event)
{
    SDLEvent *sdlEvent = dynamic_cast<SDLEvent *>(event);

    if (sdlEvent->getType() == SDL_QUIT) {
        this->kernel->terminate();
        return LISTENER_RESPONSE::SUCCESS;
    }

    return LISTENER_RESPONSE::FAILURE;
}

SDLEventListener::~SDLEventListener()
{
    delete this->kernel;
    this->kernel = NULL;
}
