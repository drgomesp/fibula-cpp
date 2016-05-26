#ifndef FIBULA_SDLEVENT_H
#define FIBULA_SDLEVENT_H

#include <Fibula/Bridge/EventDispatcher/SDLPayload.hpp>
#include <Fibula/EventDispatcher/Event.hpp>

namespace Fibula {
    namespace Bridge {
        namespace EventDispatcher {
            class SDLEvent : public Fibula::EventDispatcher::Event
            {
            private:
                const SDLPayload &payload;
            public:
                SDLEvent(const std::string &name, const SDLPayload &payload)
                        : Event(name, payload), payload(payload)
                { }

                const SDLPayload &getPayload() const
                {
                    return payload;
                }

                virtual ~SDLEvent()
                { }
            };
        }
    }
}

#endif //FIBULA_SDLEVENT_H
