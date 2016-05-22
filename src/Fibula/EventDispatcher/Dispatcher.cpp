#include "Dispatcher.h"

using namespace Fibula::EventDispatcher;

void Dispatcher::addListener(Listener *listener)
{
    this->listeners.push_back(listener);
}

void Dispatcher::dispatchEvent(Event *event)
{
//    for (Listener *listener : this->listeners) {
//        listener->handleEvent(event);
//    }
}
