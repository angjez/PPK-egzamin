typedef int T;

/** element listy cyklicznej */
struct element
{
    /** wartość przechowywana w liście */
    T wartosc;
    /** wskaźnik na następny element listy */
    element * pNext;
};

/** Funkcja dodaje element od cyklicznej listy jednokierunkowej na początek listy (przed element wskazywany przed pHead), co jest równocześ− nie dodaniem na koniec listy (po ostatnim elemencie).
    @param pHead wskaźnik na pierwszy element listy
    @param wartosc wartość do dodania do listy */
void dodajNaPoczatek ( element * & pHead , const T & wartosc )
{
    if (pHead == nullptr){
        pHead = new element {wartosc, pHead};
        pHead->pNext = pHead;
    }
    
    else{
        element * ogon = pHead;
        while(ogon->pNext != pHead)
            ogon = ogon->pNext;
        element * nowy = new element {wartosc};
        nowy -> pNext = ogon -> pNext;
        ogon -> pNext = nowy;
    }
}


/** Funkcja wypisuje na standardowe wyjście wartości elementów cyklicznej listy jednokierunkowej .
    @param pHead wskaźnik na pierwszy element listy */
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

/** Funkcja zlicza liczbę elementów cyklicznej listy jednokierunkowej.
    @param pHead wskaźnik na pierwszy element listy
    @return zwraca liczbę elementów listy , dla listy pustej zwraca zero */
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

/** Funkcja usuwa element o podanej wartości. Jeżeli w liście jest kilka takich elementów usuwa którybądź .
    @param pHead wskaźnik na pierwszy element listy @param wartosc wartość elementu do usunięcia */
void usunElem ( element * & pHead , const T & wartosc )
{
    //lista pusta
    if (pHead == NULL)
        return;

    element *pCurr = pHead;
    while (pCurr->wartosc != wartosc)
    {
        //doszliśmy do końca listy, czyli nie znaleziono podanej wartosci
        if (pCurr->pNext == pHead)
            break;

        pCurr = pCurr -> pNext;
    }
    
    usunElem(pHead, pCurr);
    
}

/** Funkcja usuwa wszystkie elementy o podanej wartości.
    @param pHead wskaźnik na pierwszy element listy
    @param wartosc wartość elementu do usunięcia */
void usunWszystkie ( element * & pHead , const T & wartosc )
{
    //lista pusta
    if (pHead == NULL)
        return;
    
    element *pCurr = pHead;
    while (pCurr)
    {
        //doszliśmy do końca listy, czyli nie znaleziono podanej wartosci
        if (pCurr->pNext == pHead)
            break;
        
        if(pCurr->wartosc == wartosc)
            usunElem(pHead, pCurr);
        pCurr = pCurr -> pNext;
    }
}

/** Funkcja usuwa element o podanym adresie.
    @param pHead wskaźnik na pierwszy element listy
    @param pDoUsuniecia adres elementu do usunięcia */
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

/** Funkcja usuwa wszystkie elementy z cyklicznej listy jednokierunkowej
 @param pHead wskaźnik na pierwszy element listy */
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

/** Funkcja łączy dwie cykliczne listy jednokierunkowe. Po połączeniu list ostatni element pierwszej listy wskazuje na pierwszy element drugiej listy. Ostatni zaś element drugiej listy wskazuje na pierwszy element listy pierwszej .
 @param pH1 wskaźnik na pierwszy element listy pierwszej , po wykonaniu funkcji wskaźnik wskazuje na list ę wynikową
 @param pH2 wskaźnik na pierwszy element listy drugiej −− dołączanej do pierwszej , po wykonaniu funkcji : nullptr
 */
void polacz (element * & pH1, element * & pH2)
{
    element * tmp = pH2;
    while(tmp){
        dodajNaPoczatek(pH1, tmp->wartosc);
        tmp = tmp->pNext;
    }
    usun(pH2);
}
