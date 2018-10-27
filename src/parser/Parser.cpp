#include <cctype>
#include "parser/Parser.h"


namespace wfg {
namespace parser {
    Parser::Parser() {}

    // void Parser::putPunctuation(char p) {
    //     switch (p) {
    //         case ''
    //     }
    // }

    void Parser::tokenize(std::string fileContent) {
        char state = Parser::STATE_SPACE;

        for (std::string::iterator it = fileContent.begin(); it != fileContent.end(); ++it) {
            char c = *it;
            unsigned char uc = static_cast<unsigned char>(c);

            switch (state)
            {
                case Parser::STATE_SPACE:
                    if (isalpha(uc)) {
                        state = Parser::STATE_IDENTIFIER;
                        buffer << c;
                    } else if (isdigit(uc)) {
                        state = Parser::STATE_NUMBER;
                        buffer << c;
                    } else if (ispunct(uc)) {
                        state = Parser::STATE_PUNCTUATION;
                        buffer << c;
                    }
                    break;

                default:
                    break;
            }
        }
    }
};
};
