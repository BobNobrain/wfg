#pragma once
#include <exception>
#include <string>

namespace wfg {
namespace parser {
    class ParserException: public std::exception {
    private:
        int col;
        int line;
        std::string expected;
        std::string got;
    public:
        ParserException(
            const int& _col,
            const int& _line,
            const std::string& _expected,
            const std::string& _got
        )
            : col(_col)
            , line(_line)
            , expected(_expected)
            , got(_got)
        {}

        virtual const char* what() const noexcept override;
        virtual const std::string show() const noexcept;
    };
};
};
