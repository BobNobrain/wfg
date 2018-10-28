#pragma once
#include "lang/Value.h"
#include "interpreter/State.h"

namespace wfg {
namespace lang {
    class Expression {
    public:
        Expression() {}

        virtual Value* evaluate(interpreter::State &state) = 0;
    };
};
};
