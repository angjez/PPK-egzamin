#ifndef funkcje_hpp
#define funkcje_hpp

#include <string>

#include <stdio.h>

struct stGenom
{
    double gen;
    stGenom * pNast;
};

struct stBakteria
{
    std::string nazwa;
    stBakteria * pNast;
    stGenom * pGenom;
};

//funkcje do zrobienia w ramach zadania
void dodajFragment (stGenom *& pGenom, stGenom * pFragment);
stGenom * wytnij (stGenom *& pGenom, int ile);
void znajdzNajlepszaNajgorszaBakterie (stBakteria * pGlowa, stBakteria * & pNajgorsza, stBakteria * pNajlepsza);
void krzyzuj (stBakteria * pGronkowiec, stBakteria * pPaciorkowiec);

//dodatkowe zdefiniowane funkcje
void dodajNaKoniec(stGenom * & pHead, double gen);
void dodajNaPoczatek (stGenom * & pHead, double gen);
void wypisz (stGenom * pHead);
void usun (stGenom * & pHead);

#endif /* funkcje_hpp */
