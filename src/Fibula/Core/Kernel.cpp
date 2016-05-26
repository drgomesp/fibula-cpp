#include <stdexcept>
#include <Fibula/Core/Kernel.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEventListener.hpp>

using namespace Fibula::Core;
using namespace Fibula::Graphics;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Bridge::EventDispatcher;

Kernel::Kernel()
{
}

void Kernel::bootstrap()
{
    SDLEventListener *sdlEventListener = new SDLEventListener(this);
    this->dispatcher.addListener(sdlEventListener);

    Window *window = new Window("Fibula Engine :: v1.0.0", 640, 480, this->dispatcher);
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
    delete this->window;
    this->window = NULL;

    this->running = false;
}
