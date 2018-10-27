#pragma once
#include <string>
#include <vector>
#include <map>
#include "lang/Value.h"

using namespace wfg::lang;

namespace wfg {
namespace interpreter {
    class State {
    private:
        std::map<std::string, Value*> memory;
        std::vector<Value*> input;
        std::vector<Value*> output;
    public:
        State(const std::vector<Value*>& _input)
            : input(_input)
        {}
        ~State();

        Value* fromMemory(const std::string& identifier);
        void toMemory(const std::string& identifier, Value* value);
        Value* read();
        void write(Value* value);
    };
};
};