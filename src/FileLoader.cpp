#include <iostream>
#include <exception>
#include "FileLoader.h"
#include "parser/Tokenizer.h"
#include "parser/Parser.h"
#include "exception/ParserException.h"
#include "interpreter/Interpreter.h"

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
        parser::Tokenizer t;
        parser::Parser p;
        interpreter::Interpreter intprt;
        try {
            t.tokenize(file_content);
            // std::cout << "Tokenized " << t.tokens.size() << std::endl;
            auto commands = p.ast(t.tokens);
            // std::cout << "Parsed " << commands.size() << std::endl;
            intprt.run(commands);
            // std::cout << "Run" << std::endl;

            for (auto it = commands.begin(); it != commands.end(); ++it) {
                Command* next = *it;
                delete next;
            }
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
