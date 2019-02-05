// 1. (3 punkty) Proszę zdefiniować funkcję znajdzLubDodajPracownika, która odszukuje pracownika o podanym nazwisku. Jeżeli pracownik zostanie znaleziony, to funkcja zwraca adres pracownika. Jeżeli pracownika nie ma w liście, to funkcja dodaje go w odpowiednim miejscu i zwraca adres świeżo dodanego pracownika.
Pracownik * znajdzLubDodajPracownika(Pracownik * & pHead, Pracownik * & pTail, const std::string & nazwisko)
{
	//wyszukanie czy pracownik już istnieje
    Pracownik * szukaj = pHead;
    while(szukaj) {
        if(szukaj->nazwisko == nazwisko)
            return szukaj;
        else
            szukaj = szukaj -> pNext;
    }
    
	 //lista pusta
    if(pHead == nullptr) {
        pHead = new Pracownik {nazwisko, nullptr, pHead};
        pTail = pHead;
        return pHead;
    }
    
	 //nazwisko do dodania na początek listy
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

// 2. (1punkty) Proszę napisać funkcję dodajZadanie, która dodaje zadanie do drzewa zadań pracownika. Zadania ułożone są w drzewie według priorytetów zadań.
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

// 3. (1punkty) Proszę napisać funkcję dodajZadaniePracownikowi, która dodaje zadanie o podanej treści i priorytecie pracownikowi o podanym nazwisku. Jeżeli pracownika nie ma, zostanie on dodany w odpowiednim miejscu. Funkcja korzysta z funkcji zdefiniowanych w punktach 1-2.
void dodajZadaniePracownikowi(Pracownik * & pHead, Pracownik * & pTail, const int & priorytet, const std::string & tresc, const std::string & nazwisko)
{
    dodajZadanie(znajdzLubDodajPracownika(pHead, pTail, nazwisko)->pZadania, priorytet, tresc);
}

// 4. (3 punkty) Proszę napisać funkcję usunPracownikowBezZadan, która usuwa wszystkich pracowni- ków, którzy nie mają żadnych zadań. Możliwe, że po usunięciu pracowników bez zadań lista pracowników będzie pusta.
void usunPracownikowBezZadan(Pracownik * & pHead, Pracownik * & pTail)
{
    Pracownik * tmp = pHead;
    while(tmp) {
        if (tmp->pZadania == nullptr) {
            if(tmp == pHead)
                pHead = tmp->pNext;
            else if (tmp->pNext != nullptr)
                tmp->pNext->pPrev = tmp->pPrev;
            else if(tmp->pPrev != nullptr)
                tmp->pPrev->pNext = tmp->pNext;
            delete tmp;
        }
        else
            tmp = tmp -> pNext;
    }
}

// 5. (2 punkty) Proszę napisać funkcję odwrocKolejnoscPracownikow, która odwraca kolejność pracow- ników, tzn. po jej wykonaniu pracownicy w liście są uporządkowani w odwrotnym porządku niż w liście wejściowej. Po wykonaniu funkcji każdy pracownik zachowuje swoje zadania niezmienione.
void odwrocKolejnoscPracownikow(Pracownik * & pHead, Pracownik * & pTail)
{
    for(Pracownik * tmp = pHead; tmp->pNext != nullptr; tmp = tmp->pNext)
    {
        for(Pracownik * tmp2 = tmp->pNext; tmp2 != nullptr; tmp2 = tmp2->pNext){
			 	 //zamieniamy drzewa zadań miejscami
            std::swap (tmp->pZadania, tmp2->pZadania);
				//zamieniamy nazwiska
            std::swap (tmp->nazwisko, tmp2->nazwisko);
        }
    }
}
