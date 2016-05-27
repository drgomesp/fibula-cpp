#include <Fibula/EventDispatcher/Dispatcher.hpp>
#include <boost/regex.h>

#include <iostream>

using namespace Fibula::EventDispatcher;

void Dispatcher::addListener(const std::string &eventName, std::shared_ptr<ListenerInterface> listener)
{
    listener->setDispatcher(this);
    ListenerVector registeredListeners;

    if (this->listeners.find(eventName) != this->listeners.end()) {
        registeredListeners = this->listeners.at(eventName);
    }

    registeredListeners.push_back(listener);
    std::pair<std::string, ListenerVector> pair(eventName, registeredListeners);
    this->listeners.insert(pair);
}

void Dispatcher::dispatchEvent(const std::string &eventName, const Event &event) const
{
    ListenerMap::const_iterator it = this->searchListenersByPrefix(eventName);

    for (it; it != this->listeners.end(); ++it) {
        ListenerVector candidates = it->second;

        for (std::shared_ptr<const ListenerInterface> listener: candidates) {
            LISTENER_RESPONSE response = listener->handleEvent(event);
        }
    }
}

ListenerMap::const_iterator Dispatcher::searchListenersByPrefix(const std::string &prefix) const
{
    ListenerMap::const_iterator it = this->listeners.lower_bound(prefix);

    if (it != this->listeners.end()) {
        const std::string &key = it->first;

        if (key.compare(0, prefix.size(), prefix) == 0) {
            return it;
        }
    }

    return this->listeners.end();
}
