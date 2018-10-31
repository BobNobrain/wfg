#include "lang/values/NumberValue.h"
#include <string>

namespace wfg {
namespace lang {
    int NumberValue::type() const {
        return Value::TYPE_NUMBER;
    }

    std::string NumberValue::toString() const {
        return std::to_string(n);
    }
};
};
