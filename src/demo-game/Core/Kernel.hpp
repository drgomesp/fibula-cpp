#ifndef GAME_KERNEL_HPP
#define GAME_KERNEL_HPP

#include <Fibula/Core/Kernel.hpp>

namespace Game {
    namespace Core {
        class Kernel : public Fibula::Core::Kernel
        {
        public:
            Kernel(const std::string &graphicsAdapter);
        };
    }
}

#endif //FIBULA_KERNEL_HPP
