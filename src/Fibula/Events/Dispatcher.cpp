#include <Fibula/Events/Dispatcher.hpp>

#include <iostream>

using namespace Fibula::Events;

void Dispatcher::addListener(const std::string &eventName, std::shared_ptr<Listener> listener)
{
    listener->setDispatcher(this);
    ListenerVector registeredListeners;

    if (this->listeners.find(eventName) != this->listeners.end()) {
        registeredListeners = this->listeners.at(eventName);
    }

    registeredListeners.push_back(listener);
    std::pair<std::string, ListenerVector> pair(eventName, registeredListeners);
    this->listeners[eventName] = registeredListeners;
}

void Dispatcher::dispatchEvent(const std::string &eventName, std::shared_ptr<const Event> event) const
{
    for (auto item : listeners) {
        auto candidates = item.second;

        for (auto listener : candidates) {
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
