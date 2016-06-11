#pragma once

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/Events/Listener.hpp>

namespace Fibula {
    namespace Core {

        using Listener = Fibula::Events::Listener;

        class KernelAwareListener : public Listener
        {
        protected:
            shared_ptr<Kernel> kernel;
        public:
            KernelAwareListener(shared_ptr<Kernel> kernel) : kernel(kernel)
            { }

            virtual ~KernelAwareListener()
            { }
        };
    }
}
