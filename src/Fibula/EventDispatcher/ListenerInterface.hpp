#ifndef FIBULA_LISTENER_HPP
#define FIBULA_LISTENER_HPP

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher;
    }
}

#include <boost/shared_ptr.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

enum class LISTENER_RESPONSE
{
    SUCCESS = 0, FAILURE = -1
};

namespace Fibula {
    namespace EventDispatcher {
        class ListenerInterface
        {
        protected:
            Dispatcher *dispatcher;
        public:
            virtual LISTENER_RESPONSE handleEvent(const Event &event) const = 0;

            inline void setDispatcher(Dispatcher *dispatcher)
            {
                this->dispatcher = dispatcher;
            }

            virtual ~ListenerInterface() { }
        };
    }
}

#endif //FIBULA_LISTENER_HPP
