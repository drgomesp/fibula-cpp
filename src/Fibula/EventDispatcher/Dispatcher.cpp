#include <Fibula/EventDispatcher/Dispatcher.hpp>
#include <iostream>

using namespace Fibula::EventDispatcher;

void Dispatcher::addListener(boost::shared_ptr<Listener> listener)
{
    this->listeners.reserve(this->getListenerMemorySize(*listener.get()));
    this->listeners.push_back(listener);
}

void Dispatcher::dispatchEvent(boost::shared_ptr<Event> event) const
{
    for (boost::shared_ptr<Listener> listener: this->listeners) {
        LISTENER_RESPONSE response = listener->handleEvent(event);
    }
}

size_t Dispatcher::getListenerMemorySize(Listener listener) const
{
    return sizeof(listener) + this->listeners.size();
}
