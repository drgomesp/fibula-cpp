#ifndef FIBULA_KERNELAWARELISTENER_H
#define FIBULA_KERNELAWARELISTENER_H

#include <Fibula/Core/Kernel.h>
#include <Fibula/EventDispatcher/Listener.h>
#include <Fibula/Bridge/EventDispatcher/SDLEvent.h>

using namespace Fibula::Bridge::EventDispatcher;

namespace Fibula {
    namespace Core {
        class KernelAwareListener : public Listener
        {
        protected:
            Kernel *kernel;
        public:
            KernelAwareListener(Kernel *kernel) : kernel(kernel)
            { }
        };
    }
}

#endif //FIBULA_KERNELAWARELISTENER_H
