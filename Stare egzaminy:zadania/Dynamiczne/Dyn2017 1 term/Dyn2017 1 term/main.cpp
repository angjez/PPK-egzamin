#include <iostream>

#include "funkcje.hpp"

int main(int argc, const char * argv[]) {
    
    Zadanie * pRoot = nullptr;
    Pracownik * pTail = nullptr , * pHead = nullptr;
    
    znajdzLubDodajPracownika(pHead, pTail, "Dzikowska");
    znajdzLubDodajPracownika(pHead, pTail, "Armak");
    znajdzLubDodajPracownika(pHead, pTail, "Lisiewicz");
    znajdzLubDodajPracownika(pHead, pTail, "Suseł");
    znajdzLubDodajPracownika(pHead, pTail, "Armak");
    znajdzLubDodajPracownika(pHead, pTail, "Lisiewicz");
    
    
    dodajZadaniePracownikowi(pHead, pTail, 5, "zadanie1", "Armak");
    dodajZadaniePracownikowi(pHead, pTail, 10, "zadanie2", "Armak");
    dodajZadaniePracownikowi(pHead, pTail, 12, "zadanie3", "Armak");

    dodajZadaniePracownikowi(pHead, pTail, 7, "zadanie1", "Kuna");
    dodajZadaniePracownikowi(pHead, pTail, 15, "zadanie1", "Bażant");
    
//    usunPracownikowBezZadan(pHead, pTail);
    
    odwrocKolejnoscPracownikow(pHead, pTail);
    
    wypisz(pHead);
    
    usun(pHead);
    return 0;
}
