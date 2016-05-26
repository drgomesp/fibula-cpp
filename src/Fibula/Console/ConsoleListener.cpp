#include <iostream>
#include <atomic>
#include <thread>
#include <Fibula/Console/ConsoleListener.hpp>

using namespace Fibula::Console;

LISTENER_RESPONSE ConsoleListener::handleEvent(boost::shared_ptr<const Fibula::EventDispatcher::Event> event) const
{
    return LISTENER_RESPONSE::SUCCESS;
}
