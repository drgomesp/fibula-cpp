#include "Dispatcher.h"

#include <iostream>

using namespace Fibula::EventDispatcher;

void Dispatcher::addListener(Listener<Event, Payload> *listener) {
    listeners.push_back((listener));
}

void Dispatcher::dispatchEvent(const Event<Payload> &event) {
    for (boost::variant<Listener<Event, Payload> *> variant : listeners) {
        Listener<Event, Payload> *listener = boost::get<Listener<Event, Payload> *>(variant);
        listener->handleEvent(event);
    }
}
