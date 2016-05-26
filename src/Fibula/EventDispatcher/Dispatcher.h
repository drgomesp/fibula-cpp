#pragma once

#include <vector>
#include <boost/ptr_container/ptr_vector.hpp>

#include <Fibula/EventDispatcher/Event.h>
#include <Fibula/EventDispatcher/Listener.h>
#include <Fibula/EventDispatcher/Payload.h>

using namespace std;

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher
        {
        private:
            vector<Listener *> listeners;
        public:
            Dispatcher() : listeners(0) { }
            void addListener(Listener *listener);
            void dispatchEvent(Event *event);
            ~Dispatcher() {}
        private:
            size_t getListenerMemorySize(Listener listener) const;
        };
    }
}
