#pragma once
#include <vector>
#include "lang/Value.h"
#include "interpreter/State.h"

namespace wfg {
    class Interpreter {
    private:
        State state;
    public:
        Interpreter(const std::vector<Value*>& input)
            : state(input)
        {}
    };
};
