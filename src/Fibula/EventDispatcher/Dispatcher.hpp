#ifndef FIBULA_DISPATCHER_HPP
#define FIBULA_DISPATCHER_HPP

#include <map>
#include <string>
#include <boost/ptr_container/ptr_vector.hpp>

#include <Fibula/EventDispatcher/Event.hpp>
#include <Fibula/EventDispatcher/Listener.hpp>
#include <Fibula/EventDispatcher/Payload.hpp>
#include <boost/shared_ptr.hpp>

namespace Fibula {
    namespace EventDispatcher {
        typedef std::vector<boost::shared_ptr<const Listener>> ListenerVector;
        typedef std::map<std::string, ListenerVector> ListenerMap;

        class Dispatcher
        {
        private:
             ListenerMap listeners;
        public:
            void addListener(const std::string &eventName, boost::shared_ptr<const Listener> listener);
            void dispatchEvent(const std::string &eventName, boost::shared_ptr<const Event> event) const;
            ~Dispatcher() { }
        private:
            ListenerMap::const_iterator searchListenersByPrefix(const std::string &prefix) const;
        };
    }
}

#endif //FIBULA_DISPATCHER_HPP
