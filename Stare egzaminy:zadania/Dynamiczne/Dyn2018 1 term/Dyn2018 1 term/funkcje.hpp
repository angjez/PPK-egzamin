#ifndef funkcje_hpp
#define funkcje_hpp

#include <stdio.h>
#include <string>
#include <vector>

struct Student
{   std::string nazwisko;
    Student * pNext;
    double ocena ;
};

struct Egzaminator
{
    std::string nazwisko;
    Egzaminator * pNext;
    Student * pStudenci;
};

void dodajEgzaminatora (Egzaminator * & pEgz, std::string nazwisko);
void wypiszEgzaminatorow(Egzaminator * pEgz);
void usunEgzaminatorow (Egzaminator * & pEgz);

void dodajStudentaEgzaminatorowi (Egzaminator * pHead, const std::string & nazwisko);
void dodajStudentaRek (Student * & pGlowa, const std::string & nazwisko);
void wypiszStudentow(Student * pGlowa);

Egzaminator * znajdzEgzaminatora (Egzaminator * pHead, const std::string & nazwisko);
int policzStudentow (Egzaminator * pEgz);

void wypisz (Egzaminator * pEgz);
void usun (Egzaminator * pEgz);

Egzaminator * znajdzNajmniejObciazonego (Egzaminator * pHead);

Student * wytnijStudenta (Student * & pGlowa, const std::string & nazwisko);

void wpiszOcene (Student * & pPrzeegzaminowani, Egzaminator * pEgzaminatorzy, const std::string & egzaminator, const std::string & student, double ocena);

#endif /* funkcje_hpp */
