#pragma once

#include <memory>
#include <vector>

#include <glm/vec2.hpp>
#include <SFML/Graphics.hpp>

namespace Fibula {
    namespace Core {
        class Kernel;
    }

    namespace Graphics {
        class Drawable;
    }
}

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/Events/Dispatcher.hpp>
#include <Fibula/Graphics/Drawable.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;

        using Kernel = Fibula::Core::Kernel;
        using Dispatcher = Fibula::Events::Dispatcher;
        using DrawablesVector = vector<shared_ptr<Drawable>>;

        class Window : public enable_shared_from_this<Window>
        {
            friend class Sprite;

        private:
            Dispatcher &dispatcher;
            shared_ptr<sf::RenderWindow> _sfml_window;
            DrawablesVector drawables;

            const shared_ptr<sf::RenderWindow> &get_sfml_window() const
            {
                return _sfml_window;
            }

        protected:
            unsigned int width;
            unsigned int height;
            const string title;

        public:
            Window(
                unsigned int width,
                unsigned int height,
                const string &title,
                Dispatcher &dispatcher
            );

            void setUp(Kernel *kernel);
            void draw();
            bool isOpen();
            void handleEvents();
            void handleInputs();
            void update();
            void close();

            void addDrawable(shared_ptr<Drawable> drawable);
        };
    }
}
