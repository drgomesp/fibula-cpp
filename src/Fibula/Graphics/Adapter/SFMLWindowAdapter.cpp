#include <Fibula/Graphics/Adapter/SFMLWindowAdapter.hpp>

using namespace Fibula::Graphics::Adapter;

SFMLWindowAdapter::SFMLWindowAdapter(
        const std::string &title,
        const unsigned int width,
        const unsigned int height,
        EventDispatcher::Dispatcher &dispatcher,
        Core::Kernel &kernel
) : WindowAdapterInterface("Graphics::Adapter::SFML", title, width, height, dispatcher, kernel)
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

SFMLWindowAdapter::~SFMLWindowAdapter()
{
    this->window->close();
}


