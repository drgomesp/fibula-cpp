#ifndef FIBULA_SDLEVENTLISTENER_HPP
#define FIBULA_SDLEVENTLISTENER_HPP

#include <Fibula/Core/KernelAwareListener.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEvent.hpp>

namespace Fibula {
    namespace Bridge {
        namespace EventDispatcher {
            using Event = Fibula::Core::Event;
            using Kernel = Fibula::Core::Kernel;

            class SDLEventListener : public Fibula::Core::KernelAwareListener<SDLEvent> {
            public:
                SDLEventListener(Kernel *kernel) : KernelAwareListener(kernel) { }

                virtual LISTENER_RESPONSE handleEvent(SDLEvent *event) const override;
            };
        }
    }
}

#endif //FIBULA_SDLEVENTLISTENER_HPP
