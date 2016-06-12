#pragma once

#include <Fibula/Core/KernelAwareListener.hpp>

namespace Fibula {
    namespace Bridge {

        using namespace std;

        using Event = Fibula::Events::Event;
        using Kernel = Fibula::Core::Kernel;
        using KernelAwareListener = Fibula::Core::KernelAwareListener;

        class SFMLEventListener : public KernelAwareListener
        {
        public:
            virtual LISTENER_RESPONSE handleEvent(shared_ptr<const Event> event) const override;

            SFMLEventListener(Kernel *kernel) : KernelAwareListener(kernel)
            { }
        };
    }
}
