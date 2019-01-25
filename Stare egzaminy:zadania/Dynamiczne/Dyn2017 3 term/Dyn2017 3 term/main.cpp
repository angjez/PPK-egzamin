#include <iostream>

#include "funkcje.hpp"

int main(int argc, const char * argv[]) {
    
    stGenom * pFragment = nullptr;
    stGenom * pGenom = nullptr;
    
    for(double i : {1, 2, 3, 4, 5, 6})
        dodajNaKoniec(pGenom, i);
    for(double i : {7, 8, 9})
        dodajNaKoniec(pFragment, i);
    
    wypisz(pFragment);
    wypisz(pGenom);
    
    dodajFragment(pGenom, pFragment);
    
    wypisz(pFragment);
    wypisz(pGenom);
    
    return 0;
}
