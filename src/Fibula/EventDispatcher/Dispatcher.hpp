#ifndef FIBULA_DISPATCHER_HPP
#define FIBULA_DISPATCHER_HPP

#include <map>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include <Fibula/EventDispatcher/Event.hpp>

namespace Fibula {
    namespace EventDispatcher {
        template<class EventType>
        class ListenerInterface;

        typedef std::vector<std::shared_ptr<ListenerInterface<Event>>> ListenerVector;
        typedef std::map<std::string, ListenerVector> ListenerMap;
    }
}

#include <Fibula/EventDispatcher/Event.hpp>
#include <Fibula/EventDispatcher/ListenerInterface.hpp>
#include <Fibula/EventDispatcher/Payload.hpp>
#include <boost/shared_ptr.hpp>

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher {
        private:
            ListenerMap listeners;
        public:
            template<class ListenerType>
            void addListener(const std::string &eventName, ListenerType *listener);

            template<class EventType>
            void dispatchEvent(const std::string &eventName, const EventType &event) const;

            ~Dispatcher() { }

        private:
            ListenerMap::const_iterator searchListenersByPrefix(const std::string &prefix) const;
        };
    }
}

#endif //FIBULA_DISPATCHER_HPP
