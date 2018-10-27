#pragma once
#include "lang/Value.h"
#include "interpreter/State.h"

namespace wfg
{
    class Expression
    {
    public:
        Expression() {}

        virtual Value* evaluate(State &state) = 0;
    };
};
