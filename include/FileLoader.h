#pragma once
#include <string>

namespace wfg {
    class FileLoader {
    private:
        std::string file_content;
    protected:
        int run();
    public:
        FileLoader();
        ~FileLoader();

        int start(const std::string& filename);
    };
};
