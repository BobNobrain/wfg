#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Token.h"
#include "Command.h"

namespace wfg {
namespace parser {

    class Parser {
    private:
        std::vector<Token> tokens;
        std::ostringstream buffer;

        static const char STATE_IDENTIFIER      = 0;
        static const char STATE_SPACE           = 1;
        static const char STATE_NUMBER          = 2;
        static const char STATE_PUNCTUATION     = 3;

        void flushBuffer();
        void putPunctuation(char p);
    public:
        Parser();

        void tokenize(std::string fileContent);
        std::vector<Command*> ast();
    };
};
};
