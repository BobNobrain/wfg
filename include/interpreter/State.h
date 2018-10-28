#pragma once
#include <string>
#include <vector>
#include <map>
#include "lang/Value.h"

using namespace wfg::lang;

namespace wfg {
namespace interpreter {
    typedef std::map<std::string, Value*> Memory;
    typedef std::vector<Value*> Output;

    class State {
    private:
        Memory memory;
        Output output;
    public:
        State();
        ~State();

        Value* fromMemory(const std::string& identifier);
        void toMemory(const std::string& identifier, Value* value);
        Value* read();
        void write(Value* value);
    };
};
};
