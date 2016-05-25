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
            boost::ptr_vector<boost::shared_ptr<Listener>> listeners;
        public:
            Dispatcher() : listeners(0) { }
            void addListener(boost::shared_ptr<Listener> listener);
            void dispatchEvent(boost::shared_ptr<Event> event);
            ~Dispatcher() {}
        private:
            size_t getListenerMemorySize(Listener listener) const;
        };
    }
}
