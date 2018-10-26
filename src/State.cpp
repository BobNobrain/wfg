#include "State.h"

namespace wfg {
    State::~State() {
        for (auto it = input.begin(); it != input.end(); ++it) {
            Value* v = *it;
            delete v;
        }

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
        Value* result = input.back();
        input.pop_back();
        return result;
    }

    void State::write(Value* value) {
        output.push_back(value);
    }
};
