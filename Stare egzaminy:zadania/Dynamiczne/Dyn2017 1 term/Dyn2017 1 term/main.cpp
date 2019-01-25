#include <iostream>

#include "funkcje.hpp"

int main(int argc, const char * argv[]) {
    
    Zadanie * pRoot = nullptr;
    Pracownik * pTail = nullptr , * pHead = nullptr;
    Pracownik * test = nullptr;
    
    znajdzLubDodajPracownika(pHead, "Dzikowska");
    znajdzLubDodajPracownika(pHead, "Armak");
    znajdzLubDodajPracownika(pHead, "Lisiewicz");
    
    
//    dodajZadaniePracownikowi(pHead, 5, "zadanie1", "Armak");
//    dodajZadaniePracownikowi(pHead, 10, "zadanie2", "Armak");
//    dodajZadaniePracownikowi(pHead, 12, "zadanie3", "Armak");
//
    dodajZadaniePracownikowi(pHead, 7, "zadanie1", "Kuna");
//    dodajZadaniePracownikowi(pHead, 15, "zadanie1", "Kuna");
    
    wypisz(pHead);
    
    usun(pHead);
    return 0;
}
