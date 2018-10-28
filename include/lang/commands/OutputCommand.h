#pragma once
#include "lang/Command.h"
#include "lang/Expression.h"
#include <string>

namespace wfg {
namespace lang {
    class OutputCommand: public Command {
    private:
        Expression* value;
    public:
        OutputCommand(Expression*& _value)
            : value(_value)
        {}
        virtual ~OutputCommand() override;

        virtual void execute(interpreter::State& state) override;
    };
};
};
