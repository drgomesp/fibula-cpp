#include <Fibula/Core/Kernel.hpp>

using namespace Fibula::Core;
using namespace Fibula::Events;

void Kernel::bootstrap()
{
    this->dispatcher = make_shared<Dispatcher>();

    this->window = make_shared<Window>(800, 600, "Fibula :: SFML", *this->dispatcher);

    if (NULL == this->window) {
        throw runtime_error("Failed to create window");
    }

    printf("Engine successfully started :: Fibula v1.0.0\n");

    this->booted = true;
}

void Kernel::registerListeners()
{

}

void Kernel::run()
{
    this->bootstrap();
    this->registerListeners();

    this->running = true;

    while (this->running && this->window->isOpen()) {
        this->handleEvents();
        this->handleInputs();
        this->window->draw();
        this->update();
    }

    this->terminate();
}

void Kernel::terminate()
{
    this->running = false;
}

void Kernel::handleEvents()
{
    this->window->handleEvents();
}

void Kernel::handleInputs()
{
    this->window->handleInputs();
}

void Kernel::update()
{
    this->window->update();
}
