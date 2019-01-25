#include <iostream>

#include "funkcje.hpp"

Pracownik * znajdzLubDodajPracownika(Pracownik * & pHead, const std::string & nazwisko)
{
    //sprawdzenie, czy pracownik już wystąpił
    Pracownik * tmp = pHead;
    while(tmp){
        if(tmp->nazwisko == nazwisko){
            return tmp;
        }
        else
            tmp = tmp->pNext;
    }
    
    //wskaźnik na obecnego pracownika
    Pracownik* current = pHead;
    
    // alokujemy nowy wskaźnik
    Pracownik* newNode = (struct Pracownik*)malloc(sizeof(struct Pracownik));
    
    // przypisujemy nazwisko do wskaźnika, tworzymy pNext i pPrev dla niego
    newNode->nazwisko = nazwisko;
    newNode->pPrev = newNode->pNext = nullptr;
        
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

void dodajZadanie (Zadanie * pRoot, const int & priorytet, const std::string & tresc)
{
    if (not pRoot) // drzewo puste
        pRoot = new Zadanie { priorytet, tresc, nullptr, nullptr };
    else  // w drzewie juz co jest
    {
        if (priorytet < pRoot->priotytet) // idziemy w lewo
            dodajZadanie(pRoot->pLewy, priorytet, tresc);
        else // idziemy w prawo
            dodajZadanie(pRoot->pPrawy, priorytet, tresc);
    }
}

void dodajZadaniePracownikowi(Pracownik * pHead, const int & priorytet, const std::string & tresc, const std::string & nazwisko)
{
    dodajZadanie(znajdzLubDodajPracownika(pHead, nazwisko)->pZadania, priorytet, tresc);
}

void usunPracownikowBezZadan()
{
    
}

void odwrocKolejnoscPracownikow()
{
    
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
