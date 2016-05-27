#include <Fibula/Graphics/Window.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEvent.hpp>
#include <Fibula/Graphics/Adapter/SDLWindowAdapter.hpp>

#include <iostream>

using namespace Fibula::Graphics;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Bridge::EventDispatcher;
using namespace Fibula::Graphics::Adapter;

Window::Window(const std::string &title, int width, int height, Dispatcher &dispatcher)
        : title(title),
          width(width),
          height(height),
          dispatcher(dispatcher)
{
    this->window = new SDLWindowAdapter(title, width, height, dispatcher);

    try {
        this->window->create(title, width, height, dispatcher);
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
        throw e;
    }
}

Window::~Window()
{
    delete this->window;
}

void Window::handleEvents()
{
    this->window->handleEvents();
}

