#include <iostream>
#include <Fibula/Console/ConsoleListener.hpp>
#include <Fibula/Graphics/Adapter/SDLWindowAdapter.hpp>
#include <Fibula/Graphics/Adapter/SFMLWindowAdapter.hpp>

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
    std::shared_ptr<ConsoleListener> consoleListener = std::make_shared<ConsoleListener>(this);
    this->dispatcher.addListener("event.console.*", consoleListener);

    std::shared_ptr<SDLWindowAdapter> window = std::make_shared<SDLWindowAdapter>(
        "Fibula Engine :: v1.0.0",
        1024,
        768,
        this->dispatcher,
        *this
    );

    std::cout << "Engine successfully started with adapter " << window->getName() << std::endl;

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
