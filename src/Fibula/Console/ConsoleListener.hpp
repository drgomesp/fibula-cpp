#ifndef FIBULA_CONSOLELISTENER_HPP
#define FIBULA_CONSOLELISTENER_HPP

#include <atomic>
#include <string>
#include <Fibula/Core/KernelAwareListener.hpp>

namespace Fibula {
    namespace Console {
        class ConsoleListener : public Fibula::Core::KernelAwareListener
        {
        public:
            ConsoleListener(Fibula::Core::Kernel *kernel) : KernelAwareListener(kernel)
            { }

            virtual LISTENER_RESPONSE handleEvent(boost::shared_ptr<const Fibula::EventDispatcher::Event> event) const override;
        };
    }
}

#endif //FIBULA_CONSOLELISTENER_HPP
