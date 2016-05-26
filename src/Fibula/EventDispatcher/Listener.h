#pragma once

#include <boost/shared_ptr.hpp>
#include "Event.h"

enum LISTENER_RESPONSE
{
    SUCCESS = 0, FAILURE = 1
};

namespace Fibula {
    namespace EventDispatcher {
        class Listener
        {
        public:
            virtual LISTENER_RESPONSE handleEvent(Event *event) = 0;

            virtual ~Listener()
            { }
        };
    }
}
