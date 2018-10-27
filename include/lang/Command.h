#pragma once
#include "interpreter/State.h"

namespace wfg {
    class Command {
    public:
        Command() {}

        virtual void execute(State& state) = 0;
    };
};
