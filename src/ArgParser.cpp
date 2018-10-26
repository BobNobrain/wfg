#include "ArgParser.h"

ArgParser::ArgParser(const int& argc, const char** argv) {
    for (int i = 1; i < argc; i++)
    {
        this->args.push_back(std::string(argv[i]));
    }
}

const std::string& ArgParser::getArgument(const std::string &option) const {
    std::vector<std::string>::const_iterator itr;
    itr = std::find(this->args.begin(), this->args.end(), option);
    if (itr != this->args.end() && ++itr != this->args.end())
    {
        return *itr;
    }
    static const std::string empty_string("");
    return empty_string;
}

bool ArgParser::hasOption(const std::string& option) const {
    return std::find(
        this->args.begin(),
        this->args.end(),
        option
    ) != this->args.end();
}
