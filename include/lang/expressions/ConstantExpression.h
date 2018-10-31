#pragma once
#include "lang/Expression.h"
#include "lang/Value.h"

namespace wfg {
namespace lang {
    class ConstantExpression: public Expression {
    private:
        Value* constant;
    public:
        ConstantExpression(Value* val): constant(val) {}
        virtual ~ConstantExpression() override {
            delete constant;
        }

        virtual Value *evaluate(interpreter::State& state) const override;

        static Expression* fromNumber(const float& n);
        static Expression* fromBoolean(const bool& b);
    };
};
};
