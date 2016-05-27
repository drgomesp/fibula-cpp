#include "MousePositionListener.hpp"

using namespace Game::Listeners::SDL;

LISTENER_RESPONSE MousePositionListener::handleEvent(
    std::shared_ptr<const Fibula::EventDispatcher::Event> event) const
{
    const Fibula::Bridge::EventDispatcher::SDLEvent *sdlEvent
        = dynamic_cast<const Fibula::Bridge::EventDispatcher::SDLEvent *>(event.get());

    const Fibula::Bridge::EventDispatcher::SDLPayload sdlPayload = sdlEvent->getPayload();

    switch (sdlPayload.getOriginalEvent().type) {
        default:
        case SDL_MOUSEMOTION:
            SDL_MouseMotionEvent m = sdlPayload.getOriginalEvent().motion;
            std::cout << "[MousePositionListener::handleEvent] -> Mouse position is [x:" << m.x << "][y:" << m.y << "]" << std::endl;
            return LISTENER_RESPONSE::SUCCESS;
    }
}
