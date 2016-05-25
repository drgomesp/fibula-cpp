#ifndef FIBULA_SDLEVENT_H
#define FIBULA_SDLEVENT_H

#include <Fibula/EventDispatcher/Event.h>
#include <SDL2/SDL_events.h>

using namespace Fibula::EventDispatcher;

namespace Fibula {
    namespace Bridge {
        namespace EventDispatcher {
            class SDLEvent : public Event
            {
            private:
                Uint32 type;
            public:
                SDLEvent(Uint32 type) : type(type)
                {}

                Uint32 getType() const
                {
                    return this->type;
                }
            };
        }
    }
}

#endif //FIBULA_SDLEVENT_H
