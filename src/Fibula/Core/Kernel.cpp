#include <Fibula/Core/Kernel.hpp>

#include <SFML/System/Clock.hpp>

using namespace Fibula::Core;
using namespace Fibula::Events;

void Kernel::bootstrap()
{
    this->dispatcher = make_shared<Dispatcher>();
    this->window = make_shared<Window>(1280, 768, "Fibula :: SFML", *this->dispatcher);

    if (NULL == this->window) {
        throw runtime_error("Failed to create window");
    }

    printf("Engine successfully started\n");

    this->window->setUp(this);
    this->booted = true;
}

void Kernel::registerListeners()
{ }

void Kernel::run()
{
    this->bootstrap();
    this->registerListeners();

    this->running = true;

    sf::Clock clock;

    while (this->running && this->window->isOpen()) {
        sf::Time elapsed = clock.restart();

        this->handleEvents();
        this->handleInputs();
        this->update();
        this->window->draw();
    }

    this->terminate();
}

void Kernel::terminate()
{
    this->running = false;
    this->window->close();
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
