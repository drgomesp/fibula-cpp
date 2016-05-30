#ifndef FIBULA_KERNELAWARELISTENER_HPP
#define FIBULA_KERNELAWARELISTENER_HPP

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/EventDispatcher/ListenerInterface.hpp>
#include <Fibula/EventDispatcher/Event.hpp>

namespace Fibula {
    namespace Core {
        using Event = Fibula::EventDispatcher::Event;

        template<class EventType>
        class KernelAwareListener : public Fibula::EventDispatcher::ListenerInterface<EventType>
        {
        protected:
            Kernel *kernel;
        public:
            KernelAwareListener(Kernel *kernel) : kernel(kernel)
            { }

            virtual ~KernelAwareListener()
            { }
        };
    }
}

#endif //FIBULA_KERNELAWARELISTENER_H
