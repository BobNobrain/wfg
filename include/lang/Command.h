#pragma once
#include "interpreter/State.h"

namespace wfg {
namespace lang {
    class Command {
    public:
        Command() {}

        virtual void execute(interpreter::State& state) = 0;
    };
};
};
