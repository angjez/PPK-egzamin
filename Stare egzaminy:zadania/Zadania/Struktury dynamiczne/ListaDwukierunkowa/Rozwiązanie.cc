/** Funkcja dodaje liczbę ma początek listy dwukierunkowej.
 @param pHead wskaźnik na pierwszy element listy dwukierunkowej
 @param pTail wskaźnik na ostatni element listy dwukierunkowej
 @param wartosc do dodania do listy
 */
void dodajNaPoczatek (element * & pHead, element * & pTail, const T & wartosc )
{
    pHead = new element {wartosc, nullptr, pHead};
    //jesli nowy ma nastepnika, ustaw wskaznik z tego elementu na nowy
    if(pHead->pNext)
        pHead->pNext->pPrev = pHead;
    //w innym przypadku nowy jest tez ogonem
    else
        pTail = pHead;
}

/** Funkcja dodaje liczbę ma koniec listy dwukierunkowej.
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param pTail wskaźnik na ostatni element listy dwukierunkowej
    @param wartosc do dodania do listy
 */
void dodajNaKoniec (element * & pHead, element * & pTail, const T & wartosc )
{
    pTail = new element {wartosc, pTail, nullptr};
    //jesli nowy ma nastepnika (poprzednika), ustaw wskaznik z tego poprzednika na nowy
    if(pTail->pPrev)
        pTail->pPrev->pNext = pTail;
    //w innym przypadku nowy jest tez glowa
    else
        pHead = pTail;
}

/** Funkcja sortuje listę ze względu na wartość przechowywaną w elemencie .
 @param pHead wskaźnik na pierwszy element listy dwukierunkowej
 @param pTail wskaźnik na ostatni element listy dwukierunkowej
 */
void posortujListe (element * & pHead, element * & pTail)
{
    for(element * tmp = pHead; tmp->pNext != nullptr; tmp = tmp->pNext)
    {
        for(element * tmp2 = tmp->pNext; tmp2 != nullptr; tmp2 = tmp2->pNext){
            if(tmp->wartosc >= tmp2->wartosc)
                std::swap (tmp->wartosc, tmp2->wartosc);
        }
    }
}

/** Funkcja dodaje liczbę do listy posortowanej niemalejąco ze względu na przechowywane liczby. Po dodaniu lista jest nadal posortowana niemalejąco.
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param pTail wskaźnik na ostatni element listy dwukierunkowej
    @param wartosc liczba do dodania do listy
 */
void dodajDoListyPosortowanej ( element * & pHead, element * & pTail, const T & wartosc)
{
    element * current = pHead;
    
    if (pHead == nullptr){
        pHead = new element {wartosc, pTail, pHead};
    }
    
    // nowy wskaźnik będzie dodany na początek listy
    else if (pHead->wartosc >= wartosc){
        dodajNaPoczatek(pHead, pTail, wartosc);
    }
    
    else {
        //szukamy miejsca do umieszczenia elementu
        while (current->pNext != nullptr && current->pNext->wartosc < wartosc)
            current = current->pNext;
        
        //element należy dodać na koniec- korzystamy z uprzednio zdefiniowanej funkcji
        if (current->pNext == nullptr){
            dodajNaKoniec(current, pTail, wartosc);
        }
        else{
            //poprzednikiem nowego elementu jest current, a następnikiem to, na co wskazywał current
            element * newElem = new element {wartosc, current, current->pNext};
            //poprzedni teraz wskazuje na nowy
            current->pNext = newElem;
            //następnik nowego wskazuje pPrevem na nowy (już nie na current)
            newElem->pNext->pPrev = newElem;
        }
    }
}

/** Funkcja przesuwa listę o jeden element w stronę ogona listy. Tzn. element ostatni listy jest przenoszony przed element pierwszy.
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param pTail wskaźnik na ostatni element listy dwukierunkowej
 */
void przesunListe (element * & pHead, element * & pTail) {
    
    element * current = pHead;
    
    if (current == nullptr)
        return;
    
    element * first = current;
    //current staje sie ostatnim elementem listy i bedzie pierwszym elementem nowej listy
    while (current->pNext != nullptr){
        current = current->pNext;
    }
    
    //pierwszy staje sie drugim i oddaje głowę
    current->pNext = first;
    pHead->pPrev = current;
    
    //current jest nową głową
    pHead = current->pPrev->pNext;
    //usuwamy wskaźnik z przedostatniego elementu na current i tworzymy ogon równy nullptr
    current->pPrev->pNext = nullptr;
    pHead->pPrev = nullptr;
    
}

/** Funkcja odwraca kolejność elementów listy dwukierunkowej.
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param pTail wskaźnik na ostatni element listy dwukierunkowej
 */
void odwrocListe (element * & pHead, element * & pTail)
{
    for(element * tmp = pHead; tmp->pNext != nullptr; tmp = tmp->pNext)
    {
        for(element * tmp2 = tmp->pNext; tmp2 != nullptr; tmp2 = tmp2->pNext){
            std::swap (tmp->wartosc, tmp2->wartosc);
        }
    }
}

/** Funkcja wyszukuje element o zadanej wartości w liście dwukierunkowej .
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param wartosc liczba do wyszukania
    @return Funkcja zwraca adres elementu znalezionego. Jeżeli w liście jest
    kilka elementów o szukanej wartości , funkcja zwraca adres dowolnego
    z nich. Jeżeli element nie można znaleźć, fukcja zwraca nullptr. */
element * znajdz ( element * pHead, const T & wartosc )
{
    element * tmp = pHead;
    while(tmp)
    {
        if(tmp->wartosc == wartosc)
            return tmp;
        else
            tmp = tmp->pNext;
    }
    return nullptr;
}

/**
 Funkcja wyszukuje wszystkie elementy o zadanej wartości w liście dwukierunkowej. Wyszukane elementy są przenoszone z listy wejściowej do wyjściowej listy dwukierunkowej. Po wykonaniu funkcji lista wyjś
 ciowa zawiera tylko elementu o zadanej wartości, podczas gdy lista wejściowa jest ich pozbawiona. Jeżeli nie ma elementów o zadanej wartości w liście wejściowej, lista wyjściowa pozostaje pusta.
@param pHeadWej wskaźnik na pierwszy element wejściowej listy dwukierunkowej
@param pTailWej wskaźnik na ostatni element wejściowej listy dwukierunkowej
@param wartosc liczba do wyszukania
@param pHeadWyj wskaźnik na pierwszy element wyjściowej listy
dwukierunkowej
@param pTailWyj wskaźnik na ostatni element wyjściowej listy
dwukierunkowej */
element * przenies ( element * & pHeadWej, element * pTailWej, const T & wartosc, element * & pHeadWyj, element * & pTailWyj)
{
    while(znajdz(pHeadWej, wartosc)!=nullptr){
        element * wyszukany = znajdz(pHeadWej, wartosc);
        dodajNaPoczatek(pHeadWyj, pTailWyj, wartosc);
        //element do usunięcia jest głową
        if(znajdz(pHeadWej, wartosc)==pHeadWej)
            pHeadWej = znajdz(pHeadWej, wartosc)->pNext;
        //element do usunięcia ma następnika
        if(znajdz(pHeadWej, wartosc)->pNext!=nullptr)
            znajdz(pHeadWej, wartosc)->pNext->pPrev=znajdz(pHeadWej, wartosc)->pPrev;
        //element do usunięcia ma poprzednika
        if(znajdz(pHeadWej, wartosc)->pPrev!=nullptr)
            znajdz(pHeadWej, wartosc)->pPrev->pNext=znajdz(pHeadWej, wartosc)->pNext;
        delete wyszukany;
    }
    return nullptr;
}

/** Funkcja usuwa wszystkie elementy o wskazanej wartości. @param pHead wskaźnik na pierwszy element listy dwukierunkowej @param pTail wskaźnik na ostatni element listy dwukierunkowej @param wartosc wartosc elementów do usunięcia
 */
void usunElementy (element * & pHead, element * & pTail , const T & wartosc )
{
    while(znajdz(pHead, wartosc)!=nullptr){
        //element do usunięcia jest głową
        if(znajdz(pHead, wartosc)==pHead)
            pHead = znajdz(pHead, wartosc)->pNext;
        //element do usunięcia ma następnika
        if(znajdz(pHead, wartosc)->pNext!=nullptr)
            znajdz(pHead, wartosc)->pNext->pPrev=znajdz(pHead, wartosc)->pPrev;
        //element do usunięcia ma poprzednika
        if(znajdz(pHead, wartosc)->pPrev!=nullptr)
            znajdz(pHead, wartosc)->pPrev->pNext=znajdz(pHead, wartosc)->pNext;
        delete znajdz(pHead, wartosc);
    }
}

/** Funkcja usuwa wszystkie elementy z listy dwukierunkowej. @param pHead wskaźnik na pierwszy element listy dwukierunkowej , po
 wykonaniu funkcji ma wartość nullptr
 @param pTail wskaźnik na ostatni element listy dwukierunkowej , po
 wykonaniu funkcji ma wartość nullptr */
void usunListe (element * & pHead, element * & pTail)
{
    while(pHead)
    {
        element * pNastepnik = pHead->pNext;
        delete pHead;
        pHead = pNastepnik;
    }
//    while(pTail)
//    {
//        element * pPoprzednik = pTail->pPrev;
//        delete pTail;
//        pTail = pPoprzednik;
//    }
}