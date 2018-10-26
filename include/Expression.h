#pragma once
#include "Value.h"
#include "State.h"

namespace wfg
{
    class Expression
    {
    public:
        Expression() {}

        virtual Value* evaluate(State &state) = 0;
    };
};
