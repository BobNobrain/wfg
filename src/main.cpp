#include <iostream>
#include "ArgParser.h"
#include "FileLoader.h"
#include "help.cpp"

int main(int argc, char const *argv[])
{
    ArgParser parser(argc, argv);
    if (parser.hasOption("-v") || parser.hasOption("--version")) {
        std::cout << PROGRAM_VERSION << std::endl;
        return 0;
    }

    if (parser.hasOption("-h") || parser.hasOption("--help")) {
        help_message();
        return 0;
    }

    if (argc != 2) {
        std::cout << "[ERROR]: no input file, type wfg --help to show usage" << std::endl;
        return 1;
    }

    // TODO
    wfg::FileLoader loader;
    return loader.start("../example.wfg");
}
