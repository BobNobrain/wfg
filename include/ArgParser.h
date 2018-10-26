#pragma once
#include <string>
#include <vector>
#include <algorithm>

class ArgParser {
private:
    std::vector<std::string> args;

public:
    ArgParser(const int& argc, const char** argv);

    const std::string& getArgument(const std::string& option) const;
    bool hasOption(const std::string& option) const;
};
