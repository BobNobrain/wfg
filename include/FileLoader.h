#pragma once
#include <string>

namespace wfg {
    class FileLoader {
    public:
        FileLoader();
        ~FileLoader();

        int start(const std::string& filename);
    };
};
