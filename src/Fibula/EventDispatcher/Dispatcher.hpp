#ifndef FIBULA_DISPATCHER_HPP
#define FIBULA_DISPATCHER_HPP

#include <vector>
#include <boost/ptr_container/ptr_vector.hpp>

#include <Fibula/EventDispatcher/Event.hpp>
#include <Fibula/EventDispatcher/Listener.hpp>
#include <Fibula/EventDispatcher/Payload.hpp>

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher
        {
        private:
            std::vector<Listener *> listeners;
        public:
            Dispatcher() : listeners(0) { }
            void addListener(Listener *listener);
            void dispatchEvent(Event *event) const;
            ~Dispatcher();
        private:
            size_t getListenerMemorySize(Listener listener) const;
        };
    }
}

#endif //FIBULA_DISPATCHER_HPP
