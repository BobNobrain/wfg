#include "interpreter/State.h"
#include <iostream>

namespace wfg {
namespace interpreter {
    State::State() { }

    State::~State() {
        // std::cout << "~" << std::endl;
        // for (auto it = output.begin(); it != output.end(); ++it) {
        //     Value* v = *it;
        //     delete v;
        // }
    }

    Value* State::fromMemory(const std::string& identifier) {
        // std::cout << "from mem: " << identifier << std::endl;
        return memory[identifier];
    }

    void State::toMemory(const std::string& identifier, Value* value) {
        // std::cout << "to mem: " << identifier << std::endl;
        memory[identifier] = value;
    }

    Value* State::read() {
        // TODO
        return 0;
    }

    void State::write(Value* value) {
        std::cout << "[OUTPUT] " << value->toString() << std::endl;
        // output.push_back(value);
    }
};
};
