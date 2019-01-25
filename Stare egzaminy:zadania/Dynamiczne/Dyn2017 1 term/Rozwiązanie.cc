// 1. (3 punkty) Proszę zdefiniować funkcję znajdzLubDodajPracownika, która odszukuje pracownika o podanym nazwisku. Jeżeli pracownik zostanie znaleziony, to funkcja zwraca adres pracownika. Jeżeli pracownika nie ma w liście, to funkcja dodaje go w odpowiednim miejscu i zwraca adres świeżo dodanego pracownika.

Pracownik * znajdzLubDodajPracownika(Pracownik * & pHead, Pracownik * & pTail, const std::string nazwisko)
{
    // alokujemy nowy wskaźnik
    Pracownik* newNode = (struct Pracownik*)malloc(sizeof(struct Pracownik));
    
    // przypisujemy nazwisko do wskaźnika, tworzymy pNext i pPrev dla niego
    newNode->nazwisko = nazwisko;
    newNode->pPrev = newNode->pNext = nullptr;
    
    //sprawdzenie, czy pracownik już wystąpił
    Pracownik * tmp = pHead;
    while(tmp){
        if(tmp->nazwisko == nazwisko)
            return tmp;
        else
            tmp = tmp->pNext;
    }
    
    //wskaźnik na obecnego pracownika
    Pracownik* current = pHead;
        
    // lista pusta = nowy wskaźnik jest głową
    if (pHead == nullptr){
        pHead = newNode;
        return newNode;
    }
        
    // nowy wskaźnik będzie dodany na początek listy
    else if (pHead->nazwisko >= newNode->nazwisko) {
        //wskaźnik na głowę listy to teraz "lewy" wskaźnik nowego elementu
        newNode->pNext = pHead;
        //tworzymy wskaźnik pPrev ze starego pierwszego elementu na nowy pierwszy element
        newNode->pNext->pPrev = newNode;
        //nowy wskaźnik to głowa
        pHead = newNode;
        return newNode;
    }
        
    else {
        //szukamy miejsca do umieszczenia elementu
        while (current->pNext != nullptr && current->pNext->nazwisko < newNode->nazwisko)
            current = current->pNext;
        
        //wskaźnik na następny element musi zostać przesunięty, bo teraz nowy element będzie wskazywał na następny
        newNode->pNext = current->pNext;
            
        //jeśli nowy element nie jest na końcu listy trzeba dostosować wskaźnik na poprzedni
        if (current->pNext != nullptr){
            //wskaźnik pPrev z następnego elementu wskazuje na nowy element
            newNode->pNext->pPrev = newNode;
            return newNode;
        }
        
        //obecny element wskazuje na nowy wskaźnikiem pNext
        current->pNext = newNode;
        //nowy element wskazuje na obecny wskaźnikiem pPrev
        newNode->pPrev = current;
        }
    return nullptr;
}

// 2. (1punkty) Proszę napisać funkcję dodajZadanie, która dodaje zadanie do drzewa zadań pracownika. Zadania ułożone są w drzewie według priorytetów zadań.

void dodajZadanie (Zadanie * pRoot, int priorytet, std::string tresc)
{
    if(not pRoot)
        pRoot = new Zadanie {priorytet, tresc, nullptr, nullptr};
    else{
        //zadanie mniejszego priorytetu = idź w lewo
        if (priorytet < pRoot->priotytet)
            dodajZadanie(pRoot->pLewy, priorytet, tresc);
        //zadanie większego priorytetu = idź w prawo
        else
            dodajZadanie(pRoot->pPrawy, priorytet, tresc);
    }
}

// 3. (1punkty) Proszę napisać funkcję dodajZadaniePracownikowi, która dodaje zadanie o podanej treści i priorytecie pracownikowi o podanym nazwisku. Jeżeli pracownika nie ma, zostanie on dodany w odpowiednim miejscu. Funkcja korzysta z funkcji zdefiniowanych w punktach 1-2.