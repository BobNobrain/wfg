#pragma once
#include "lang/Value.h"

namespace wfg {
namespace lang {
    class BooleanValue: public Value {
    public:
        const bool b;
        BooleanValue(const bool& _b): b(_b) {}
        virtual ~BooleanValue() override {}

        virtual int type() const override;
        virtual std::string toString() const override;

        static const std::string STR_TRUE;
        static const std::string STR_FALSE;
    };
};
};
