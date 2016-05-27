#ifndef FIBULA_LISTENER_HPP
#define FIBULA_LISTENER_HPP

#include <boost/shared_ptr.hpp>

enum LISTENER_RESPONSE
{
    SUCCESS = 0, FAILURE = 1
};

namespace Fibula {
    namespace EventDispatcher {
        class ListenerInterface
        {
        public:
            virtual LISTENER_RESPONSE handleEvent(boost::shared_ptr<const Event> event) const = 0;

            virtual ~ListenerInterface()
            { }
        };
    }
}

#endif //FIBULA_LISTENER_HPP
