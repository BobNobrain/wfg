#include "parser/Token.h"

namespace wfg {
namespace parser {
    Token::Token() {}

    char Token::type() const {
        return Token::TYPE_UNKNOWN;
    }

    bool Token::isKeyword() {
        return type() & 0xA0;
    }
    bool Token::isOperator() {
        return type() & 0xB0;
    }
    bool Token::isLiteral() {
        return type() & 0xC0;
    }
};
};
