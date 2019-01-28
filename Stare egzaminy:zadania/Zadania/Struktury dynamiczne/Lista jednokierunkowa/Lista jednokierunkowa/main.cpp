#include <iostream>

#include "funkcje.hpp"

int main(int argc, const char * argv[]) {
    
    element * pHead = nullptr;
    element * pHead2 = nullptr;
    
    for(int i : {1, 2, 3, 4, 5, 6})
        dodajIteracyjnieDoListyPosortowanej(pHead, i);
    
    for(int i : {0, 2, 5, 9, 8, 0, 0, 0})
        dodajIteracyjnieDoListyPosortowanej(pHead2, i);

    wypisz(pHead2);
    wypisz(pHead);
    wypisz(roznicaMnogosciowa(pHead, pHead2));
    usunParzyste(pHead2);
    wypisz(pHead2);
    return 0;
}
