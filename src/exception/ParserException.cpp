#include "exception/ParserException.h"
#include <sstream>

namespace wfg {
namespace parser {
    const char* ParserException::what() const noexcept {
        return "Parser Exception";
    }

    const std::string ParserException::show() const noexcept {
        std::stringstream builder;
        builder << "Unexpected token at ";
        builder << line << ":" << col << ". ";
        builder << "Expected \"" << expected << "\", got \"";
        builder << got << "\"";

        return builder.str();
    }
};
};
