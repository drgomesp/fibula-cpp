#ifndef FIBULA_WINDOW_HPP
#define FIBULA_WINDOW_HPP

#include <string>
#include <SDL.h>

#include <Fibula/EventDispatcher/Dispatcher.hpp>

namespace Fibula {
    namespace Graphics {
        class Window
        {
        private:
            std::string title;
            int width;
            int height;
            SDL_Window *window;
            Fibula::EventDispatcher::Dispatcher &dispatcher;
        public:
            Window(const std::string &title, int width, int height, Fibula::EventDispatcher::Dispatcher &dispatcher);
            ~Window();
            void handleEvents();
        };
    }
}

#endif //FIBULA_WINDOW_HPP
