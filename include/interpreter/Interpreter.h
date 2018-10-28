#pragma once
#include <vector>
#include "lang/Value.h"
#include "interpreter/State.h"

namespace wfg {
namespace interpreter {
    class Interpreter {
    private:
        State state;
    public:
        Interpreter();
        ~Interpreter();
    };
};
};
