#include <string>
#include <exception>
#include "parser/Parser.h"
#include "exception/ParserException.h"
#include "parser/Token.h"

#include "lang/commands/OutputCommand.h"
#include "lang/commands/AssignmentCommand.h"

#include "lang/expressions/VariableExpression.h"
#include "lang/expressions/ConstantExpression.h"

// #include <iostream>

using namespace wfg::lang;

namespace wfg {
namespace parser {
    Parser::Parser() { }
    Parser::~Parser() { }

    std::vector<Command*> Parser::ast(const std::vector<Token*>& tokens) {
        std::vector<Command*> result;

        iter_t it = tokens.cbegin();
        const iter_t end = tokens.end();
        while (it != end) {
            Command* next = readCommand(it, end);
            result.push_back(next);
        }

        return result;
    }

    Command* Parser::readCommand(iter_t& pos, const iter_t& end) {
        Token* t = *pos;
        Command* result = 0;
        switch (t->type()) {
            case Token::TYPE_OUTPUT:
                result = readOutputCmd(pos, end);
                break;

            case Token::TYPE_IDENTIFIER:
                result = readAssignCmd(pos, end);
                break;

            case Token::TYPE_IF:
                throw std::runtime_error("If has not been implemented yet");
                break;

            case Token::TYPE_WHILE:
                throw std::runtime_error("While has not been implemented yet");
                break;

            default:
                throw std::runtime_error("Unexpected token");
        }
        return result;
    }

    Command* Parser::readOutputCmd(iter_t& pos, const iter_t& end) {
        // std::cout << "readOutputCmd" << std::endl;
        ++pos;

        iter_t expr_end = find(pos, end, Token::TYPE_SEMICOLON);

        Expression* expr = readExpression(pos, expr_end);

        // skip semicolon
        ++pos;
        return new OutputCommand(expr);
    }

    Command* Parser::readAssignCmd(iter_t& pos, const iter_t& end) {
        // std::cout << "readAssignCmd" << std::endl;
        Token* id = *pos;
        IdentifierToken* casted = dynamic_cast<IdentifierToken*>(id);
        std::string identifier = casted->identifier;

        ++pos; // skip identifier
        Token* assign_operator = *pos;
        if (assign_operator->type() != Token::TYPE_ASSIGN) {
            throw std::runtime_error("Expected command operator");
        }
        ++pos; // skip :=

        iter_t expr_end = find(pos, end, Token::TYPE_SEMICOLON);
        Expression* expr = readExpression(pos, expr_end);

        ++pos; // skip ;

        return new AssignmentCommand(identifier, expr);
    }

    Expression* Parser::readExpression(iter_t& pos, const iter_t& end) {
        // std::cout << "readExpr" << std::endl;
        Token* t = *pos;
        Expression* result = 0;
        while (pos != end) {
            switch (t->type()) {
                case Token::TYPE_NUMBER:
                    result = readNumberExpr(pos, end);
                    break;

                case Token::TYPE_BOOL:
                    result = readBoolExpr(pos, end);
                    break;

                case Token::TYPE_IDENTIFIER:
                    result = readIdExpr(pos, end);
                    break;

                default:
                    // std::cerr << (int) t->type() << std::endl;
                    throw std::runtime_error("Expected expression");
            }
        }
        return result;
    }

    Expression* Parser::readBoolExpr(iter_t& pos, const iter_t& end) {
        // std::cout << "readBool" << std::endl;
        Token* b = *pos;
        BoolToken* casted = dynamic_cast<BoolToken*>(b);
        ++pos;
        return ConstantExpression::fromBoolean(casted->value);
    }

    Expression* Parser::readNumberExpr(iter_t& pos, const iter_t& end) {
        // std::cout << "readNum" << std::endl;
        Token* n = *pos;
        NumberToken* casted = dynamic_cast<NumberToken*>(n);
        ++pos;
        return ConstantExpression::fromNumber(casted->number);
    }

    Expression* Parser::readIdExpr(iter_t& pos, const iter_t& end) {
        // std::cout << "readId" << std::endl;
        Token* id = *pos;
        IdentifierToken* casted = dynamic_cast<IdentifierToken*>(id);
        ++pos;
        return new VariableExpression(casted->identifier);
    }


    Parser::iter_t Parser::find(iter_t& pos, const iter_t& end, char token_type) {
        iter_t result = pos;
        while (result != end) {
            Token* t = *result;
            if (t->type() == token_type) {
                return result;
            }
            ++result;
        }
        throwEof();
        return result;
    }

    void Parser::throwEof() {
        throw std::runtime_error("Unexpected end of input");
    }
};
};
