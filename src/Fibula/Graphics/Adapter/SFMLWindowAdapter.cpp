#include <Fibula/Graphics/Adapter/SFMLWindowAdapter.hpp>

using namespace Fibula::Graphics::Adapter;

SFMLWindowAdapter::SFMLWindowAdapter(
        const std::string &title,
        const unsigned int width,
        const unsigned int height,
        EventDispatcher::Dispatcher &dispatcher,
        Core::Kernel *kernel
) : WindowAdapterInterface("Graphics::Adapter::SFML", title, width, height, dispatcher, kernel)
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;

    sf::RenderWindow window(
            sf::VideoMode(this->width, this->height),
            this->title,
            sf::Style::Default,
            settings
    );

    this->window = &window;

    this->window->setVerticalSyncEnabled(true);
    glEnable(GL_TEXTURE_2D);
}

void SFMLWindowAdapter::handleEvents()
{
    sf::Event event;

    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        {
            break;
        }
        else if (event.type == sf::Event::Resized)
        {
            glViewport(0, 0, event.size.width, event.size.height);
        }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->window->display();
}

SFMLWindowAdapter::~SFMLWindowAdapter()
{

}


