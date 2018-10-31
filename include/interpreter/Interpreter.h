#pragma once
#include <vector>
#include "lang/Value.h"
#include "lang/Command.h"
#include "interpreter/State.h"

namespace wfg {
namespace interpreter {
    class Interpreter {
    private:
        State state;
    public:
        Interpreter() {}
        ~Interpreter() {}

        void run(const std::vector<Command*> instructions);
    };
};
};
