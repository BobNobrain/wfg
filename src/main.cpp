#include <iostream>

#ifndef PROGRAM_VERSION
#define PROGRAM_VERSION "Unknown"
#endif

int main(int argc, char const *argv[])
{
    std::cout << PROGRAM_VERSION << std::endl;
    return 0;
}
