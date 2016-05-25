#include "Dispatcher.h"
#include <boost/foreach.hpp>

using namespace Fibula::EventDispatcher;

void Dispatcher::addListener(boost::shared_ptr<Listener> listener)
{
    this->listeners.reserve(this->getListenerMemorySize(*listener));
    this->listeners.push_back(&listener);
}

void Dispatcher::dispatchEvent(boost::shared_ptr<Event> event)
{
    for (boost::shared_ptr<Listener> listener : this->listeners) {
        listener->handleEvent(event);
    }
}

size_t Dispatcher::getListenerMemorySize(Listener listener) const
{
    return sizeof(listener) + this->listeners.size();
}
