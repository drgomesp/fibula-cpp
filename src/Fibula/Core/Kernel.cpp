#include "Kernel.h"

#include <boost/shared_ptr.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEventListener.h>

using namespace Fibula::Core;
using namespace Fibula::Graphics;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Bridge::EventDispatcher;

class FakeListener : public Listener
{
public:
    FakeListener()
    { }
};

Kernel::Kernel()
{
    this->bootstrap();
}

void Kernel::bootstrap()
{
    try {
        boost::shared_ptr<Dispatcher> eventDispatcher(new Dispatcher);
        this->eventDispatcher = boost::get_pointer(eventDispatcher);

        boost::shared_ptr<SDLEventListener> sdlEventListener(new SDLEventListener(this));
        this->eventDispatcher->addListener(boost::get_pointer(sdlEventListener));
    } catch (exception const &e) {
        this->booted = false;
        throw e;
    }

    try {
        boost::shared_ptr<Window> window(new Window("Fibula Engine :: v1.0.0", 640, 480, this->eventDispatcher));
        this->window = boost::get_pointer(window);
    } catch (exception const &e) {
        this->booted = false;
        throw e;
    }

    this->booted = true;
}

void Kernel::run()
{
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
