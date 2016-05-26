#ifndef FIBULA_KERNEL_HPP
#define FIBULA_KERNEL_HPP

#include <Fibula/Graphics/Window.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

namespace Fibula {
    namespace Core {
        class Kernel
        {
        private:
            bool running = false;
            bool booted = false;

            Fibula::EventDispatcher::Dispatcher dispatcher;
            Fibula::Graphics::Window *window;
        public:
            Kernel();
            void bootstrap();
            void run();
            void terminate();
        };
    }
}

#endif //FIBULA_KERNEL_HPP
