#include "lang/commands/OutputCommand.h"

namespace wfg {
namespace lang {
    void OutputCommand::execute(interpreter::State& state) {
        Value* result = value->evaluate(state);
        state.write(result);
    }

    OutputCommand::~OutputCommand() {
        delete value;
    }
};
};
