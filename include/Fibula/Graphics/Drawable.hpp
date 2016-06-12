#pragma once

#include <memory>

#include <glm/vec2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <Fibula/Graphics/Window.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace glm;
        using namespace std;

        class Drawable
        {
        public:
            dvec2 size;
            dvec2 position;

        public:
            Drawable(
                const dvec2 &size,
                const dvec2 &position
            ) : size(size), position(position)
            {}


            virtual void draw(shared_ptr<Window> window) = 0;
        };
    }
}
