#pragma once
#include <string>

namespace wfg {
namespace lang {
    class Value {
    public:
        Value();
        virtual ~Value();

        virtual void* eval() = 0;
        virtual int type() = 0;
        virtual std::string toString() = 0;

        static const int TYPE_STRING = 1;
        static const int TYPE_NUMBER = 2;
        static const int TYPE_BOOL = 3;
        static const int TYPE_LIST = 4;
    };
};
};
