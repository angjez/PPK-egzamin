#include "funkcje.hpp"

Cruise * findCruise (Cruise * pH, const std::string & start_harbour, const std::string & end_harbour, const std::string & date)
{
    Cruise * findCruise = nullptr;
    while(pH)
    {
        if(pH->date == date && pH->start_harbour == start_harbour && pH->end_harbour == end_harbour)
            return findCruise;
        else
            pH = pH->pNext;
    }
    return nullptr;
}

Cruise * addCruise (Cruise * & pHead, Cruise * & pTail, const std::string & date, const std::string start_harbour, const std::string & end_harbour)
{
    Cruise * pCurrent = pHead;
    if(pHead == nullptr)
    {
        pHead = new Cruise {start_harbour, end_harbour, date, nullptr, nullptr, pHead};
        pTail = pHead;
        return pHead;
    }
    else if (pHead->date >= date)
    {
        pHead = new Cruise {start_harbour, end_harbour, date, nullptr, nullptr, pHead};
        pHead->pNext->pPrev = pHead;
        return pHead;
    }
    else
    {
        while (pCurrent->pNext != nullptr && pCurrent->pNext->date < date)
            pCurrent = pCurrent->pNext;

        if(pCurrent->pNext == nullptr) {
            pTail = new Cruise {start_harbour, end_harbour, date, nullptr, pTail, nullptr};
            pTail->pPrev->pNext = pTail;
            return pTail;
        }
        
        Cruise * newCruise = new Cruise {start_harbour, end_harbour, date, nullptr, pCurrent, pCurrent->pNext};
        pCurrent->pNext = newCruise;
        newCruise->pNext->pPrev = newCruise;
        return newCruise;
    }
}

Passenger * addPassenger (Passenger * & pH, const std::string & name, const std::string & surname)
{
    if(pH == nullptr)
        pH = new Passenger {name, surname, nullptr};
        
    else if(pH->surname >= surname)
        pH = new Passenger {name, surname, pH};
    
    else
        addPassenger(pH->pNext, name, surname);
        
    return pH;
}

void addPassengerToCruise (Cruise * & pH, Cruise * & pT, const std::string & date, const std::string & start_harbour, const std::string & end_harbour, const std::string & name, const std::string & surname);

Cruise * favourite (Cruise * & pH);

//////////////////////////////////////////////////////////////////////////////////////////////////////

void showPassengers (Passenger * pHead)
{
    while(pHead) {
        std::cout << pHead->name << " " << pHead->surname << std::endl;
        pHead = pHead->pNext;
    }
}

void showCruises (Cruise * pHead)
{
    Cruise * pFirst = pHead;
    while(pHead) {
        if (pHead->pNext == pFirst)
            break;
        std::cout << pHead->start_harbour << " " << pHead->end_harbour << " " << pHead->date << std::endl;
        pHead = pHead->pNext;
    }
}

