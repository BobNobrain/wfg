#pragma once
#include "lang/Value.h"

namespace wfg {
namespace lang {
    class NumberValue: public Value {
    public:
        const float n;
        NumberValue(const float& _n): n(_n) {}
        virtual ~NumberValue() override {}

        virtual int type() const override;
        virtual std::string toString() const override;
    };
};
};
