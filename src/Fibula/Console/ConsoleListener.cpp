#include <iostream>
#include <atomic>
#include <thread>
#include <Fibula/Console/ConsoleListener.hpp>

using namespace Fibula::Console;

LISTENER_RESPONSE ConsoleListener::handleEvent(boost::shared_ptr<Fibula::EventDispatcher::Event> event)
{
    return LISTENER_RESPONSE::SUCCESS;
}
