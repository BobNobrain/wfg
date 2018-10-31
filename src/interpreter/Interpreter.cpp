#include "interpreter/Interpreter.h"

namespace wfg {
namespace interpreter {
    void Interpreter::run(const std::vector<Command*> instructions) {
        for (auto it = instructions.begin(); it != instructions.end(); ++it) {
            auto cmd = *it;
            cmd->execute(state);
        }
    }
};
};
