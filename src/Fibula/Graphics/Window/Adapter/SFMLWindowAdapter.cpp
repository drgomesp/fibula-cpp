#include "SFMLWindowAdapter.hpp"

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

using namespace Fibula::Core;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Graphics::Window::Adapter;

SFMLWindowAdapter::SFMLWindowAdapter(
    const std::string &title,
    const unsigned int width,
    const unsigned int height,
    EventDispatcher::Dispatcher &dispatcher,
    Kernel &kernel
) : WindowAdapter("Graphics::Adapter::SFML", title, width, height, dispatcher, kernel)
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(this->width, this->height),
        this->title
    );

    this->window = window;
}

void SFMLWindowAdapter::handleEvents()
{
    sf::Event event;

    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->kernel.terminate();
        }
    }

    this->window->display();
}

void SFMLWindowAdapter::render()
{

}

SFMLWindowAdapter::~SFMLWindowAdapter()
{

}
