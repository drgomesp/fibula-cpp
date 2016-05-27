#include <iostream>
#include <atomic>
#include <thread>
#include <Fibula/Console/ConsoleListener.hpp>

using namespace Fibula::Console;
using namespace Fibula::EventDispatcher;

LISTENER_RESPONSE ConsoleListener::handleEvent(std::shared_ptr<const Event> event) const
{
    return LISTENER_RESPONSE::SUCCESS;
}
