#pragma once
#include <string>

namespace wfg {
namespace parser {
    class Token {
    public:
        Token();

        virtual char type();
        virtual bool isKeyword();
        virtual bool isLiteral();
        virtual bool isOperator();

        static const char TYPE_IDENTIFIER = 0x01;

        // keywords
        static const char TYPE_READ          = 0xA0;
        static const char TYPE_OUTPUT        = 0xA1;
        static const char TYPE_IF            = 0xA2;
        static const char TYPE_THEN          = 0xA3;
        static const char TYPE_ELSE          = 0xA4;
        static const char TYPE_WHILE         = 0xA5;
        static const char TYPE_DO            = 0xA6;

        // operators
        static const char TYPE_ASSIGN        = 0xB0;
        static const char TYPE_SEMICOLON     = 0xB1;
        static const char TYPE_PLUS          = 0xB2;
        static const char TYPE_MINUS         = 0xB3;
        static const char TYPE_MULTIPLY      = 0xB4;
        static const char TYPE_DIVIDE        = 0xB5;
        static const char TYPE_EQUALS        = 0xB6;
        static const char TYPE_NOT           = 0xB7;
        static const char TYPE_PAREN         = 0xB8;

        // literals
        static const char TYPE_BOOL          = 0xC1;
        static const char TYPE_NUMBER        = 0xC2;
    };

    class IdentifierToken: public Token {
    public:
        std::string identifier;
        IdentifierToken(const std::string& _id): identifier(_id) {}
        virtual char type() override { return TYPE_IDENTIFIER; }
    };

    // keywords
    class ReadToken: public Token {
    public:
        ReadToken() {}
        virtual char type() override { return TYPE_READ; }
    };
    class OutputToken: public Token {
    public:
        OutputToken() {}
        virtual char type() override { return TYPE_OUTPUT; }
    };
    class IfToken: public Token {
    public:
        IfToken() {}
        virtual char type() override { return TYPE_IF; }
    };
    class ThenToken: public Token {
    public:
        ThenToken() {}
        virtual char type() override { return TYPE_THEN; }
    };
    class ElseToken: public Token {
    public:
        ElseToken() {}
        virtual char type() override { return TYPE_ELSE; }
    };
    class WhileToken: public Token {
    public:
        WhileToken() {}
        virtual char type() override { return TYPE_WHILE; }
    };
    class DoToken: public Token {
    public:
        DoToken() {}
        virtual char type() override { return TYPE_DO; }
    };

    // operators
    class AssignToken: public Token {
    public:
        AssignToken() {}
        virtual char type() override { return TYPE_ASSIGN; }
    };
    class SemicolonToken: public Token {
    public:
        SemicolonToken() {}
        virtual char type() override { return TYPE_SEMICOLON; }
    };
    class PlusToken: public Token {
    public:
        PlusToken() {}
        virtual char type() override { return TYPE_PLUS; }
    };
    class MinusToken: public Token {
    public:
        MinusToken() {}
        virtual char type() override { return TYPE_MINUS; }
    };
    class MultiplyToken: public Token {
    public:
        MultiplyToken() {}
        virtual char type() override { return TYPE_MULTIPLY; }
    };
    class DivideToken: public Token {
    public:
        DivideToken() {}
        virtual char type() override { return TYPE_DIVIDE; }
    };
    class EqualsToken: public Token {
    public:
        EqualsToken() {}
        virtual char type() override { return TYPE_EQUALS; }
    };
    class NotToken: public Token {
    public:
        NotToken() {}
        virtual char type() override { return TYPE_NOT; }
    };
    class ParenToken: public Token {
    public:
        bool opening;
        ParenToken(bool type): opening(type) {}
        virtual char type() override { return TYPE_PAREN; }

        static const bool OPENING = true;
        static const bool CLOSING = false;
    };

    // literals
    class NumberToken: public Token {
    public:
        float number;
        NumberToken() {}
        virtual char type() override { return TYPE_NUMBER; }
    };
    class BoolToken: public Token {
    public:
        bool number;
        BoolToken() {}
        virtual char type() override { return TYPE_BOOL; }
    };
};
};
