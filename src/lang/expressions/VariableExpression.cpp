#include "lang/expressions/VariableExpression.h"

namespace wfg {
namespace lang {
    Value* VariableExpression::evaluate(interpreter::State& state) const {
        return state.fromMemory(identifier);
    }
};
};

