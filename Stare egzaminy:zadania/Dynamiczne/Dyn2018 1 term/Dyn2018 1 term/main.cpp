#include <iostream>
#include <vector>

#include "funkcje.hpp"

int main(int argc, const char * argv[])
{
    Egzaminator * pHead = nullptr;
    Student * pGlowa = nullptr;
    Student * pHeadP = nullptr;
    
    dodajEgzaminatora(pHead, "Dzikowska");
    dodajEgzaminatora(pHead, "Rysiewicz");
    dodajEgzaminatora(pHead, "Armacki");
    
    dodajStudentaRek(pGlowa, "Wolski");
    dodajStudentaRek(pGlowa, "August");
    dodajStudentaRek(pGlowa, "Jaworek");
    dodajStudentaRek(pGlowa, "Malecka");
    dodajStudentaRek(pGlowa, "Adamiak");
    wypiszStudentow(pGlowa);
    
    dodajStudentaEgzaminatorowi(pHead, "Wolski");
    dodajStudentaEgzaminatorowi(pHead, "Malecka");
    dodajStudentaEgzaminatorowi(pHead, "August");
    dodajStudentaEgzaminatorowi(pHead, "Jaworek");
    dodajStudentaEgzaminatorowi(pHead, "Adamiak");
    
    std::cout << wytnijStudenta(pGlowa, "August");
    wypiszStudentow(pGlowa);
    
    std::cout << "najmniej obciazonym egzaminatorem jest " << znajdzNajmniejObciazonego(pHead)->nazwisko << std::endl;
    
//    if(znajdzEgzaminatora(pHead, "Rysiewicz")!=nullptr){
//       std::cout << "liczba studentow egzaminatora o zadanym nazwisku to " << policzStudentow(znajdzEgzaminatora(pHead, "Rysiewicz")) << std::endl;
//    }
//    else
//       std::cout << "nie ma takiego egzaminatora";
    
    wpiszOcene(pHeadP, pHead, "Dzikowska", "Wolski", 5);
    wypisz(pHead);
//    wypiszEgzaminatorow(pHead);
//    usun(pHead);
    return 0;
}
