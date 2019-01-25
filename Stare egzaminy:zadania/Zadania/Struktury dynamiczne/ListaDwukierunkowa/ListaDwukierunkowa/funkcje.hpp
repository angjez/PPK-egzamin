#ifndef funkcje_hpp
#define funkcje_hpp

#include <stdio.h>

typedef int T;

//element listy dwukierunkowej
struct element
{
    /* wartość przechowywana w elemencie listy */
    T wartosc;
    /* wskaźnik na poprzedni element w liście */
    element * pPrev ;
    /* wskaźnik na następny element w liście */
    element * pNext ;
};

/** Funkcja wypisuje zawartość listy dwukierunkowej/
 @param pHead wskaźnik na pierwszy element listy dwukierunkowej
 @param pTail wskaźnik na ostatni element listy dwukierunkowej
 */
void wypiszListe (element * pHead, element * pTail);

/** Funkcja dodaje liczbę ma początek listy dwukierunkowej.
 @param pHead wskaźnik na pierwszy element listy dwukierunkowej
 @param pTail wskaźnik na ostatni element listy dwukierunkowej
 @param wartosc do dodania do listy
 */
void dodajNaPoczatek (element * & pHead, element * & pTail, const T & wartosc );

/** Funkcja dodaje liczbę ma koniec listy dwukierunkowej.
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param pTail wskaźnik na ostatni element listy dwukierunkowej
    @param wartosc do dodania do listy
 */
void dodajNaKoniec (element * & pHead, element * & pTail, const T & wartosc );

/** Funkcja sortuje listę ze względu na wartość przechowywaną w elemencie .
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param pTail wskaźnik na ostatni element listy dwukierunkowej
 */
void posortujListe (element * & pHead, element * & pTail) ;

/** Funkcja dodaje liczbę do listy posortowanej niemalejąco ze względu na przechowywane liczby. Po dodaniu lista jest nadal posortowana niemalejąco.
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param pTail wskaźnik na ostatni element listy dwukierunkowej
    @param wartosc liczba do dodania do listy
 */
void dodajDoListyPosortowanej ( element * & pHead, element * & pTail, const T & wartosc);

/** Funkcja przesuwa listę o jeden element w stronę ogona listy. Tzn. element ostatni listy jest przenoszony przed element pierwszy.
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param pTail wskaźnik na ostatni element listy dwukierunkowej
 */
void przesunListe (element * & pHead, element * & pTail);

/** Funkcja odwraca kolejność elementów listy dwukierunkowej.
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param pTail wskaźnik na ostatni element listy dwukierunkowej
 */
void odwrocListe (element * & pHead, element * & pTail);

/** Funkcja wyszukuje element o zadanej wartości w liście dwukierunkowej .
    @param pHead wskaźnik na pierwszy element listy dwukierunkowej
    @param wartosc liczba do wyszukania
    @return Funkcja zwraca adres elementu znalezionego. Jeżeli w liście jest
    kilka elementów o szukanej wartości , funkcja zwraca adres dowolnego
    z nich. Jeżeli element nie można znaleźć, fukcja zwraca nullptr. */
element * znajdz ( element * pHead, const T & wartosc );

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
element * przenies ( element * & pHeadWej, element * pTailWej, const T & wartosc, element * & pHeadWyj, element * & pTailWyj);

/** Funkcja usuwa wszystkie elementy o wskazanej wartości. @param pHead wskaźnik na pierwszy element listy dwukierunkowej @param pTail wskaźnik na ostatni element listy dwukierunkowej @param wartosc wartosc elementów do usunięcia
 */
void usunElementy (element * & pHead, element * & pTail , const T & wartosc );

/** Funkcja usuwa wszystkie elementy z listy dwukierunkowej. @param pHead wskaźnik na pierwszy element listy dwukierunkowej , po
 wykonaniu funkcji ma wartość nullptr
 @param pTail wskaźnik na ostatni element listy dwukierunkowej , po
 wykonaniu funkcji ma wartość nullptr */
void usunListe (element * & pHead, element * & pTail) ;

#endif /* funkcje_hpp */
