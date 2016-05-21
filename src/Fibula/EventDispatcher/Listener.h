#pragma once

#include "Event.h"
#include <iostream>

namespace Fibula {
    namespace EventDispatcher {
        class Listener {
        public:
            virtual void handleEvent(Event *event) = 0;
            virtual ~Listener() {};
        };
    }
}
