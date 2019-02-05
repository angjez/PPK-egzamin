#include <iostream>

#include "funkcje.hpp"

int main(int argc, const char * argv[]) {
    
    element * pHead = nullptr;
    element * pTail = nullptr;
    
    element * pHeadWyj = nullptr;
    element * pTailWyj = nullptr;
    
//    for (int i : { 1, 0, 6, 3 } )
//        dodajNaPoczatek(pHead, pTail, i);
    for (int i : { 3, 6, 0, 9, 1, 5, 9 } )
        dodajNaKoniec(pHead, pTail, i);
    
//    wypiszListe(pHead, pTail);
    
//    posortujListe(pHead, pTail);
    
    wypiszListe(pHead, pTail);
    
//    dodajDoListyPosortowanej(pHead, pTail, 9);
//    dodajDoListyPosortowanej(pHead, pTail, 7);
//    dodajDoListyPosortowanej(pHead, pTail, 11);
    
    usunElementy(pHead, pTail, 9);
    
//    przesunListe(pHead, pTail);
//    odwrocListe(pHead, pTail);
    
//    przenies(pHead, pTail, 1, pHeadWyj, pTailWyj);
    
    wypiszListe(pHead, pTail);
//    wypiszListe(pHeadWyj, pTailWyj);
    
    usunListe(pHead, pTail);
    
    return 0;
}
