#include <iostream>

#include "funkcje.hpp"

void dodajIteracyjnieDoListyPosortowanej ( element * & pHead , T liczba )
{
    element * pCurrent = pHead;
    //brak elementów lub element do dodania mniejszy od głowy
    if (pHead == nullptr || pHead->wartosc >= liczba)
        pHead = new element {liczba, pHead};
    else
    {
        while (pCurrent->pNext != nullptr && pCurrent->pNext->wartosc < liczba)
            pCurrent = pCurrent->pNext;
        element * nowy = new element {liczba, pCurrent->pNext};
        pCurrent->pNext = nowy;
    }
}

void dodajRekurencyjnieDoListyPosortowanej ( element * & pHead , T liczba )
{

}

element * znajdzElementIteracyjnie ( element * pHead , T liczba )
{
    while(pHead)
    {
        if(pHead->wartosc == liczba)
            return pHead;
        pHead = pHead -> pNext;
    }
    return nullptr;
}

element * znajdzElementRekurencyjnie ( element * pHead , T liczba )
{
    if (pHead == nullptr)
        return nullptr;

    if (pHead->wartosc == liczba)
        return pHead;
    
    return znajdzElementRekurencyjnie(pHead->pNext, liczba);
}

void odwrocListe (element * & pHead)
{
    element * pCurr = pHead, * pPrev = nullptr, * pForw = nullptr;
    
    while (pCurr != nullptr)
    {
        pForw = pCurr->pNext;
        
        // zamiana wskaźnika obecnego elementu
        pCurr->pNext = pPrev;
        
        // przesunięcie wskaźników o pozycję do przodu
        pPrev = pCurr;
        pCurr = pForw;
    }
    pHead = pPrev;
}

void odwrocListeRek (element * & pHead)
{
    //lista pusta lub ma tylko jeden element
    if (pHead == nullptr || pHead->pNext == nullptr)
        return;
    
    struct element * pFirst = pHead, * pRest = pFirst->pNext;
    
    //ostatni element staje się pierwszym (funkcja wywołuje się, aż dojdziemy do końca listy)
    odwrocListeRek(pRest);
    //odwracamy wskaźniki
    pFirst->pNext->pNext  = pFirst;
    
    //stara głowa teraz jest końcem listy, więc wskazuje na nullptr
    pFirst->pNext  = nullptr;
    
    //głowa teraz jest końcem, trzeba to zrobić, aby móc ponownie wywołać funkcję
    pHead = pRest;
}

element * sumaMnogosciowa ( element * pH1 , element * pH2 )
{
    element * sumaMnogosciowa = nullptr;
    while(pH1)
    {
        dodajIteracyjnieDoListyPosortowanej(sumaMnogosciowa, pH1->wartosc);
        pH1 = pH1->pNext;
    }
    while(pH2)
    {
        dodajIteracyjnieDoListyPosortowanej(sumaMnogosciowa, pH2->wartosc);
        pH2 = pH2->pNext;
    }
    usunPowtorzenia(sumaMnogosciowa);
    return sumaMnogosciowa;
}

element * iloczynMnogosciowy ( element * pH1 , element * pH2 )
{
    element * iloczynMnogosciowy = nullptr;
    while(pH1) {
        element * tmp = pH2;
        while(tmp) {
            if(pH1->wartosc == tmp ->wartosc)
                dodajIteracyjnieDoListyPosortowanej(iloczynMnogosciowy, pH1->wartosc);
            tmp = tmp -> pNext;
        }
        pH1 = pH1 -> pNext;
    }
    usunPowtorzenia(iloczynMnogosciowy);
    return iloczynMnogosciowy;
}

element * roznicaMnogosciowa ( element * pH1 , element * pH2 )
{
    element * roznicaMnogosciowa = nullptr, * pTmp = pH1;
    while(pTmp)
    {
         dodajIteracyjnieDoListyPosortowanej(roznicaMnogosciowa, pTmp->wartosc);
        pTmp = pTmp->pNext;
    }
    
    while(pH1) {
        element * tmp = pH2;
        while(tmp) {
            if(pH1->wartosc == tmp ->wartosc)
                usunElementy(roznicaMnogosciowa, pH1->wartosc);
            tmp = tmp -> pNext;
        }
        pH1 = pH1 -> pNext;
    }
    usunPowtorzenia(roznicaMnogosciowa);
    return roznicaMnogosciowa;
}

element * scalListyPosortowane ( element * & pH1 , element * & pH2 )
{
    element * scaloneListy = nullptr;
    
    if (pH1 == nullptr)
        return (pH1);
    else if (pH2 == nullptr)
        return (pH2);
    
    /* Pick either a or b, and recur */
    if (pH1->wartosc <= pH2->wartosc) {
        scaloneListy = pH1;
        scaloneListy->pNext = scalListyPosortowane(pH1->pNext, pH2);
    }
    else {
        scaloneListy = pH2;
        scaloneListy->pNext = scalListyPosortowane(pH1, pH2->pNext);
    }
    return scaloneListy;
}

void usunPowtorzenia (element * & pHead)
{
    element * pTmp1 = pHead, * pTmp2, * pDuplikat;
    
    while (pTmp1 != nullptr && pTmp1->pNext != nullptr)
    {
        pTmp2 = pTmp1;
        while (pTmp2->pNext)
        {
            if (pTmp1->wartosc == pTmp2->pNext->wartosc)
            {
                pDuplikat = pTmp2->pNext;
                pTmp2->pNext = pTmp2->pNext->pNext;
                delete pDuplikat;
            }
            else
                pTmp2 = pTmp2->pNext;
        }
        pTmp1 = pTmp1->pNext;
    }
}

void usunElement (element * & pHead , element * pDoUsuniecia)
{
    element * pTmp = pHead, * pPrev = nullptr;
    if (pTmp != nullptr && pTmp == pDoUsuniecia)
    {
        pHead = pTmp->pNext;
        delete pTmp;
        return;
    }
    
    while (pTmp != nullptr && pTmp != pDoUsuniecia)
    {
        pPrev = pTmp;
        pTmp = pTmp->pNext;
    }
    
    //nie znaleziono elementu
    if (pTmp == nullptr)
        return;
    
    pPrev->pNext = pTmp->pNext;
    delete pTmp;
}

void usunElement ( element * & pHead , T wartosc )
{
    element * pTmp = pHead, * pPrev = nullptr;
    if (pTmp != nullptr && pTmp->wartosc == wartosc)
    {
        pHead = pTmp->pNext;
        delete pTmp;
        return;
    }
    
    while (pTmp != nullptr && pTmp->wartosc != wartosc)
    {
        pPrev = pTmp;
        pTmp = pTmp->pNext;
    }
    
    //nie znaleziono elementu
    if (pTmp == nullptr)
        return;
    
    pPrev->pNext = pTmp->pNext;
    delete pTmp;
}

void usunElementy ( element * & pHead , T wartosc )
{
    element * pCurr = pHead, * pPrev = nullptr;

    //szukana wartość to głowa
    while (pCurr != nullptr && pCurr->wartosc == wartosc)
    {
        pHead = pCurr->pNext;
        delete pCurr;
        pCurr = pHead;
    }
    
    while (pCurr != nullptr)
    {
        while (pCurr != nullptr && pCurr->wartosc != wartosc)
        {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }

        //nie znaleziono wartosci
        if (pCurr == nullptr)
            return;

        pPrev->pNext = pCurr->pNext;
        delete pCurr;
        pCurr = pPrev->pNext;
    }
}

void usunParzyste (element * & pHead)
{
    element * pCurr = pHead, * pPrev = nullptr;
    
    while (pCurr != nullptr && ((pCurr->wartosc % 2) == 0))
    {
        pHead = pCurr->pNext;
        delete pCurr;
        pCurr = pHead;
    }
    
    while (pCurr != nullptr)
    {
        while (pCurr != nullptr && ((pCurr->wartosc % 2) != 0))
        {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }
        
        //nie znaleziono wartosci
        if (pCurr == nullptr)
            return;
        
        pPrev->pNext = pCurr->pNext;
        delete pCurr;
        pCurr = pPrev->pNext;
    }
}

void usunOstatni (element * & pHead)
{
    element * pTmp = pHead, * pPrev = nullptr;
    //brak elementów w liście
    if(pHead == nullptr)
        return;
    //lista ma tylko jeden element - głowę
    if(pHead -> pNext == nullptr){
        pHead = pTmp->pNext;
        delete pTmp;
        pTmp = pHead;
        return;
    }
    //lista ma więcej elementów
    while (pTmp->pNext != nullptr)
    {
        pPrev = pTmp;
        pTmp = pTmp->pNext;
    }
    pPrev->pNext = pTmp->pNext;
    delete pTmp;
}

void wypisz (element * pHead)
{
    while(pHead)
    {
        std::cout << pHead->wartosc << " ";
        pHead = pHead->pNext;
    }
    std::cout << std::endl;
}
