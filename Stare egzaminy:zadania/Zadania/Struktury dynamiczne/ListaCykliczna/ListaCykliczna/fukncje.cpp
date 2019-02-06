#include <iostream>

#include "fukncje.hpp"

void dodajNaPoczatek ( element * & pHead , const T & wartosc )
{
    if (pHead == nullptr){
        pHead = new element {wartosc};
        pHead->pNext = pHead;
    }
    
    else {
        element * ogon = pHead;
        while(ogon->pNext != pHead /*&& ogon->pNext != nullptr*/)
            ogon = ogon->pNext;
        pHead = new element {wartosc};
        pHead->pNext = ogon->pNext;
        ogon->pNext = pHead;
    }
}

void wypisz ( element * pHead )
{
    element * pierwszy = pHead;
    while(pHead)
    {
        std::cout << pHead->wartosc << " ";
        pHead = pHead->pNext;
        if(pHead == pierwszy)
            break;
    }
    std::cout << std::endl;
}

int zliczElementy ( element * pHead )
{
    int i=0;
    element * pierwszy = pHead;
    while(pHead)
    {
        i++;
        pHead = pHead->pNext;
        if(pHead == pierwszy)
            break;
    }
    return i;
}

void usunElem ( element * & pHead , const T & wartosc )
{
//    //lista pusta
//    if (pHead == NULL)
//        return;
//
//    element *pCurr = pHead;
//    while (pCurr->wartosc != wartosc)
//    {
//        //doszliśmy do końca listy, czyli nie znaleziono podanej wartosci
//        if (pCurr->pNext == pHead)
//            break;
//
//        pCurr = pCurr -> pNext;
//    }
//
//    usunElem(pHead, pCurr);
    if(pHead == nullptr)
        return;
    
    element * tmp = pHead;
    while(tmp->pNext != pHead) {
        if(tmp->pNext->wartosc == wartosc) {
            tmp->pNext = tmp->pNext->pNext;
            delete tmp->pNext;
            break;
        }
        else
            tmp = tmp->pNext;
    }
}

void usunWszystkie ( element * & pHead , const T & wartosc )
{
    if (pHead == nullptr)
        return;
    
    element *pCurr = pHead, *pPrev = nullptr;
    while (pCurr->pNext != pHead)
    {
        if(pCurr->wartosc == wartosc) {
            pPrev->pNext = pCurr->pNext;
            delete pCurr;
            pCurr = pPrev->pNext;
        }
        else {
            pPrev = pCurr;
            pCurr = pCurr -> pNext;
        }
    }
}

void usunElem ( element * & pHead , const element * pDoUsuniecia )
{
    //lista pusta
    if (pHead == NULL)
        return;
    
    // wskaźniki na obecny i poprzedni element potrzebne do znalezienia wartości do usunięcia
    element *pCurr = pHead, *pPrev = nullptr;
    
    while (pCurr != pDoUsuniecia)
    {
        //doszliśmy do końca listy, czyli nie znaleziono podanej wartosci
        if (pCurr->pNext == pHead)
            break;
        
        pPrev = pCurr;
        pCurr = pCurr -> pNext;
    }
    
    //jeśli głowa jest jedyną wartością
    if (pCurr->pNext == pHead)
    {
        pHead = nullptr;
        delete pCurr;
        return;
    }
    
    //jeśli nie, sprawdź, czy jest to pierwszy element
    if (pCurr == pHead)
    {
        pPrev = pHead;
        while (pPrev -> pNext != pHead)
            pPrev = pPrev -> pNext;
        pHead = pCurr->pNext;
        pPrev->pNext = pHead;
        delete pCurr;
    }
    
    //jeśli nie, sprawdź, czy jest to ostatni element
    else if (pCurr -> pNext == pHead)
    {
        pPrev->pNext = pHead;
        delete pCurr;
    }
    
    //jeśli nie, jesteśmy w środku listy i wystarczy zmienić poprzedni na następny i usunąć obecny
    else
    {
        pPrev->pNext = pCurr->pNext;
        delete pCurr;
    }
}

void usun ( element * & pHead )
{
    element * pTmp = pHead;
    while(pTmp)
    {
        element * pNastepnik = pTmp->pNext;
        //jeżeli dotrzemy do końca listy
        if(pNastepnik == pHead){
            pHead = nullptr;
            delete pTmp;
            return;
        }
        delete pTmp;
        pTmp = pNastepnik;
    }
}

void polacz (element * & pH1, element * & pH2)
{
    element * tmp = pH2;
    while(tmp){
        dodajNaPoczatek(pH1, tmp->wartosc);
        tmp = tmp->pNext;
    }
    usun(pH2);
}
