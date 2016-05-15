#pragma once

#include "Payload.h"

namespace Fibula {
    namespace EventDispatcher {
        class Event {
        protected:
            Payload payload;
        public:
            Event(Payload &payload) : payload(payload) { }
            Payload getPayload() { return payload; }
            virtual ~Event() {}
        };
    }
}

