#include <iostream>

#include "funkcje.hpp"

int main(int argc, const char * argv[]) {
    if (szachownicaPoprawna("dane.txt"))
        std::cout << "Dobre" << std::endl;
    else
        std::cout << "Zle" << std::endl;
    return 0;
}
