#ifndef FIBULA_KERNEL_HPP
#define FIBULA_KERNEL_HPP

#include <Fibula/Graphics/Window.hpp>
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

            Fibula::EventDispatcher::Dispatcher dispatcher;
            boost::shared_ptr<Fibula::Graphics::Window> window;
        public:
            Kernel();
            void bootstrap();
            void run();
            void terminate();
            boost::shared_ptr<Kernel> getShared()
            {
                return shared_from_this();
            }
        };
    }
}

#endif //FIBULA_KERNEL_HPP
