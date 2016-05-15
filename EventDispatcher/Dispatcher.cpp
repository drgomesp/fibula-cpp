#include "Dispatcher.h"

#include <iostream>

using namespace Fibula::EventDispatcher;

void Dispatcher::addListener(Listener<Event, Payload> *listener) {
    listeners.push_back(listener);
}

void Dispatcher::dispatchEvent(Event<Payload> *event) {
    for (Listener<Event, Payload> *listener: listeners) {
        listener->handleEvent(event);
    }
}
