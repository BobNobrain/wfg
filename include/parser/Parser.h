#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "parser/Token.h"
#include "lang/Command.h"

namespace wfg {
namespace parser {

    class Parser {
    private:
        std::vector<Token> tokens;
        std::ostringstream buffer;
        char state;

        static const char STATE_IDENTIFIER      = 0;
        static const char STATE_SPACE           = 1;
        static const char STATE_NUMBER          = 2;
        static const char STATE_PUNCTUATION     = 3;

        void flushBuffer();
        void handleOperators(const std::string& buffer_content);
        void handleNumber(const std::string& buffer_content);
    public:
        Parser();

        void tokenize(std::string fileContent);
        std::vector<lang::Command*> ast();
    };
};
};
