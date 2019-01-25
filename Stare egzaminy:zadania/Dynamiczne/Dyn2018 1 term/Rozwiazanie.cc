// 1. (3 pkt) Proszę zdefiniować funkcję
// Egzaminator ∗ znajdzNajmniejObciazonego (Egzaminator ∗ pHead);
// która zwraca adres egzaminatora z najmniejszą liczbą przypisanych studentów. Jeżeli lista egzamina- torów jest pusta, funkcja zwraca nullptr (lub 0). Jeżeli kilku egzaminatorów ma tę samą minimalną liczbę studentów, funkcja zwraca adres któregokolwiek egzaminatora.

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


// 2. (1 pkt) Proszę zdefiniować rekurencyjną funkcję
// void dodajStudenta (Student ∗ & pGlowa, const string & nazwisko)
// która dodaje studenta o zadanym nazwisku do listy studentów o głowie pGlowa. Lista studentów jest posortowana wg nazwisk studentów. Po dodaniu kolejnego studenta lista nadal jest posortowana. Lista może być pusta.

void dodajStudentaRek (Student * & pGlowa, const std::string & nazwisko)
{
	//lista pusta
    if (not pGlowa)
        pGlowa = new Student {nazwisko, nullptr};
    else{
		 //sprawdzenie chronologiczności
        if(pGlowa->nazwisko>nazwisko)
            pGlowa = new Student {nazwisko, pGlowa};
        else
            dodajStudentaRek(pGlowa->pNext, nazwisko);
    }
}

// 3. (1 pkt) Proszę zdefiniować funkcję
// void dodajStudentaEgzaminatorowi (Egzaminator ∗ pHead, const string & nazwisko);
// która dodaje studenta o nazwisku nazwisko i ocenie 0.0 najmniej obciążonemu egzaminatorowi z listy egzaminatorów o głowie pHead. Jeżeli lista egzaminatorów jest pusta, funkcja nie robi nic. Funkcja wykorzystuje zdefiniowane wyżej funkcje.
//
void dodajStudentaEgzaminatorowi (Egzaminator * pHead, const std::string & nazwisko)
{
    znajdzNajmniejObciazonego(pHead)->pStudenci = new Student {nazwisko, znajdzNajmniejObciazonego(pHead)->pStudenci, 0.0};
}

// 4. (3 pkt) Proszę zdefiniować funkcję
// Student ∗ wytnijStudenta (Student ∗ & pGlowa, const string & nazwisko);
// która wycina (ale nie niszczy!) z listy studentów o głowie pGlowa studenta o zadanym nazwisku. Funkcja zwraca adres wyciętego studenta.

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

// 5. (2 pkt) Proszę zdefiniować funkcję
// void wpiszOcene (Student ∗ & pPrzeegzaminowani, Egzaminator ∗ pEgzaminatorzy, const string
// & egzaminator, const string & student, double ocena);
// która wykonuje następujące czynności (funkcja korzysta z wyżej zdefiniowanych funkcji):
// • wyszukuje egzaminatora o nazwisku egzaminator,
// • wycina studenta o nazwisku student z listy egzaminatora znalezionego w poprzednim punk-
// cie,
// • wpisuje wyciętemu studentowi ocenę i wreszcie
// • przenosi wyciętego studenta do listy o głowie pPrzeegzaminowani – nie jest istotnie miejsce wstawienia studenta.
// Jeżeli nie ma egzaminatora o podanym nazwisku lub nie ma studenta o podanym nazwisku, funkcja nie robi nic.
	
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