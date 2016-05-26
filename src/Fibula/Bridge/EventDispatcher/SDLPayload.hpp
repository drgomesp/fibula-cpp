#ifndef FIBULA_SDLPAYLOAD_HPP
#define FIBULA_SDLPAYLOAD_HPP

#include <Fibula/EventDispatcher/Payload.hpp>
#include <SDL_events.h>

namespace Fibula {
    namespace Bridge {
        namespace EventDispatcher {
            class SDLPayload : public Fibula::EventDispatcher::Payload
            {
                const SDL_Event &originalEvent;
            public:
                SDLPayload(const SDL_Event &originalEvent) : originalEvent(originalEvent)
                { }

                const SDL_Event &getOriginalEvent() const
                {
                    return originalEvent;
                }

                virtual ~SDLPayload()
                { }
            };
        }
    }
}


#endif //FIBULA_SDLPAYLOAD_HPP
