#ifndef FIBULA_SDLEVENTLISTENER_HPP
#define FIBULA_SDLEVENTLISTENER_HPP

#include <Fibula/Core/KernelAwareListener.hpp>

namespace Fibula {
    namespace Bridge {
        namespace EventDispatcher {
            class SDLEventListener : public Fibula::Core::KernelAwareListener
            {
            public:
                virtual LISTENER_RESPONSE handleEvent(boost::shared_ptr<const Fibula::EventDispatcher::Event> event) const override;

                SDLEventListener(Fibula::Core::Kernel *kernel) : KernelAwareListener(kernel)
                { }
            };
        }
    }
}

#endif //FIBULA_SDLEVENTLISTENER_HPP
