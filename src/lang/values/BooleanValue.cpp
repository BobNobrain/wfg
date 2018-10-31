#include "lang/values/BooleanValue.h"

namespace wfg {
namespace lang {
    const std::string BooleanValue::STR_FALSE = "false";
    const std::string BooleanValue::STR_TRUE = "true";

    int BooleanValue::type() const {
        return Value::TYPE_NUMBER;
    }

    std::string BooleanValue::toString() const {
        if (b) return BooleanValue::STR_TRUE;
        return BooleanValue::STR_FALSE;
    }
};
};
