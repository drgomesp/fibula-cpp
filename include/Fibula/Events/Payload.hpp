#pragma once

#include <vector>

#include <Fibula/Events/Cargo.hpp>

namespace Fibula {
    namespace Events {

        using namespace std;

        class Payload
        {
        protected:
            Cargo *cargo;
        public:
            inline void setCargo(Cargo *cargo)
            {
                this->cargo = cargo;
            }

            Cargo *getCargo() const
            {
                return cargo;
            }

            virtual ~Payload() {}
        };
    }
}
