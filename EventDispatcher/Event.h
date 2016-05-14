#pragma once

namespace Fibula {
    namespace EventDispatcher {
        template<class PayloadType>
        class Event {
        protected:
            PayloadType payload;
        public:
            Event(PayloadType &payload) : payload(payload) { }
            PayloadType getPayload() { return payload; }
            virtual ~Event() {}
        };
    }
}

