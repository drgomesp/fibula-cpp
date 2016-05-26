#ifndef FIBULA_SDLEVENT_H
#define FIBULA_SDLEVENT_H

#include <Fibula/EventDispatcher/Event.h>
#include <SDL2/SDL_events.h>

namespace Fibula {
    namespace Bridge {
        namespace EventDispatcher {
            class SDLEvent : public Fibula::EventDispatcher::Event
            {
            private:
                Uint32 type;
            public:
                SDLEvent(const string &name, Uint32 type) : Event(name, nullptr), type(type)
                { }

                Uint32 getType() const
                {
                    return this->type;
                }

                virtual ~SDLEvent()
                { }
            };
        }
    }
}

#endif //FIBULA_SDLEVENT_H
