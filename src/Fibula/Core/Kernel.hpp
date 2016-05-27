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

#include <Fibula/Graphics/WindowAdapterInterface.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace Fibula {
    namespace Core {
        class Kernel : public boost::enable_shared_from_this<Kernel>
        {
        private:
            bool running = false;
            bool booted = false;

            EventDispatcher::Dispatcher dispatcher;
            boost::shared_ptr<Graphics::WindowAdapterInterface> window;
        public:
            Kernel();
            void bootstrap();
            void run();
            void terminate();
            boost::shared_ptr<Kernel> getShared();
        };
    }
}

#endif //FIBULA_KERNEL_HPP
