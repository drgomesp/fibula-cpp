#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;

        class Drawable
        {
        public:
            virtual void draw(sf::RenderWindow *window) = 0;
        };
    }
}
