#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "parser/Token.h"

namespace wfg {
namespace parser {

    class Tokenizer {
    private:
        std::ostringstream buffer;
        char state;

        static const char STATE_IDENTIFIER      = 0;
        static const char STATE_SPACE           = 1;
        static const char STATE_NUMBER          = 2;
        static const char STATE_PUNCTUATION     = 3;

        void flushBuffer();
        void handleOperators(const std::string& buffer_content);
        void handleNumber(const std::string& buffer_content);
        void handleIdentifier(const std::string& buffer_content);
    public:
        std::vector<Token*> tokens;
        Tokenizer();
        ~Tokenizer();

        void tokenize(std::string fileContent);
    };
};
};
