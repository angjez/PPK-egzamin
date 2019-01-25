#include <iostream>

#include "funkcje.hpp"

void dodajNaKoniec(stGenom * & pHead, double gen)
{
    if (not pHead) // lista pusta
        pHead = new stGenom { gen, nullptr };
    else // jestesmy gdzieś w środku listy
        dodajNaKoniec(pHead->pNast, gen);
}

void dodajNaPoczatek (stGenom * & pHead, double gen)
{
    pHead = new stGenom {gen, pHead};
}

void wypisz (stGenom * pHead)
{
    while(pHead){
        std::cout << pHead->gen << " ";
        pHead = pHead->pNast;
    }
    std::cout << std::endl;
}

void usun (stGenom * & pHead)
{
    while(pHead)
    {
        stGenom * pNastepnik = pHead->pNast;
        delete pHead;
        pHead = pNastepnik;
    }
}

void dodajFragment (stGenom *& pGenom, stGenom * pFragment)
{
    stGenom * tmp = pFragment;
    while(tmp){
        dodajNaPoczatek(pGenom, tmp->gen);
        tmp = tmp->pNast;
    }
}

stGenom * wytnij (stGenom *& pGenom, int ile)
{
    
}

void znajdzNajlepszaNajgorszaBakterie (stBakteria * pGlowa, stBakteria * & pNajgorsza, stBakteria * pNajlepsza)
{
    
}

void krzyzuj (stBakteria * pGronkowiec, stBakteria * pPaciorkowiec)
{
    
}
