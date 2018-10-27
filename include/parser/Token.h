#pragma once
#include <string>


namespace wfg {
namespace parser {
    class Token {
    public:
        Token();
        virtual ~Token() {}

        virtual char type() const;
        virtual bool isKeyword();
        virtual bool isLiteral();
        virtual bool isOperator();

        static const char TYPE_UNKNOWN = 0x00;
        static const char TYPE_IDENTIFIER = 0x01;

        // keywords
        static const char TYPE_READ          = 0xA0;
        static const char TYPE_OUTPUT        = 0xA1;
        static const char TYPE_IF            = 0xA2;
        static const char TYPE_THEN          = 0xA3;
        static const char TYPE_ELSE          = 0xA4;
        static const char TYPE_WHILE         = 0xA5;
        static const char TYPE_DO            = 0xA6;
        static const char TYPE_NOT           = 0xA7;
        static const char TYPE_OR            = 0xA8;
        static const char TYPE_AND           = 0xA9;

        // operators
        static const char TYPE_ASSIGN        = 0xB0;
        static const char TYPE_SEMICOLON     = 0xB1;
        static const char TYPE_PLUS          = 0xB2;
        static const char TYPE_MINUS         = 0xB3;
        static const char TYPE_MULTIPLY      = 0xB4;
        static const char TYPE_DIVIDE        = 0xB5;
        static const char TYPE_EQUALS        = 0xB6;
        static const char TYPE_PAREN         = 0xB7;
        static const char TYPE_GT            = 0xB8;
        static const char TYPE_LT            = 0xB9;
        static const char TYPE_GE            = 0xBA;
        static const char TYPE_LE            = 0xBB;

        // literals
        static const char TYPE_BOOL          = 0xC1;
        static const char TYPE_NUMBER        = 0xC2;
    };

    class IdentifierToken: public Token {
    public:
        std::string identifier;
        IdentifierToken(const std::string& _id): identifier(_id) {}
        virtual char type() const override { return TYPE_IDENTIFIER; }
        virtual ~IdentifierToken() override {}
    };

    // keywords
    class KeywordToken: public Token {
    private:
        std::string keyword;
        char _type;
    public:
        KeywordToken(const std::string& kw): keyword(kw), _type(TYPE_UNKNOWN) {
            if (kw == "if") _type = TYPE_IF;
            if (kw == "then") _type = TYPE_THEN;
            if (kw == "else") _type = TYPE_ELSE;
            if (kw == "while") _type = TYPE_WHILE;
            if (kw == "do") _type = TYPE_DO;
            if (kw == "not") _type = TYPE_NOT;
            if (kw == "read") _type = TYPE_READ;
            if (kw == "output") _type = TYPE_OUTPUT;
            if (kw == "or") _type = TYPE_OR;
            if (kw == "and") _type = TYPE_AND;
        }
        virtual char type() const override { return _type; }
        virtual ~KeywordToken() override {}
    };

    // operators
    class OperatorToken: public Token {
    private:
        std::string opr;
        char _type;
    public:
        OperatorToken(const std::string& op): opr(op), _type(TYPE_UNKNOWN) {
            if (op == "+") _type = TYPE_PLUS;
            if (op == "-") _type = TYPE_MINUS;
            if (op == "*") _type = TYPE_MULTIPLY;
            if (op == "/") _type = TYPE_DIVIDE;
            if (op == ";") _type = TYPE_SEMICOLON;
            if (op == ":=") _type = TYPE_ASSIGN;
            if (op == "=") _type = TYPE_EQUALS;
            if (op == ">") _type = TYPE_GT;
            if (op == "<") _type = TYPE_LT;
            if (op == ">=") _type = TYPE_GE;
            if (op == "<=") _type = TYPE_LE;
        }
        virtual char type() const override { return _type; }
        virtual ~OperatorToken() override {}
    };
    class ParenToken: public Token {
    public:
        bool opening;
        ParenToken(bool type): opening(type) {}
        virtual char type() const override { return TYPE_PAREN; }
        virtual ~ParenToken() override {}

        static const bool OPENING = true;
        static const bool CLOSING = false;
    };

    // literals
    class NumberToken: public Token {
    public:
        float number;
        NumberToken(float n): number(n) {}
        virtual char type()const  override { return TYPE_NUMBER; }
        virtual ~NumberToken() override {}
    };
    class BoolToken: public Token {
    public:
        bool value;
        BoolToken(bool b): value(b) {}
        virtual char type() const override { return TYPE_BOOL; }
        virtual ~BoolToken() override {}
    };
};
};
