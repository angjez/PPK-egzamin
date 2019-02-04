struct Passenger
{
    std::string name, surname;
    Passenger * pNext;
};

struct Cruise
{
    std::string start_harbour, end_harbour;
    std::string date;
    Passenger * pPassengers;
    Cruise * pPrev , * pNext ;
};

/* The function searches for a cruise defined with a date, start harbour, and end harbour in a list of cruises pH. The function returns an address of the found cruise. If there is not matching cruise, the function returns NULL (or nullptr or 0). */
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

/* The function adds in a non descending order a new cruise to a list of cruises (head: pH, tail pT). The adding of a new cruise keeps the non descending order by date. The function returns an address of an added cruise. It is possible that the list is empty. The function adds a new cruise iteratively. */
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

/* The function adds a new passenger to a singly linked list of passengers (head pH). The function returns a head of a modified list. The function keeps the non descending order by surnames of passengers. An empty list is possible. The function adds passenger recursively. */
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

/* The function adds a passenger (name, surname given) to a doubly linked list of cruises (with head pH and tail pT). If a cruise is missing, it is added so that the ordering of the list is kept. It is possible that the list of cruised is empty. Cruises with no passengers are also possible. Function uses the functions defined above. */
void addPassengerToCruise (Cruise * & pH, Cruise * & pT, const std::string & date, const std::string & start_harbour, const std::string & end_harbour, const std::string & name, const std::string & surname)
{
    Cruise * tmp = pH;
    while(tmp) {
        if(tmp->start_harbour == start_harbour && tmp->end_harbour == end_harbour && tmp->date == date)
            break;
        tmp = tmp -> pNext;
    }
    if(tmp == nullptr)
        tmp = addCruise(pH, pT, date, start_harbour, end_harbour);
    
    addPassenger(tmp->pPassengers, name, surname);
    
}

/* The function returns an address of a cruise with the maximal length of passengers. Passed parameters: an address of the head of the list pH. If the list of cruises is empty, the function returns NULL (or nullptr or 0). If several cruises have the same lengths of passengers, the function returns an address of any of cruises with maximal length of passengers. */
Cruise * favourite (Cruise * & pHead)
{
    Cruise * favourite = pHead, * tmp = pHead;
    int passengers = 0, max = 0;
    while(tmp) {
        passengers = 0;
        while(tmp->pPassengers) {
            passengers++;
            tmp->pPassengers = tmp->pPassengers->pNext;
        }
        if(max < passengers) {
            max = passengers;
            favourite = tmp;
        }
        tmp = tmp->pNext;
    }
    return favourite;
}
