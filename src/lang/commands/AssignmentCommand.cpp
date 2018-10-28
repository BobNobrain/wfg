#include "lang/commands/AssignmentCommand.h"

namespace wfg {
namespace lang {
    void AssignmentCommand::execute(interpreter::State& state) {
        Value* result = value->evaluate(state);
        state.toMemory(identifier, result);
    }

    AssignmentCommand::~AssignmentCommand() {
        delete value;
    }
};
};
