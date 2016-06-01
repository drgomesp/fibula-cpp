#ifndef FIBULA_KERNEL_HPP
#define FIBULA_KERNEL_HPP

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher;
    }

    namespace Graphics {
        namespace Window {
            class WindowAdapterInterface;
        }
    }
}

#include <memory>

#include <Fibula/Graphics/Window/WindowAdapterInterface.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

namespace Fibula {
    namespace Core {

        using WindowAdapterInterface = Fibula::Graphics::Window::WindowAdapterInterface;

        class Kernel
        {
        protected:
            bool running = false;
            bool booted = false;

            EventDispatcher::Dispatcher dispatcher;
            std::shared_ptr<WindowAdapterInterface> window;
        public:
            void addListener(
                const std::string &eventName,
                std::shared_ptr<EventDispatcher::ListenerInterface> listener
            );

            void bootstrap();

            void run();

            void terminate();
        };
    }
}

#endif //FIBULA_KERNEL_HPP
