#pragma once

namespace Fibula {
    namespace Events {
        class Dispatcher;
    }
}

#include <Fibula/Events/Dispatcher.hpp>

enum class LISTENER_RESPONSE
{
    SUCCESS = 0, FAILURE = -1
};

namespace Fibula {
    namespace Events {
        class Listener
        {
        protected:
            Dispatcher *dispatcher;
        public:
            virtual LISTENER_RESPONSE handleEvent(std::shared_ptr<const Event> event) const = 0;

            inline void setDispatcher(Dispatcher *dispatcher)
            {
                this->dispatcher = dispatcher;
            }

            virtual ~Listener() { }
        };
    }
}
