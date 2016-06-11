#include <Fibula/Graphics.hpp>
#include <Fibula/Bridge.hpp>
#include <Fibula/Events.hpp>

using namespace Fibula::Bridge;
using namespace Fibula::Events;
using namespace Fibula::Graphics;

Window::Window(unsigned int width, unsigned int height, const string &title, Dispatcher &dispatcher)
    : width(width),
      height(height),
      title(title),
      dispatcher(dispatcher)
{
    this->_sfml_window = make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
}

void Window::setUp(shared_ptr<Kernel> kernel)
{
    std::shared_ptr<SFMLEventListener> listener = make_shared<SFMLEventListener>(kernel);
    this->dispatcher.addListener("event.sfml", listener);

    kernel->running = true;
}

void Window::draw()
{
    for (shared_ptr<Drawable> drawable : this->drawables) {
        this->_sfml_window->clear();
        drawable->draw(this->_sfml_window.get());
        this->_sfml_window->display();
    }
}

void Window::handleEvents()
{
    sf::Event event;

    while (this->_sfml_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            this->_sfml_window->close();
        } else {
            for (shared_ptr<Drawable> drawable : this->drawables) {
                std::shared_ptr<SFMLPayload> payload = make_shared<SFMLPayload>(event);

                if (Cargo *cargo = dynamic_cast<Cargo *>(drawable.get())) {
                    payload->setCargo(cargo);
                } else {
                    payload->setCargo(nullptr);
                }

                std::shared_ptr<SFMLEvent> e = make_shared<SFMLEvent>(*payload);
                this->dispatcher.dispatchEvent("event.sfml", e);
            }
        }
    }
}

void Window::handleInputs()
{

}

void Window::update()
{

}

bool Window::isOpen()
{
    return this->_sfml_window->isOpen();
}

void Window::addDrawable(shared_ptr<Drawable> drawable)
{
    this->drawables.push_back(drawable);
}
