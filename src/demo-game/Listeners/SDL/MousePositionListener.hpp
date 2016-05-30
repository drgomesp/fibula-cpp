#ifndef FIBULA_MOUSEPOSITIONLISTENER_HPP
#define FIBULA_MOUSEPOSITIONLISTENER_HPP

#include <iostream>

#include <SDL2/SDL_events.h>
#include <Fibula/Bridge/EventDispatcher/SDLEventListener.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEvent.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLPayload.hpp>

namespace Game {
    namespace Listeners {
        namespace SDL {
            class MousePositionListener : public Fibula::Bridge::EventDispatcher::SDLEventListener
            {
            public:
                MousePositionListener(Fibula::Core::Kernel *kernel) : SDLEventListener(kernel)
                { }

                ~MousePositionListener()
                { }
            };
        }
    }
}

#endif //FIBULA_MOUSEPOSITIONLISTENER_HPP
