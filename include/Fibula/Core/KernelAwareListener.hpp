#pragma once

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/Events/Listener.hpp>

namespace Fibula {
    namespace Core {

        using Listener = Fibula::Events::Listener;

        class KernelAwareListener : public Listener
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
