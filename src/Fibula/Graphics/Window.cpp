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
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;

    this->_sfml_window = make_shared<sf::RenderWindow>(
        sf::VideoMode(width, height),
        title,
        sf::Style::Default,
        settings
    );

    this->_sfml_window->setVerticalSyncEnabled(true);

    glEnable(GL_TEXTURE_2D);

    printf("Initialized OpenGL context :: version %s\n", glGetString(GL_VERSION));
}

void Window::setUp(Kernel *kernel)
{
    auto _sfml_view = make_shared<sf::View>(sf::FloatRect(0, 0, width, height));
    this->camera = make_shared<Camera>(this->shared_from_this(), _sfml_view);
    this->_sfml_window->setView(*_sfml_view);

    std::shared_ptr<SFMLEventListener> listener = make_shared<SFMLEventListener>(kernel);
    this->dispatcher.addListener("event.sfml", listener);

    kernel->running = true;
}

void Window::draw()
{
    this->_sfml_window->clear();

    for (shared_ptr<Drawable> drawable : this->drawables) {
        drawable->draw(this->shared_from_this());
    }

    this->_sfml_window->display();
}

void Window::handleEvents()
{
    sf::Event event;

    while (this->_sfml_window->pollEvent(event)) {

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

void Window::handleInputs()
{

}

void Window::update()
{

}

void Window::close()
{
    this->_sfml_window->close();
}

bool Window::isOpen()
{
    return this->_sfml_window->isOpen();
}

void Window::addDrawable(shared_ptr<Drawable> drawable)
{
    this->drawables.push_back(drawable);
}

const shared_ptr<Camera> &Window::getCamera() const
{
    return camera;
}
