#include <Fibula/Console/ConsoleListener.hpp>
#include <Fibula/Graphics/Adapter/SDLWindowAdapter.hpp>
#include <boost/make_shared.hpp>

using namespace Fibula::Core;
using namespace Fibula::Console;
using namespace Fibula::Graphics;
using namespace Fibula::Graphics::Adapter;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Bridge::EventDispatcher;

Kernel::Kernel()
{
}

void Kernel::bootstrap()
{
    boost::shared_ptr<ConsoleListener> consoleListener(new ConsoleListener(this));
    this->dispatcher.addListener("event.console.*", consoleListener);

    boost::shared_ptr<WindowAdapterInterface> window(new SDLWindowAdapter(
            "Fibula Engine :: v1.0.0",
            1024,
            768,
            this->dispatcher,
            this
    ));

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

boost::shared_ptr<Kernel> Kernel::getShared()
{
    return this->shared_from_this();
}

