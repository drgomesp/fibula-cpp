#ifndef PROJECT_CAMERA_HPP
#define PROJECT_CAMERA_HPP

#include <memory>
#include <SFML/Graphics/View.hpp>

#include <Fibula/Graphics/Window.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;

        class Camera
        {
        private:
            shared_ptr<Window> window;
            shared_ptr<sf::View> _sfml_view;
        public:
            Camera(shared_ptr <Window> window, const shared_ptr<sf::View> &_sfml_view)
                : window(window), _sfml_view(_sfml_view)
            { }

            void move(int offsetX, int offsetY);
        };
    }
}

#endif //PROJECT_CAMERA_HPP
