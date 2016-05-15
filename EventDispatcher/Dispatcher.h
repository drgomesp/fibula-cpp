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
            std::vector<Listener *> listeners;
        public:
            void addListener(Listener *listener);
            void dispatchEvent(Event *event);
        };
    }
}
