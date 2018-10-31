#pragma once
#include "lang/Expression.h"
#include "lang/Value.h"

namespace wfg {
namespace lang {
    class VariableExpression: public Expression {
    private:
        const std::string identifier;
    public:
        VariableExpression(const std::string& _identifier): identifier(_identifier) {}
        virtual ~VariableExpression() override {}

        virtual Value *evaluate(interpreter::State& state) const override;
    };
};
};
