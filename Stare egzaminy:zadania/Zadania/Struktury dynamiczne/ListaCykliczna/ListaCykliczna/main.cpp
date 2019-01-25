#include <iostream>

#include "fukncje.hpp"

int main(int argc, const char * argv[]) {
    
    element * pHead = nullptr;
    element * pHead2 = nullptr;
    
    for(int i : {1, 2, 3, 4})
        dodajNaPoczatek(pHead, i);
    

    for(int i : {5, 6, 7 , 8})
        dodajNaPoczatek(pHead2, i);
    
//    polacz(pHead, pHead2);
    
    wypisz(pHead);
    
    usun(pHead);
    
//    wypisz(pHead);
    
    return 0;
}
