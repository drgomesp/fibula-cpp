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
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;

    this->window = new sf::RenderWindow(
            sf::VideoMode(this->width, this->height),
            this->title,
            sf::Style::Default,
            settings
    );

    this->window->setVerticalSyncEnabled(true);
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


