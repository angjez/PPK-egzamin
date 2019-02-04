#ifndef funkcje_hpp
#define funkcje_hpp

#include <stdio.h>
#include <string>
#include <iostream>

struct Zadanie
{
    int priotytet;
    std::string tresc_zadania;
    Zadanie * pLewy, * pPrawy;
};

struct Pracownik
{
    std::string nazwisko;
    Pracownik * pPrev , * pNext;
    Zadanie * pZadania ;
};

Pracownik * znajdzLubDodajPracownika(Pracownik * & pHead, Pracownik * & pTail, const std::string & nazwisko);
void dodajZadanie (Zadanie * & pRoot, const int & priorytet, const std::string & tresc);
void dodajZadaniePracownikowi(Pracownik * & pHead, Pracownik * & pTail, const int & priorytet, const std::string & tresc, const std::string & nazwisko);
void usunPracownikowBezZadan(Pracownik * & pHead, Pracownik * & pTail);
void odwrocKolejnoscPracownikow(Pracownik * & pHead, Pracownik * & pTail);

void wypisz(Pracownik * pHead);
void wypiszPracownikow (Pracownik * pHead);
void wypiszZadania (Zadanie * pRoot);

void usunDrzewo (Zadanie * & pRoot);
void usun (Pracownik * & pHead);

#endif /* funkcje_hpp */
