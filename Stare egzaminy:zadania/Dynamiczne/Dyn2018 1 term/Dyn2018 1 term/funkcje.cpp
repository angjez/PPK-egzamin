#include <iostream>
#include <vector>
#include <algorithm>

#include "funkcje.hpp"

void dodajEgzaminatora (Egzaminator * & pEgz, std::string nazwisko)
{
    pEgz = new Egzaminator {nazwisko, pEgz};
}

void dodajStudentaRek (Student * & pGlowa, const std::string & nazwisko)
{
    if (not pGlowa)
        pGlowa = new Student {nazwisko, nullptr};
    else{
        if(pGlowa->nazwisko>nazwisko)
            pGlowa = new Student {nazwisko, pGlowa};
        else
            dodajStudentaRek(pGlowa->pNext, nazwisko);
    }
}

void wypiszStudentow(Student * pGlowa)
{
    while(pGlowa)
    {
        std::cout << pGlowa->nazwisko << std::endl;
        pGlowa = pGlowa->pNext;
    }
}

void wypiszEgzaminatorow(Egzaminator * pEgz)
{
    while(pEgz)
    {
        std::cout << pEgz->nazwisko << std::endl;
        pEgz = pEgz->pNext;
    }
}

void dodajStudentaEgzaminatorowi (Egzaminator * pHead, const std::string & nazwisko)
{
    znajdzNajmniejObciazonego(pHead)->pStudenci = new Student {nazwisko, znajdzNajmniejObciazonego(pHead)->pStudenci, 0.0};
}

void wypisz (Egzaminator * pEgz)
{
    Egzaminator * tmp = pEgz;
    while(tmp)
    {
//        std::cout << "egzaminator: " << tmp->nazwisko << std::endl;
        Student * tmp2 = tmp->pStudenci;
        while(tmp2)
        {
            std::cout <<  "student: " << tmp2->nazwisko << " ocena: " << tmp2->ocena <<std::endl;
            tmp2 = tmp2->pNext;
        }
        tmp = tmp->pNext;
    }
}

void usunEgzaminatorow (Egzaminator * & pEgz)
{
    while (pEgz)
    {
        Egzaminator * pNastepnik = pEgz->pNext;
        delete pEgz;
        pEgz = pNastepnik;
    }
}

void usunStudentow (Student * & pStudent)
{
    while (pStudent)
    {
        Student * pNastepnik = pStudent->pNext;
        delete pStudent;
        pStudent = pNastepnik;
    }
}

void usun (Egzaminator * pEgz)
{
    Student * tmp = pEgz->pStudenci;
    while(tmp)
    {
        usunStudentow(tmp);
        tmp = tmp->pNext;
    }
    usunEgzaminatorow(pEgz);
}

Egzaminator * znajdzEgzaminatora (Egzaminator * pHead, const std::string & nazwisko)
{
    Egzaminator * tmp = pHead;
    while(tmp)
    {
        if(tmp->nazwisko == nazwisko)
            return tmp;
        tmp = tmp->pNext;
    }
    return nullptr;
}

int policzStudentow (Egzaminator * pEgz)
{
    int i=0;
    Student * tmp = pEgz->pStudenci;
    while(tmp)
    {
        i++;
        tmp = tmp->pNext;
    }
    return i;
}

Egzaminator * znajdzNajmniejObciazonego (Egzaminator * pHead)
{
    std::vector <int> liczbaStudentow;
    Egzaminator * najmniejObciazony=nullptr;
    while(pHead)
    {
        liczbaStudentow.push_back(policzStudentow(pHead));
        if(*std::min_element(std::begin(liczbaStudentow), std::end(liczbaStudentow))==policzStudentow(pHead))
           najmniejObciazony=pHead;
        pHead = pHead->pNext;
    }
    return najmniejObciazony;
}
//
//Egzaminator * wynik = nullptr;
//int minLiczbaStudentow = 0;
//while(pHead)
//{
//    if (maxLiczbaStudentow > policzStudentow(pHead))
//        wynik = policzStudentow(pHead);
//}


Student * wytnijStudenta (Student * & pGlowa, const std::string & nazwisko)
{
//    tworzymy wskaźniki na aktualnego studenta i następnego studenta
    Student * tmp = pGlowa;
    Student * nast = nullptr;
    
//    doszliśmy do końca listy, studenta nie odnaleziono
    if (tmp == nullptr)
        return nullptr;

//    znaleźliśmy studenta do wycięcia
    if (tmp->nazwisko == nazwisko) {
//        zapamiętujemy adres studenta
        nast = tmp->pNext;
        delete tmp;
        return nast;
    }

//    nie znaleziono studenta, idziemy dalej przez listę
    tmp->pNext = wytnijStudenta(tmp->pNext, nazwisko);
//    nie trzeba zapamiętywać wskaźnika, bo funkcję wywołujemy z następnego (ten nie jest usuwany)
    return tmp;
}

void wpiszOcene (Student * & pPrzeegzaminowani, Egzaminator * pEgzaminatorzy, const std::string & egzaminator, const std::string & student, double ocena){
    
    Egzaminator * szukany = nullptr;
    Egzaminator * tmp = pEgzaminatorzy;
    while(tmp)
    {
        if(pEgzaminatorzy->nazwisko == egzaminator)
            szukany = pEgzaminatorzy;
        else
            tmp = tmp->pNext;
    }
    wytnijStudenta(pEgzaminatorzy->pStudenci, student);
    pEgzaminatorzy->pStudenci = new Student {student, pEgzaminatorzy->pStudenci, ocena};
}
