#pragma once
#include <vector>
#include "Value.h"
#include "State.h"

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
