#pragma once
#include <vector>
#include "parser/Tokenizer.h"
#include "lang/Command.h"
#include "lang/Expression.h"

namespace wfg {
namespace parser {
    class Parser {
        using iter_t = std::vector<Token*>::const_iterator;
    private:
        Command* readCommand(iter_t& pos, const iter_t& end);
        Command* readOutputCmd(iter_t& pos, const iter_t& end);
        Command* readAssignCmd(iter_t& pos, const iter_t& end);

        Expression* readExpression(iter_t& pos, const iter_t& end);
        Expression* readNumberExpr(iter_t& pos, const iter_t& end);
        Expression* readBoolExpr(iter_t& pos, const iter_t& end);
        Expression* readIdExpr(iter_t& pos, const iter_t& end);

        iter_t find(iter_t& from, const iter_t& end, char token_type);
        // void ff(iter_t& from, iter_t& result);

        void throwEof();
    public:
        Parser();
        virtual ~Parser();

        std::vector<lang::Command*> ast(const std::vector<Token*>& tokens);
    };
};
};
