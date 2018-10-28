#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace wfg {
    class ArgParser {
    private:
        std::vector<std::string> args;

    public:
        ArgParser(const int& argc, const char** argv);

        const std::string& getArgument(const std::string& option) const;
        const std::string& getArgument(const size_t& index) const;
        bool hasOption(const std::string& option) const;
    };
};
