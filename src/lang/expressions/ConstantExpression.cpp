#include "lang/expressions/ConstantExpression.h"
#include "lang/values/BooleanValue.h"
#include "lang/values/NumberValue.h"

namespace wfg {
namespace lang {
    Value* ConstantExpression::evaluate(interpreter::State& state) const {
        return constant;
    }

    Expression* ConstantExpression::fromNumber(const float& n) {
        return new ConstantExpression(new NumberValue(n));
    }

    Expression* ConstantExpression::fromBoolean(const bool& b) {
        return new ConstantExpression(new BooleanValue(b));
    }
};
};

