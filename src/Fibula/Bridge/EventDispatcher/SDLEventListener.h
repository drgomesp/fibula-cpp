#ifndef FIBULA_SDLEVENTLISTENER_H
#define FIBULA_SDLEVENTLISTENER_H

#include <Fibula/Core/KernelAwareListener.h>

using namespace Fibula::Core;

namespace Fibula {
    namespace Bridge {
        namespace EventDispatcher {
            class SDLEventListener : public KernelAwareListener
            {
            public:
                virtual LISTENER_RESPONSE handleEvent(Event *event) override;

                SDLEventListener(Kernel *kernel) : KernelAwareListener(kernel)
                { }

                virtual ~SDLEventListener();
            };
        }
    }
}

#endif //FIBULA_SDLEVENTLISTENER_H
