#include "Dispatcher.h"

#include <iostream>

using namespace Fibula::EventDispatcher;

void Dispatcher::addListener(Listener *listener) {
    listeners.push_back(listener);
}

void Dispatcher::dispatchEvent(Event *event) {
    for (Listener *listener: listeners) {
        listener->handleEvent(event);
    }
}
