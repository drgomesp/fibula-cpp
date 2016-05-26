#ifndef FIBULA_CONSOLEEVENT_HPP
#define FIBULA_CONSOLEEVENT_HPP

#include <Fibula/EventDispatcher/Event.hpp>

namespace Fibula {
    namespace Console {
        class ConsoleEvent : public EventDispatcher::Event
        {
        public:
            ConsoleEvent(const std::string &name, const EventDispatcher::Payload &payload) : Event(name, payload)
            { }
        };
    }
}

#endif //FIBULA_CONSOLEEVENT_HPP
