#ifndef fukncje_hpp
#define fukncje_hpp

#include <stdio.h>

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
void dodajNaPoczatek ( element * & pHead , const T & wartosc );

/** Funkcja wypisuje na standardowe wyjście wartości elementów cyklicznej listy jednokierunkowej .
    @param pHead wskaźnik na pierwszy element listy */
void wypisz ( element * pHead );

/** Funkcja zlicza liczbę elementów cyklicznej listy jednokierunkowej.
    @param pHead wskaźnik na pierwszy element listy
    @return zwraca liczbę elementów listy , dla listy pustej zwraca zero */
int zliczElementy ( element * pHead );

/** Funkcja usuwa element o podanej wartości. Jeżeli w liście jest kilka takich elementów usuwa którybądź .
    @param pHead wskaźnik na pierwszy element listy @param wartosc wartość elementu do usunięcia */
void usunElem ( element * & pHead , const T & wartosc );

/** Funkcja usuwa wszystkie elementy o podanej wartości.
    @param pHead wskaźnik na pierwszy element listy
    @param wartosc wartość elementu do usunięcia */
void usunWszystkie ( element * & pHead , const T & wartosc );

/** Funkcja usuwa element o podanym adresie.
    @param pHead wskaźnik na pierwszy element listy
    @param pDoUsuniecia adres elementu do usunięcia */
void usunElem ( element * & pHead , const element * pDoUsuniecia );

/** Funkcja usuwa wszystkie elementy z cyklicznej listy jednokierunkowej
 @param pHead wskaźnik na pierwszy element listy */
void usun ( element * & pHead );

/** Funkcja łączy dwie cykliczne listy jednokierunkowe. Po połączeniu list ostatni element pierwszej listy wskazuje na pierwszy element drugiej listy. Ostatni zaś element drugiej listy wskazuje na pierwszy element listy pierwszej .
 @param pH1 wskaźnik na pierwszy element listy pierwszej , po wykonaniu funkcji wskaźnik wskazuje na list ę wynikową
 @param pH2 wskaźnik na pierwszy element listy drugiej −− dołączanej do pierwszej , po wykonaniu funkcji : nullptr
 */
void polacz (element * & pH1, element * & pH2);

#endif /* fukncje_hpp */
