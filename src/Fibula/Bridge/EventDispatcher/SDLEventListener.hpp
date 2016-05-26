#ifndef FIBULA_SDLEVENTLISTENER_HPP
#define FIBULA_SDLEVENTLISTENER_HPP

#include <Fibula/Core/KernelAwareListener.hpp>

namespace Fibula {
    namespace Bridge {
        namespace EventDispatcher {
            class SDLEventListener : public Fibula::Core::KernelAwareListener
            {
            public:
                virtual LISTENER_RESPONSE handleEvent(Fibula::EventDispatcher::Event *event) override;

                SDLEventListener(Fibula::Core::Kernel *kernel) : KernelAwareListener(kernel)
                { }

                virtual ~SDLEventListener()
                { }
            };
        }
    }
}

#endif //FIBULA_SDLEVENTLISTENER_HPP
