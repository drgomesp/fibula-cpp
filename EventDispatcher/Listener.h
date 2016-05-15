#pragma once

#include "Event.h"
#include <iostream>

namespace Fibula {
    namespace EventDispatcher {
        class Listener {
        public:
            virtual const void handleEvent(Event *event) = 0;
            virtual ~Listener() {};
        };
    }
}
