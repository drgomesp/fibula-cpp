#include <stdexcept>
#include <Fibula/Core/Kernel.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEventListener.hpp>
#include <Fibula/Console/ConsoleListener.hpp>

using namespace Fibula::Core;
using namespace Fibula::Console;
using namespace Fibula::Graphics;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Bridge::EventDispatcher;

Kernel::Kernel()
{
}

void Kernel::bootstrap()
{
    boost::shared_ptr<SDLEventListener> sdlEventListener(new SDLEventListener(this));
    boost::shared_ptr<ConsoleListener> consoleListener(new ConsoleListener(this));

    this->dispatcher.addListener(sdlEventListener);
    this->dispatcher.addListener(consoleListener);

    boost::shared_ptr<Window> window(new Window("Fibula Engine :: v1.0.0", 1024, 768, this->dispatcher));
    this->window = window;

    this->booted = true;
}

void Kernel::run()
{
    this->bootstrap();

    if (!this->booted) {
        throw std::runtime_error("Failed to run engine because it was never booted");
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
