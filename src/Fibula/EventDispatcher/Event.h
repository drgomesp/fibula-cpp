#pragma once

#include <string>
#include "Payload.h"

namespace Fibula {
    namespace EventDispatcher {
        class Event
        {
        protected:
            const std::string &name;
            Payload *payload;
        public:
            Event(const std::string &name, Payload *payload) : name(name), payload(payload)
            { }

            Payload* getPayload()
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
