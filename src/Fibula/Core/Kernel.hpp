#ifndef FIBULA_KERNEL_HPP
#define FIBULA_KERNEL_HPP

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher;
    }

    namespace Graphics {
        namespace Window {
            class WindowAdapter;
        }
    }
}

#include <memory>

#include <Fibula/Graphics/Window/WindowAdapter.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

namespace Fibula {
    namespace Core {

        using namespace std;
        using Dispatcher = Fibula::EventDispatcher::Dispatcher;
        using WindowAdapter = Fibula::Graphics::Window::WindowAdapter;

        class Kernel
        {
        protected:
            bool running = false;
            bool booted = false;

            shared_ptr<Dispatcher> dispatcher;
            shared_ptr<WindowAdapter> window;
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
