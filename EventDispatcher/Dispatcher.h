#pragma once

#include <vector>
#include <boost/variant.hpp>

#include "Event.h"
#include "Listener.h"
#include "Payload.h"

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher {
        protected:
            std::vector<boost::variant<Listener<Event, Payload> *>> listeners;
        public:
            void addListener(Listener<Event, Payload> *listener);
            void dispatchEvent(const Event<Payload> &event);
        };
    }
}
