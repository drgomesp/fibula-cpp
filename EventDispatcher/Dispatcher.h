#pragma once

#include <vector>
#include <boost/shared_ptr.hpp>

#include "Event.h"
#include "Listener.h"
#include "Payload.h"

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher {
        protected:
            std::vector<Listener<Event, Payload> *> listeners;
        public:
            void addListener(Listener<Event, Payload> *listener);
            void dispatchEvent(Event<Payload> *event);
        };
    }
}
