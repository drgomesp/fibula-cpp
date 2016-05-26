#include "Dispatcher.h"
#include <iostream>

using namespace Fibula::EventDispatcher;

void Dispatcher::addListener(Listener *listener)
{
    this->listeners.reserve(this->getListenerMemorySize(*listener));
    this->listeners.push_back(listener);
}

void Dispatcher::dispatchEvent(Event *event)
{
    std::cout << "Dispatching event " << event->getName() << std::endl;

    for (Listener *listener: this->listeners) {
        LISTENER_RESPONSE response = listener->handleEvent(event);
    }
}

size_t Dispatcher::getListenerMemorySize(Listener listener) const
{
    return sizeof(listener) + this->listeners.size();
}
