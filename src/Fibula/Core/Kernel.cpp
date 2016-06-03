#include <iostream>

#include <Fibula/Graphics/Window/Adapter/SFMLWindowAdapter.hpp>

using namespace Fibula::Core;
using namespace Fibula::Graphics::Window;
using namespace Fibula::Graphics::Window::Adapter;
using namespace Fibula::EventDispatcher;

void Kernel::addListener(const std::string &eventName, std::shared_ptr<ListenerInterface> listener)
{
    this->dispatcher.addListener(eventName, listener);
}

void Kernel::bootstrap()
{
    std::shared_ptr<WindowAdapter> window = std::make_shared<SFMLWindowAdapter>(
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
        this->window->render();
        this->window->handleEvents();
    }
}

void Kernel::terminate()
{
    this->running = false;
}
