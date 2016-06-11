#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include <Fibula/Graphics/Window.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;

        class Drawable
        {
            friend class Window;
        protected:
            virtual void draw(sf::RenderWindow *window) = 0;
        };
    }
}
