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
        typedef std::vector<boost::shared_ptr<Listener>> ListenerVector;
        typedef std::map<std::string, ListenerVector> ListenerMap;

        class Dispatcher
        {
        private:
             ListenerMap listeners;
        public:
            void addListener(const std::string &eventName, boost::shared_ptr<Listener> listener);
            void dispatchEvent(const std::string &eventName, boost::shared_ptr<Event> event) const;
            ~Dispatcher() { }
        private:
            size_t getListenerMemorySize(Listener listener) const;
            ListenerMap::const_iterator searchListenersByPrefix(const std::string &prefix) const;
            bool canHandleEvent(const std::string &eventName) const;
        };
    }
}

#endif //FIBULA_DISPATCHER_HPP
