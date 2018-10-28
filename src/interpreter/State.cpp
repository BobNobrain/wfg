#include "interpreter/State.h"

namespace wfg {
namespace interpreter {
    State::~State() {
        for (auto it = output.begin(); it != output.end(); ++it) {
            Value* v = *it;
            delete v;
        }
    }

    Value* State::fromMemory(const std::string& identifier) {
        return memory[identifier];
    }

    void State::toMemory(const std::string& identifier, Value* value) {
        memory[identifier] = value;
    }

    Value* State::read() {
        // TODO
        return 0;
    }

    void State::write(Value* value) {
        output.push_back(value);
    }
};
};
