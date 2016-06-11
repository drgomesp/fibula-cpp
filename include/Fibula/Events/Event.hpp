#pragma once

#include <string>

#include <Fibula/Events/Payload.hpp>

namespace Fibula {
    namespace Events {
        class Event
        {
        protected:
            const Payload &payload;
        public:
            Event(const Payload &payload) : payload(payload)
            { }

            virtual const Payload &getPayload() const
            {
                return payload;
            }

            virtual ~Event()
            { }
        };
    }
}
