#include <Fibula/Graphics/Camera.hpp>

using namespace Fibula::Graphics;

void Camera::move(int offsetX, int offsetY)
{
    sf::View view = this->window->get_sfml_window()->getView();

    view.move(offsetX, offsetY);

    this->window->get_sfml_window()->setView(view);
}
