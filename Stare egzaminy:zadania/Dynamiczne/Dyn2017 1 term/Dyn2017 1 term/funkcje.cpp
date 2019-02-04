#include "funkcje.hpp"

Pracownik * znajdzLubDodajPracownika(Pracownik * & pHead, Pracownik * & pTail, const std::string & nazwisko)
{
    Pracownik * szukaj = pHead;
    while(szukaj) {
        if(szukaj->nazwisko == nazwisko)
            return szukaj;
        else
            szukaj = szukaj -> pNext;
    }
    
    if(pHead == nullptr) {
        pHead = new Pracownik {nazwisko, nullptr, pHead};
        pTail = pHead;
        return pHead;
    }
    
    else if(pHead->nazwisko >= nazwisko) {
        pHead = new Pracownik {nazwisko, nullptr, pHead};
        pHead->pNext->pPrev = pHead;
        return pHead;
    }
    else {
        Pracownik * tmp = pHead;
        while (tmp->pNext != nullptr && tmp->nazwisko < nazwisko)
            tmp = tmp->pNext;
    
        if (tmp->pNext == nullptr){
            tmp = new Pracownik {nazwisko, tmp, nullptr};
            tmp->pPrev->pNext = tmp;
            return tmp;
        }
        Pracownik * nowy = new Pracownik {nazwisko, tmp, tmp->pNext};
        tmp->pNext = nowy;
        tmp->pNext->pPrev = nowy;
        return nowy;
    }
}

void dodajZadanie (Zadanie * & pRoot, const int & priorytet, const std::string & tresc)
{
    if (not pRoot)
        pRoot = new Zadanie { priorytet, tresc, 0, 0 };
    else // w drzewie juz cos jest
    {
        auto p = pRoot;
        
        while (p)
        {
            if (priorytet < p->priotytet) // idziemy w lewo
            {
                if (p->pLewy)  // jezeli istnieje pLewy
                    p = p->pLewy;
                else
                {
                    p->pLewy = new Zadanie { priorytet, tresc, 0, 0 };
                    break;
                }
            }
            else  // idziemy w prawo
            {
                if (p->pPrawy)
                    p = p->pPrawy;
                else
                {
                    p->pPrawy = new Zadanie { priorytet, tresc, 0, 0 };
                    break;
                }
            }
        }
    }
}

void dodajZadaniePracownikowi(Pracownik * & pHead, Pracownik * & pTail, const int & priorytet, const std::string & tresc, const std::string & nazwisko)
{
    dodajZadanie(znajdzLubDodajPracownika(pHead, pTail, nazwisko)->pZadania, priorytet, tresc);
}

void usunPracownikowBezZadan(Pracownik * & pHead, Pracownik * & pTail)
{
    Pracownik * tmp = pHead, * prev = nullptr;
    while(tmp) {
        if (tmp->pZadania == nullptr) {
            if(tmp->pPrev == nullptr) {
                tmp->pNext = pHead;
                pHead->pPrev = nullptr;\
                delete tmp;
            }
            else if (tmp->pNext == nullptr) {
                tmp->pPrev = pTail;
                pTail->pNext = nullptr;
                delete tmp;
            }
            else {
                prev->pNext = tmp->pNext;
                tmp->pNext->pPrev = prev;
                delete tmp;
            }
        }
        else
            prev = tmp;
            tmp = tmp -> pNext;
    }
}

void odwrocKolejnoscPracownikow(Pracownik * & pHead, Pracownik * & pTail)
{
    for(Pracownik * tmp = pHead; tmp->pNext != nullptr; tmp = tmp->pNext)
    {
        for(Pracownik * tmp2 = tmp->pNext; tmp2 != nullptr; tmp2 = tmp2->pNext){
            std::swap (tmp->pZadania, tmp2->pZadania);
            std::swap (tmp->nazwisko, tmp2->nazwisko);
        }
    }
}

void wypisz(Pracownik * pHead)
{
    while (pHead)
    {
        std::cout << pHead->nazwisko << std::endl;
        wypiszZadania(pHead->pZadania);
        pHead = pHead->pNext;
    }
}


void wypiszPracownikow (Pracownik * pHead)
{
    while (pHead)
    {
        std::cout << pHead->nazwisko << std::endl;
        pHead = pHead->pNext;
    }
}

void wypiszZadania (Zadanie * pRoot)
{
    if(pRoot){
        wypiszZadania(pRoot->pLewy);
        std::cout << pRoot->tresc_zadania << " priorytet: " << pRoot->priotytet << std::endl;
        wypiszZadania(pRoot->pPrawy);
    }
}

void usun (Pracownik * & pHead)
{
    if(pHead)
    {
        usunDrzewo(pHead->pZadania);
        Pracownik * pNastepnik = pHead->pNext;
        delete pHead;
        pHead = pNastepnik;
    }
}

void usunDrzewo (Zadanie * & pRoot)
{
    if (pRoot)
    {
        usunDrzewo(pRoot->pLewy);
        usunDrzewo(pRoot->pPrawy);
        delete pRoot;
        pRoot = nullptr;
    }
}
