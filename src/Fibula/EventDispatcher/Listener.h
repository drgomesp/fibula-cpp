#pragma once

#include <boost/shared_ptr.hpp>
#include "Event.h"

namespace Fibula {
    namespace EventDispatcher {
        class Listener {
        public:
            virtual void handleEvent(boost::shared_ptr<Event> event) = 0;
            virtual ~Listener() {};
        };
    }
}
