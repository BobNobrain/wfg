#include <iostream>
#include <exception>
#include "FileLoader.h"
#include "parser/Parser.h"
#include "exception/ParserException.h"

namespace wfg {
    FileLoader::FileLoader() {}
    FileLoader::~FileLoader() {}

    int FileLoader::start(const std::string& filename) {
        std::cout << "Opening " << filename << std::endl;
        // TODO
        file_content = "var := 1; output var;";

        return run();
    }

    int FileLoader::run() {
        parser::Parser p;
        try {
            p.tokenize(file_content);
        } catch (const std::runtime_error& err) {
            std::cerr << "Parsing error: " << err.what() << std::endl;
            return 50;
        } catch (const parser::ParserException& err) {
            std::cerr << "Parsing error: " << err.what() << std::endl;
            std::cerr << err.show() << std::endl;
            return 40;
        }

        return 0;
    }
};
