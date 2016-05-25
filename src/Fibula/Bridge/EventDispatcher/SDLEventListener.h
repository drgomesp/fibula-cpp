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
                virtual void handleEvent(boost::shared_ptr<Event> event) override;

                SDLEventListener(boost::shared_ptr<Kernel> kernel) : KernelAwareListener(kernel)
                { }

                virtual ~SDLEventListener()
                { }
            };
        }
    }
}


#endif //FIBULA_SDLEVENTLISTENER_H
