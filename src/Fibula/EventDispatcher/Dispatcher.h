#pragma once

#include <vector>

#include <Fibula/EventDispatcher/Event.h>
#include <Fibula/EventDispatcher/Listener.h>
#include <Fibula/EventDispatcher/Payload.h>

using namespace std;

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher {
        protected:
            vector<Listener *> listeners;
        public:
            void addListener(Listener *listener);
            void dispatchEvent(Event *event);
        };
    }
}
