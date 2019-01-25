#ifndef funkcje_hpp
#define funkcje_hpp

#include <stdio.h>
#include <string>

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

Pracownik * znajdzLubDodajPracownika(Pracownik * & pHead, const std::string & nazwisko);
void dodajZadanie (Zadanie * pRoot, const int & priorytet, const std::string & tresc);
void dodajZadaniePracownikowi(Pracownik * pHead, const int & priorytet, const std::string & tresc, const std::string & nazwisko);
void usunPracownikowBezZadan();
void odwrocKolejnoscPracownikow();

void wypisz(Pracownik * pHead);
void wypiszPracownikow (Pracownik * pHead);
void wypiszZadania (Zadanie * pRoot);

void usunDrzewo (Zadanie * & pRoot);
void usun (Pracownik * & pHead);

#endif /* funkcje_hpp */
