#include <iostream>

#include "funkcje.hpp"

int main(int argc, const char * argv[]) {
    
    element * pHead = nullptr;
    element * pHead2 = nullptr;
    
    for(int i : {5, 5, 5, 5, 5})
        dodajIteracyjnieDoListyPosortowanej(pHead, i);
    
    for(int i : {0, 2, 5, 9, 8, 0, 0, 0})
        dodajRekurencyjnieDoListyPosortowanej(pHead2, i);

    wypisz(pHead2);
//    usunPowtorzenia(pHead);
    wypisz(pHead);
//    wypisz(scalListyPosortowane(pHead, pHead2));
    return 0;
}
