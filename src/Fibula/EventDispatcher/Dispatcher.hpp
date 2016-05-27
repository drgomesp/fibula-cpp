#ifndef FIBULA_DISPATCHER_HPP
#define FIBULA_DISPATCHER_HPP

#include <map>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

namespace Fibula {
    namespace EventDispatcher {
        class ListenerInterface;
        typedef std::vector<boost::shared_ptr<ListenerInterface>> ListenerVector;
        typedef std::map<std::string, ListenerVector> ListenerMap;
    }
}

#include <Fibula/EventDispatcher/Event.hpp>
#include <Fibula/EventDispatcher/ListenerInterface.hpp>
#include <Fibula/EventDispatcher/Payload.hpp>
#include <boost/shared_ptr.hpp>

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher
        {
        private:
             ListenerMap listeners;
        public:
            void addListener(const std::string &eventName, boost::shared_ptr<ListenerInterface> listener);
            void dispatchEvent(const std::string &eventName, boost::shared_ptr<const Event> event) const;
            ~Dispatcher() { }
        private:
            ListenerMap::const_iterator searchListenersByPrefix(const std::string &prefix) const;
        };
    }
}

#endif //FIBULA_DISPATCHER_HPP
