#pragma once

#include <Fibula/Bridge/SFMLPayload.hpp>
#include <Fibula/Events/Event.hpp>

namespace Fibula {
    namespace Bridge {

        using Event = Fibula::Events::Event;

        class SFMLEvent : public Event
        {
        protected:
            const SFMLPayload &payload;
        public:
            SFMLEvent(const SFMLPayload &payload)
                : Event(payload),
                  payload(payload)
            { }

            const SFMLPayload &getPayload() const
            {
                return payload;
            }
        };
    }
}
