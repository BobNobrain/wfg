#include <cctype>
#include <string>
#include <exception>
#include "parser/Parser.h"
#include "exception/ParserException.h"


namespace wfg {
namespace parser {
    bool is_keyword(const std::string& token) {
        if (token == "read") return true;
        if (token == "output") return true;
        if (token == "if") return true;
        if (token == "then") return true;
        if (token == "else") return true;
        if (token == "while") return true;
        if (token == "do") return true;
        if (token == "not") return true;
        return false;
    }


    Parser::Parser() {}

    void Parser::flushBuffer() {
        std::string buffer_content = buffer.str();
        buffer.str(std::string());
        switch (state) {
            case Parser::STATE_IDENTIFIER:
                if (buffer_content == "true") {
                    tokens.push_back(BoolToken(true));
                    break;
                }
                if (buffer_content == "false") {
                    tokens.push_back(BoolToken(false));
                    break;
                }
                if (is_keyword(buffer_content)) {
                    tokens.push_back(KeywordToken(buffer_content));
                    break;
                }

                tokens.push_back(IdentifierToken(buffer_content));
                break;

            case Parser::STATE_NUMBER:
                handleNumber(buffer_content);
                break;

            case Parser::STATE_PUNCTUATION:
                handleOperators(buffer_content);
                break;

            default:
                throw std::runtime_error("Cannot flush buffer: incorrect state");
        }
    }

    void Parser::handleNumber(const std::string& buffer_content) {
        float num = std::stof(buffer_content);
        tokens.push_back(NumberToken(num));
    }

    void Parser::handleOperators(const std::string& buffer_content) {
        // Here we shall check, if we have some operators in one token: (-1), for example
        OperatorToken token(buffer_content);
        if (token.type() != Token::TYPE_UNKNOWN) {
            // everything is ok
            tokens.push_back(token);
            return;
        }
        // unknown operator, we heed to find a way
        // to split down buffer_content into several operators
        // TODO!
        tokens.push_back(token);
    }

    void Parser::tokenize(std::string fileContent) {
        int col = 0;
        int ln = 0;
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
                    } else if (isspace(uc)) {
                        // skip
                    } else {
                        throw ParserException(col, ln, "valid char", std::to_string(c));
                    }
                    break;

                case Parser::STATE_IDENTIFIER:
                    if (isalnum(uc)) {
                        buffer << c;
                    } else if (ispunct(uc)) {
                        flushBuffer();
                        state = Parser::STATE_PUNCTUATION;
                        buffer << c;
                    } else if (isspace(uc)) {
                        flushBuffer();
                        state = Parser::STATE_SPACE;
                    } else {
                        throw ParserException(col, ln, "valid char", std::to_string(c));
                    }
                    break;

                case Parser::STATE_NUMBER:
                    if (isdigit(uc)) {
                        buffer << c;
                    } else if (isspace(uc)) {
                        flushBuffer();
                        state = Parser::STATE_SPACE;
                    } else if (ispunct(uc)) {
                        flushBuffer();
                        state = Parser::STATE_PUNCTUATION;
                        buffer << c;
                    } else {
                        throw ParserException(col, ln, "number, operator or space", std::to_string(c));
                    }
                    break;

                case Parser::STATE_PUNCTUATION:
                    if (ispunct(uc)) {
                        buffer << c;
                    } else if (isspace(uc)) {
                        flushBuffer();
                        state = Parser::STATE_SPACE;
                    } else if (isdigit(uc)) {
                        flushBuffer();
                        state = Parser::STATE_NUMBER;
                        buffer << c;
                    } else if (isalpha(uc)) {
                        flushBuffer();
                        state = Parser::STATE_IDENTIFIER;
                        buffer << c;
                    } else {
                        throw ParserException(col, ln, "valid char", std::to_string(c));
                    }
                    break;

                default:
                    throw std::runtime_error("Invalid parser state");
                    break;
            }

            ++col;
            if (c == '\n') {
                col = 0;
                ++ln;
            }
        }
    }

    std::vector<lang::Command*> Parser::ast() {
        return std::vector<lang::Command*>();
    }
};
};
