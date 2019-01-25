#include <string>
#include <fstream>
#include <iostream>

#include "funkcje.hpp"

bool szachownicaPoprawna (std::string nazwaPliku)
{
    std::string szachownica [7][7];
    std::ifstream plik (nazwaPliku);
    if(plik) {
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
                while(plik >> szachownica[i][j]){
                        std::cout << szachownica[i][j] << std::endl;
                }
    }
    plik.close();
    
    return true;
}
