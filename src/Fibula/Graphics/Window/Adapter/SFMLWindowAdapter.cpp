#include "SFMLWindowAdapter.hpp"
#include "SFMLRendererAdapter.hpp"

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

using namespace Fibula::Core;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Graphics::Window::Adapter;

SFMLWindowAdapter::SFMLWindowAdapter(
    const string &title,
    const unsigned int width,
    const unsigned int height,
    shared_ptr<Dispatcher> dispatcher,
    Kernel &kernel,
    shared_ptr<RendererAdapter> renderer)
    : WindowAdapter("SFML", title, width, height, dispatcher, kernel, renderer)
{
    this->window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(this->width, this->height),
        this->title
    );

    this->renderer = renderer;
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
    this->window->clear();

    this->renderer->render(this->window.get());

    this->window->display();
}

SFMLWindowAdapter::~SFMLWindowAdapter()
{

}
