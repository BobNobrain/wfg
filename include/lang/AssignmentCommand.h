#pragma once
#include "lang/Command.h"
#include "lang/Expression.h"
#include <string>

namespace wfg {
namespace lang {
    class AssignmentCommand: public Command {
    private:
        std::string identifier;
        Expression* value;
    public:
        AssignmentCommand(const std::string& _identifier, Expression*& _value)
            : identifier(_identifier)
            , value(_value)
        {}
        virtual ~AssignmentCommand() override;

        virtual void execute(interpreter::State& state) override;
    };
};
};
