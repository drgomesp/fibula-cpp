#ifndef FIBULA_KERNEL_HPP
#define FIBULA_KERNEL_HPP

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher;
    }

    namespace Graphics {
        class WindowAdapterInterface;
    }
}

#include <memory>
#include <Fibula/Graphics/WindowAdapterInterface.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

namespace Fibula {
    namespace Core {
        class Kernel
        {
        private:
            bool running = false;
            bool booted = false;
            std::string graphicsAdapter;

            EventDispatcher::Dispatcher dispatcher;
            std::shared_ptr<Graphics::WindowAdapterInterface> window;
        public:
            Kernel(std::string graphicsAdapter) : graphicsAdapter(graphicsAdapter)
            { }

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
