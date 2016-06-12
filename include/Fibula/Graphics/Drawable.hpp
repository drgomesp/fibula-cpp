#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include <Fibula/Graphics/Window.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;

        class Drawable
        {
        public:
            virtual void draw(shared_ptr<Window> window) = 0;
        };
    }
}
