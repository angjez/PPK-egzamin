#include <iostream>

#include "funkcje.hpp"

void dodajNaKoniec(stGenom * & pHead, double gen)
{
    stGenom * tmp = pHead;
    if(pHead == nullptr){
        pHead = new stGenom {gen, pHead};
        pHead->pNast = pHead;
    }
    else{
        while(tmp->pNast != pHead)
            tmp = tmp->pNast;
        stGenom * nowy = new stGenom {gen, tmp->pNast};
        tmp->pNast = nowy;
        nowy->pNast = pHead;
    }
}

void dodajNaPoczatek (stGenom * & pHead, double gen)
{
    if (pHead == nullptr){
        pHead = new stGenom {gen};
        pHead->pNast = pHead;
    }
    
    else {
        stGenom * ogon = pHead;
        while(ogon->pNast != pHead)
            ogon = ogon->pNast;
        pHead = new stGenom {gen};
        pHead->pNast = ogon->pNast;
        ogon->pNast = pHead;
    }
}

void wypisz (stGenom * pHead)
{
    stGenom * tmp = pHead;
    while(tmp)
    {
        std::cout << tmp->gen << " ";
        //należy przesunąć wskaźnik już na początku funkcji, gdyż w innym przypadku warunek pHead == pierwszy zostanie natychmiast spełniony i zakończy pętlę!
        tmp = tmp->pNast;
        if(tmp == pHead)
            break;
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
    stGenom * pierwszy = pFragment;
    while(pFragment){
        dodajNaPoczatek(pGenom, pFragment->gen);
        pFragment = pFragment->pNast;
        if(pFragment == pierwszy)
            break;
    }
}

stGenom * wytnij (stGenom *& pGenom, int ile)
{
    //najpierw sprawdźmy, czy zadana wielkość do usunięcia nie przekracza całkowitej ilości elementów
    stGenom * tmp = pGenom, * pierwszy = pGenom;
    int i = 0;
    while(tmp)
    {
        i++;
        tmp = tmp->pNast;
        if(tmp == pierwszy)
            break;
    }
    
    stGenom * pFrag = nullptr;
    if(ile<=i) {
        for (int j = 0; j<ile; j++) {
            if(pGenom) {
                stGenom * pNast = pGenom->pNast;
                if(pNast == pierwszy)
                    break;
                dodajNaKoniec(pFrag, pGenom->gen);
                usunElem(pGenom, pGenom);
                pGenom = pNast;
            }
        }
    }
    wypisz(pFrag);
    return pFrag;
}

void znajdzNajlepszaNajgorszaBakterie (stBakteria * pGlowa, stBakteria * & pNajgorsza, stBakteria * pNajlepsza)
{
    
}

void krzyzuj (stBakteria * pGronkowiec, stBakteria * pPaciorkowiec)
{
    
}

void usunElem ( stGenom * & pHead , const stGenom * pDoUsuniecia )
{
    //lista pusta
    if (pHead == NULL)
        return;
    
    // wskaźniki na obecny i poprzedni element potrzebne do znalezienia wartości do usunięcia
    stGenom *pCurr = pHead, *pPrev = nullptr;
    
    while (pCurr != pDoUsuniecia)
    {
        //doszliśmy do końca listy, czyli nie znaleziono podanej wartosci
        if (pCurr->pNast == pHead)
            break;
        
        pPrev = pCurr;
        pCurr = pCurr -> pNast;
    }
    
    //jeśli głowa jest jedyną wartością
    if (pCurr->pNast == pHead)
    {
        pHead = nullptr;
        delete pCurr;
        return;
    }
    
    //jeśli nie, sprawdź, czy jest to pierwszy element
    if (pCurr == pHead)
    {
        pPrev = pHead;
        while (pPrev -> pNast != pHead)
            pPrev = pPrev -> pNast;
        pHead = pCurr->pNast;
        pPrev->pNast = pHead;
        delete pCurr;
    }
    
    //jeśli nie, sprawdź, czy jest to ostatni element
    else if (pCurr -> pNast == pHead)
    {
        pPrev->pNast = pHead;
        delete pCurr;
    }
    
    //jeśli nie, jesteśmy w środku listy i wystarczy zmienić poprzedni na następny i usunąć obecny
    else
    {
        pPrev->pNast = pCurr->pNast;
        delete pCurr;
    }
}
