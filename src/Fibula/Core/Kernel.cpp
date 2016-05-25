#include "Kernel.h"

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEventListener.h>

using namespace Fibula::Core;
using namespace Fibula::Graphics;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Bridge::EventDispatcher;

class SimpleListener : public Listener
{
public:
    virtual void handleEvent(boost::shared_ptr<Event> event) override
    {
        std::cout << "SimpleListener::handleEvent()" << std::endl;
    }

    ~SimpleListener()
    {}
};

Kernel::Kernel()
{
}

void Kernel::bootstrap()
{
    boost::shared_ptr<Dispatcher> eventDispatcher(new Dispatcher);
    boost::shared_ptr<SimpleListener> sdlEventListener(new SimpleListener);

    eventDispatcher->addListener(sdlEventListener);
    this->eventDispatcher = eventDispatcher;

    boost::shared_ptr<Window> window(new Window("Fibula Engine :: v1.0.0", 640, 480, eventDispatcher));
    this->window = window;

    this->booted = true;
}

void Kernel::run()
{
    this->bootstrap();

    if (!this->booted) {
        throw runtime_error("Failed to run engine because it was never booted");
    }

    this->running = true;

    while (this->running) {
        this->window->handleEvents();
    }
}

void Kernel::terminate()
{
    this->running = false;
}
