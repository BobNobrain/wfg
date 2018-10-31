#include <cctype>
#include <string>
#include <exception>
#include "parser/Tokenizer.h"
#include "exception/ParserException.h"


namespace wfg {
namespace parser {
    Tokenizer::Tokenizer() {
        state = STATE_SPACE;
    }
    Tokenizer::~Tokenizer() {
        for (auto it = tokens.begin(); it != tokens.end(); ++it) {
            Token* t = *it;
            delete t;
        }
    }

    void Tokenizer::flushBuffer() {
        std::string buffer_content = buffer.str();
        buffer.str(std::string());

        switch (state) {
            case Tokenizer::STATE_IDENTIFIER:
                handleIdentifier(buffer_content);
                break;

            case Tokenizer::STATE_NUMBER:
                handleNumber(buffer_content);
                break;

            case Tokenizer::STATE_PUNCTUATION:
                handleOperators(buffer_content);
                break;

            default:
                throw std::runtime_error("Cannot flush buffer: incorrect state");
        }
    }

    void Tokenizer::handleNumber(const std::string& buffer_content) {
        float num = std::stof(buffer_content);
        tokens.push_back(new NumberToken(num));
    }

    void Tokenizer::handleOperators(const std::string& buffer_content) {
        // Here we shall check, if we have some operators in one token: (-1), for example
        OperatorToken* token = new OperatorToken(buffer_content);
        if (token->type() != Token::TYPE_UNKNOWN) {
            // everything is ok
            tokens.push_back(token);
            return;
        }
        // unknown operator, we heed to find a way
        // to split down buffer_content into several operators
        // TODO!
        tokens.push_back(token);
    }

    void Tokenizer::handleIdentifier(const std::string& buffer_content) {
        if (buffer_content == "true") {
            tokens.push_back(new BoolToken(true));
            return;
        }
        if (buffer_content == "false") {
            tokens.push_back(new BoolToken(false));
            return;
        }
        KeywordToken* kw = new KeywordToken(buffer_content);
        if (kw->type() != Token::TYPE_UNKNOWN) {
            tokens.push_back(kw);
            return;
        }
        tokens.push_back(new IdentifierToken(buffer_content));
    }

    void Tokenizer::tokenize(std::string fileContent) {
        int col = 0;
        int ln = 0;
        for (std::string::iterator it = fileContent.begin(); it != fileContent.end(); ++it) {
            char c = *it;
            unsigned char uc = static_cast<unsigned char>(c);

            switch (state)
            {
                case Tokenizer::STATE_SPACE:
                    if (isalpha(uc)) {
                        state = Tokenizer::STATE_IDENTIFIER;
                        buffer << c;
                    } else if (isdigit(uc)) {
                        state = Tokenizer::STATE_NUMBER;
                        buffer << c;
                    } else if (ispunct(uc)) {
                        state = Tokenizer::STATE_PUNCTUATION;
                        buffer << c;
                    } else if (isspace(uc)) {
                        // skip
                    } else {
                        throw ParserException(col, ln, "valid char", std::to_string(c));
                    }
                    break;

                case Tokenizer::STATE_IDENTIFIER:
                    if (isalnum(uc)) {
                        buffer << c;
                    } else if (ispunct(uc)) {
                        flushBuffer();
                        state = Tokenizer::STATE_PUNCTUATION;
                        buffer << c;
                    } else if (isspace(uc)) {
                        flushBuffer();
                        state = Tokenizer::STATE_SPACE;
                    } else {
                        throw ParserException(col, ln, "valid char", std::to_string(c));
                    }
                    break;

                case Tokenizer::STATE_NUMBER:
                    if (isdigit(uc)) {
                        buffer << c;
                    } else if (isspace(uc)) {
                        flushBuffer();
                        state = Tokenizer::STATE_SPACE;
                    } else if (ispunct(uc)) {
                        flushBuffer();
                        state = Tokenizer::STATE_PUNCTUATION;
                        buffer << c;
                    } else {
                        throw ParserException(col, ln, "number, operator or space", std::to_string(c));
                    }
                    break;

                case Tokenizer::STATE_PUNCTUATION:
                    if (ispunct(uc)) {
                        buffer << c;
                    } else if (isspace(uc)) {
                        flushBuffer();
                        state = Tokenizer::STATE_SPACE;
                    } else if (isdigit(uc)) {
                        flushBuffer();
                        state = Tokenizer::STATE_NUMBER;
                        buffer << c;
                    } else if (isalpha(uc)) {
                        flushBuffer();
                        state = Tokenizer::STATE_IDENTIFIER;
                        buffer << c;
                    } else {
                        throw ParserException(col, ln, "valid char", std::to_string(c));
                    }
                    break;

                default:
                    throw std::runtime_error("Invalid Tokenizer state");
                    break;
            }

            ++col;
            if (c == '\n') {
                col = 0;
                ++ln;
            }
        }
        flushBuffer();
    }
};
};
