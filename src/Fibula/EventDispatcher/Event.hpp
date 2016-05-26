#ifndef FIBULA_EVENT_HPP
#define FIBULA_EVENT_HPP

#include <string>
#include <Fibula/EventDispatcher/Payload.hpp>

namespace Fibula {
    namespace EventDispatcher {
        class Event
        {
        protected:
            const std::string &name;
            const Payload &payload;
        public:
            Event(const std::string &name, const Payload &payload) : name(name), payload(payload)
            { }

            virtual const Payload &getPayload() const
            {
                return payload;
            }

            const std::string &getName() const
            {
                return name;
            }

            virtual ~Event()
            { }
        };
    }
}

#endif //FIBULA_EVENT_HPP
